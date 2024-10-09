use itertools::*;

fn sushi(n: Vec<i32>) -> usize {
    n.iter()
        .chunk_by(|&e| 2 - e)
        .into_iter()
        .map(|(_k, v)| v.count())
        .tuple_windows()
        .map(|(x,y)| std::cmp::min(x,y))
        .max().unwrap_or_default()
    
}

fn main() {
    println!("{:?}", sushi(vec![2, 2, 2, 1, 1, 2, 2]));
    println!("{:?}", sushi(vec![1, 2, 1, 2, 1, 2]));
    println!("{:?}", sushi(vec![2, 2, 1, 1, 1, 2, 2, 2, 2]));

}
