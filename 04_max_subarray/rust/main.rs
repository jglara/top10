fn max_sub_array(nums: Vec<i32>) -> i32 {
    nums.iter()
        .scan(0, |acum, &x| {
            if x > *acum + x {
                *acum = x;
            } else {
                *acum +=x;
            }
            Some(*acum)
        })
        .max()
        .unwrap_or_default()
}

fn main() {
    println!("{:?}", max_sub_array(vec![-2, 1, -3, 4, -1, 2, 1, -5, 4]));
    println!("{:?}", max_sub_array(vec![1]));
    println!("{:?}", max_sub_array(vec![5,4,-1,7,8]));
}
