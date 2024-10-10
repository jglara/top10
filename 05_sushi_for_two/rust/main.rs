use itertools::*;

fn sushi(n: Vec<i32>) -> usize {
    2 * n
        .iter()
        .chunk_by(|&e| 2 - e)
        .into_iter()
        .map(|(_k, v)| v.count())
        .tuple_windows()
        .map(|(x, y)| std::cmp::min(x, y))
        .max()
        .unwrap_or_default()
}

fn main() -> anyhow::Result<()> {
    std::io::stdin()
        .lines()
        .skip(1)
        .filter_map_ok(|l| {
            let nums = l
                .split_whitespace()
                .filter_map(|w| w.parse::<i32>().ok())
                .collect::<Vec<_>>();

            Some(sushi(nums))
        })
        .for_each(|x| x.iter().for_each(|x| println!("{x}")));

    Ok(())
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(sushi(vec![2, 2, 2, 1, 1, 2, 2]), 4);
    }

    #[test]
    fn test_2() {
        assert_eq!(sushi(vec![1, 2, 1, 2, 1, 2]), 2);
    }

    #[test]
    fn test_3() {
        assert_eq!(sushi(vec![2, 2, 1, 1, 1, 2, 2, 2, 2]), 6);
    }
}
