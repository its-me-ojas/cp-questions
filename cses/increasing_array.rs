use std::{collections::HashSet, io};
fn main() {
    let mut size = String::new();
    io::stdin().read_line(&mut size).unwrap();
    let size: usize = size.trim().parse().unwrap();
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut numbers: Vec<u64> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();

    let mut moves = 0;
    for i in 1..size {
        if numbers[i] < numbers[i - 1] {
            moves += numbers[i - 1] - numbers[i];
            numbers[i] = numbers[i - 1];
        }
    }
    println!("{moves}");
}
