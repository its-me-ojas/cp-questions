use std::{
    collections::{HashMap, HashSet},
    io,
    thread::current,
};

pub fn weird_algorithm() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let mut n: u64 = input.trim().parse().unwrap();
    print!("{n} ");
    while n != 1 {
        if n % 2 == 0 {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
        print!("{n} ");
    }
}

pub fn missing_number() {
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let n: u64 = input.trim().parse().unwrap();
    let mut input = String::new();
    io::stdin().read_line(&mut input).unwrap();
    let set: HashSet<u64> = input
        .trim()
        .split_whitespace()
        .map(|x| x.parse().unwrap())
        .collect();
    for i in 1..=n {
        if !set.contains(&i) {
            print!("{i}");
            break;
        }
    }
}

pub fn repetitions() {
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
