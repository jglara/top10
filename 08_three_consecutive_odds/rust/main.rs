

fn three_consecutive_odds(arr: Vec<i32>) -> bool {
    arr.iter().map(|x| x % 2).scan(0, |acum, x| {
        *acum += 1;
        *acum *= x;
        Some(*acum)
    }).any(|x| x == 3)
}

fn main() {
    println!("{:?}", three_consecutive_odds(vec![1, 2, 1, 1]));
    println!("{:?}", three_consecutive_odds(vec![2, 6, 4, 1]));
    println!("{:?}", three_consecutive_odds(vec![1,2,34,3,4,5,7,23,12]));
}
