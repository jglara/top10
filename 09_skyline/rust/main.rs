use itertools::Itertools;

fn skyline(nums: Vec<i32>) -> Vec<i32> {

    nums.iter().scan(0, |acum, &x| {
        *acum = std::cmp::max(*acum, x);
        Some(*acum)
    }).dedup().collect::<Vec<_>>()
}

fn main() {
    println!("{:?}", skyline(vec![5, 5, 2, 10, 3, 15, 10]));
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(skyline(vec![5, 5, 2, 10, 3, 15, 10]), vec![5, 10, 15]);
    }
}
