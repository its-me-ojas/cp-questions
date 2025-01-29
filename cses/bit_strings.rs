use std::{collections::HashSet, io};
fn mod_exp(base: u64, exp: u64, modulos: u64) -> u64 {
    let mut result = 1;
    let mut base = base % modulos;
    let mut exp = exp;

    while exp > 0 {
        if exp % 2 == 1 {
            result = (result * base) % modulos;
        }
        base = (base * base) % modulos;
        exp /= 2;
    }
    result
}
fn main() {
    let mut n = String::new();
    io::stdin().read_line(&mut n).unwrap();
    let n: u64 = n.trim().parse().unwrap();
    let modulos: u64 = 1_000_000_007;
    let result = mod_exp(2, n, modulos);
    println!("{result}");
}
