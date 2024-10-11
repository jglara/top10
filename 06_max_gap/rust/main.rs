use itertools::*;

fn max_gap(xs: Vec<i32>) -> i32 {
    xs.iter()
        .sorted()
        .tuple_windows()
        .map(|(x, y)| y - x)
        .max()
        .unwrap_or_default()
}

fn max_gap_2(mut xs: Vec<i32>) -> i32 {
    xs.sort();

        xs
        .iter()
        .zip(xs[1..].iter())
        .map(|(x, y)| y - x)
        .max()
        .unwrap_or_default()
}


fn main() {
    println!("{:?}", max_gap(vec![3,6,9,1]));
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(max_gap(vec![3,6,9,1]),3)
    }

    #[test]
    fn test_2() {
        assert_eq!(max_gap(vec![10]),0)
    }
}
