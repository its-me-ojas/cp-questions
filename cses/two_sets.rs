use std::{collections::HashSet, io};
fn main() {
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
