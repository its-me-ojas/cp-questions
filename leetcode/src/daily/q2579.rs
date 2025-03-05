pub struct Solution;

impl Solution {
    pub fn colored_cells(n: i32) -> i64 {
        if n == 1 {
            return 1;
        }
        // formula: 2n(n-1) + 1
        let n: i64 = n as i64;
        2 * n * (n - 1) + 1
    }
}
