use std::{collections::HashSet, io};

fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n = n.trim().parse::<u64>().unwrap();

    let mut count = 0;
    let mut i = 5;
    while n / i > 0 {
        count += n / i;
        i *= 5;
    }
    println!("{count}");
}
