fn ocean(nums: Vec<i32>) -> Vec<usize> {
    let mut h = nums
        .iter()
        .rev()
        .scan(0, |acum, &x| {
            *acum = std::cmp::max(*acum, x);
            Some(*acum)
        })
        .collect::<Vec<_>>();

    h.reverse();
    h.push(0);

    nums.iter()
        .enumerate()
        .zip(h[1..].iter())
        .filter_map(|((i, &x), &y)| if x > y { Some(i) } else { None })
        .collect::<Vec<_>>()
}

fn main() {
    println!("{:?}", ocean(vec![4, 2, 3, 1]));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(ocean(vec![4, 2, 3, 1]), vec![0, 2, 3]);
        assert_eq!(ocean(vec![4, 3, 2, 1]), vec![0, 1, 2, 3]);
        assert_eq!(ocean(vec![1, 3, 2, 4]), vec![3]);
        assert_eq!(ocean(vec![2, 2, 2, 2]), vec![3]);
    }
}
