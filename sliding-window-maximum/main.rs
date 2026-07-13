use std::collections::VecDeque;
// https://leetcode.cn/problems/sliding-window-maximum
impl Solution {
    pub fn max_sliding_window(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let mut ret = Vec::new();
        let mut w = VecDeque::new();
        for i in 0..nums.len() {
            while let Some(&front) = w.front() {
                if (front + k as usize) <= i {
                    w.pop_front();
                } else {
                    break;
                }
            }
            while let Some(&back) = w.back() {
                if nums[back] < nums[i] {
                    w.pop_back();
                } else {
                    break;
                }
            }
            w.push_back(i);
            if i >= (k - 1) as usize {
                ret.push(nums[*w.front().unwrap()]);
            }
        }
        ret
    }
}

struct Solution {}
fn main() {
    assert_eq!(
        Solution::max_sliding_window(vec![1, 3, -1, -3, 5, 3, 6, 7], 3),
        vec![3, 3, 5, 5, 6, 7]
    );
    println!("All tests passed");
}
