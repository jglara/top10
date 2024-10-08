
fn find_length_of_lcis(nums: Vec<i32>) -> i32 {
 nums.iter().zip(
    nums[1..].iter()).
    map(|(x,y)| if y>x {1} else {0}).
    scan(0,|acum,x| if x==0 {
        *acum=0;
        Some(0)
    } else {
        *acum += 1;
        Some (*acum)
    }).max().unwrap_or_default()+1
 
}

fn main() {
    println!("{:?}", find_length_of_lcis(vec![1,3,5,4,7]));
    println!("{:?}", find_length_of_lcis(vec![2,2,2,2,2]));
}