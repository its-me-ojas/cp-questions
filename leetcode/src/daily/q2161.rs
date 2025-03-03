pub struct Solution;

// impl Solution {
//     pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
//         let mut less = nums
//             .iter()
//             .filter(|&&x| x < pivot)
//             .copied()
//             .collect::<Vec<i32>>();
//         let mut equal = nums
//             .iter()
//             .filter(|&&x| x == pivot)
//             .copied()
//             .collect::<Vec<i32>>();
//         let mut great = nums
//             .iter()
//             .filter(|&&x| x > pivot)
//             .copied()
//             .collect::<Vec<i32>>();
//         [less, equal, great].concat()
//     }
// }

impl Solution {
    pub fn pivot_array(nums: Vec<i32>, pivot: i32) -> Vec<i32> {
        let (mut less, mut more) = (vec![], vec![]);
        let mut pivot_count = 0;
        for &n in nums.iter() {
            if n == pivot {
                pivot_count += 1;
            } else if n < pivot {
                less.push(n);
            } else {
                more.push(n);
            }
        }
        let mut result: Vec<i32> = Vec::with_capacity(nums.len());
        result.extend(&less);
        for _ in 0..pivot_count {
            result.push(pivot);
        }
        result.extend(&more);
        result
    }
}
