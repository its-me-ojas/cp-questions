use std::{collections::HashSet, io};

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

pub fn increasing_array() {
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

pub fn permutations() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();
}

pub fn number_spiral() {}

pub fn two_knights() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: usize = n.trim().parse().unwrap();
    for i in 1..=n {
        if i == 1 {
            print!("0\n");
        } else {
            print!("{:}\n", (i * i) * (i * i - 1) / 2 - 4 * (i - 1) * (i - 2));
        }
    }
}

pub fn two_sets() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: u64 = n.trim().parse().unwrap();
    let sum = n * (n + 1) / 2;
    if sum % 2 != 0 {
        print!("NO");
        return;
    }
    print!("YES\n");
    let mut set1 = HashSet::new();
    let mut set2 = HashSet::new();
    let mut sum1 = 0;
    let mut sum2 = 0;
    for i in (1..=n).rev() {
        if sum1 < sum2 {
            set1.insert(i);
            sum1 += i;
        } else {
            set2.insert(i);
            sum2 += i;
        }
    }
    print!("{}\n", set1.len());
    for i in set1 {
        print!("{i} ");
    }
    print!("\n");
    print!("{}\n", set2.len());
    for i in set2 {
        print!("{i} ");
    }
}
