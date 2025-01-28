use std::{collections::HashSet, io};
fn main() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let input = input.trim();

    if input.is_empty() {
        print!("0");
        return;
    }

    let chars: Vec<char> = input.chars().collect();
    let mut max_count = 0;
    let mut current_count = 1;

    for i in 1..chars.len() {
        if chars[i] == chars[i - 1] {
            current_count += 1;
        } else {
            if current_count > max_count {
                max_count = current_count;
            }
            current_count = 1;
        }
    }

    if current_count > max_count {
        max_count = current_count;
    }

    println!("{max_count}");
}
