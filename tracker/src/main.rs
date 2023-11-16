use std::env;
use std::fs::File;
use std::io::Read;
use std::process;

use rusqlite::{Connection, Error};
use scraper::{Html, Selector};

const INFILE: &str = "table.html";

fn read_table(file_name: &str) -> Result<String, std::io::Error> {
    let mut file = File::open(file_name)?;
    let mut buffer = String::new();
    file.read_to_string(&mut buffer)?;
    Ok(buffer)
}

fn to_iso_date(date: &str) -> String {
    date.split("/")
        .collect::<Vec<&str>>()
        .iter()
        .rev()
        .fold(String::new(), |acc, &x| acc + x + "-")
        .trim_matches('-')
        .to_string()
}

fn process_lines(input: &str) -> Vec<String> {
    input
        .trim()
        .lines()
        .map(|line| line.trim())
        .filter(|line| !line.is_empty())
        .map(|data| data.to_string())
        .collect()
}

fn insert_data(data: &Vec<Vec<String>>) -> Result<(), Error> {
    let conn = Connection::open("log.db")?;

    conn.execute(
        "CREATE TABLE IF NOT EXISTS log(
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            date TEXT,
            link TEXT,
            problem TEXT,
            language TEXT
)",
        [],
    )?;

    let mut insert_statement =
        conn.prepare("INSERT INTO log (date, link, problem, language) VALUES (?,?,?,?)")?;

    for row in data {
        insert_statement.execute([
            row[0].clone(),
            row[1].clone(),
            row[2].clone(),
            row[3].clone(),
        ])?;
    }

    println!("Finsihed writing to database");

    Ok(())
}

fn import() -> Result<(), Error> {
    let table = match read_table(INFILE) {
        Ok(content) => content,
        Err(e) => {
            println!("Error reading table : {}", e);
            process::exit(2);
        }
    };

    let fragment = Html::parse_fragment(&table);
    let mut data: Vec<Vec<String>> = Vec::new();

    for table in fragment.select(&Selector::parse("table").unwrap()) {
        for row in table.select(&Selector::parse("tr").unwrap()).skip(1) {
            let cols = row
                .select(&Selector::parse("td").unwrap())
                .collect::<Vec<_>>();
            let date = to_iso_date(&cols[0].text().collect::<String>());
            let lang = to_iso_date(&cols[3].text().collect::<String>());
            let links: Vec<String> = process_lines(&cols[1].text().collect::<String>());
            let problems: Vec<String> = process_lines(&cols[2].text().collect::<String>());
            for i in 0..links.len() {
                data.push(vec![
                    date.clone(),
                    links[i].clone(),
                    problems[i].clone(),
                    lang.clone(),
                ]);
            }
        }

        println!("Finished reading data");
    }

    insert_data(&data)
}

fn get_input(item: &str) -> String {
    let mut input = String::new();
    println!("Enter {} : ", item);
    std::io::stdin()
        .read_line(&mut input)
        .expect("Failed to read line");
    input.to_string()
}

fn update() -> Result<(), Error> {
    let (date, id, name, language) = (
        get_input("date"),
        get_input("id"),
        get_input("Name"),
        get_input("language"),
    );

    let conn = Connection::open("log.db")?;
    conn.execute(
        "INSERT INTO log (date, link, problem, language) VALUES (?,?,?,?)",
        [date, id, name, language],
    )?;

    Ok(())
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() != 2 {
        println!("Usage: tracker <function>");
        process::exit(1);
    }

    let arg = &args[1];

    match arg.as_str() {
        "import" => {
            import().expect("Error importing html file");
        }
        "update" => {
            update().expect("Error adding entry to file");
        }
        "export" => {
            export_html.expect("Error exporting database");
            format().expect("Error formatting html");
            export_md.expect("Error exporting to markdown");
        }
    }

    println!("Hello, world!");
}
