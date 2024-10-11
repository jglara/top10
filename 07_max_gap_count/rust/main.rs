use itertools::*;

fn max_gap_count(xs: Vec<i32>) -> usize {
    let  diffs = xs.iter()
        .sorted()
        .tuple_windows()
        .map(|(x, y)| y - x).collect::<Vec<_>>();

    let max_val = diffs.iter().max().unwrap_or(&0);

    diffs.iter().filter(|&x| x == max_val).count()
        
}



fn main() {
    println!("{:?}", max_gap_count(vec![1,2,5,8]));
}

#[cfg(test)]
mod test {
    use super::*;

    #[test]
    fn test_1() {
        assert_eq!(max_gap_count(vec![1,2,5,8]),2)
    }

    
}