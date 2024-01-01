// Explanation
// Sort the children and cookies in ascending order.
// For each cookie, check if it can satisfy the greed of the child.
// If it can, increment the count and move to the next child.
// Use count as the index of the greed vector.
// If the cookie is not large enough, move to the next cookie.
// if there are no more cookies, break out of the loop.

use std::convert::TryInto;
impl Solution {
    pub fn find_content_children(mut g: Vec<i32>, mut s: Vec<i32>) -> i32 {
        g.sort_unstable();
        s.sort_unstable();
        let mut count = 0;

        for cookie in &s {
            if let Some(greed) = g.get(count) {
                if cookie >= greed {
                    count += 1;
                }
            } else {
                break; // No more children to satisfy
            }
        }

        count.try_into().unwrap()
    }
}
