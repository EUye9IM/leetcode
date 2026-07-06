// https://leetcode.cn/problems/3sum
use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn three_sum(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut num_set = HashMap::new();
        let mut ret = HashSet::<Vec<i32>>::new();
        for (i, &ni) in nums.iter().enumerate() {
            let n = num_set.get(&ni).unwrap_or(&(0, 0)).1 + 1;
            num_set.insert(ni, (i, n));
        }
        for i in 0..nums.len() {
            for j in i + 1..nums.len() {
                let n1 = nums[i].to_owned();
                let n2 = nums[j].to_owned();
                let n3 = -n1 - n2;
                let v = num_set.get(&n3).unwrap_or(&(0, 0)).to_owned();
                let mut n = v.1;
                if v.0 <= j {
                    continue;
                }
                if n1 == n3 {
                    n = n - 1;
                }
                if n2 == n3 {
                    n = n - 1;
                }
                let mut a = vec![n1, n2, n3];
                a.sort();
                if n > 0 {
                    ret.insert(a);
                }
            }
        }
        ret.into_iter().collect()
    }
}

struct Solution {}
fn main() {
    assert_eq!(Solution::three_sum(vec![1, 2, 3]), Vec::<Vec<i32>>::new());
    assert_eq!(Solution::three_sum(vec![-1, 0, 1]), vec![vec![-1, 0, 1]]);
    assert_eq!(Solution::three_sum(vec![-1, 0, 0, 1]), vec![vec![-1, 0, 1]]);
    println!("All tests passed");
}
