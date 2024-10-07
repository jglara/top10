use anyhow::Result;

fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
    nums.iter().scan(0, |acum, &x| {
        if x == 0 {
            let ret = *acum;
            *acum=0;
            Some(ret)
        } else {
            *acum+=x;
            Some(*acum)
        }
        
    }).max().unwrap_or_default()
}
fn main() -> Result<()> {
    println!("{:?}", find_max_consecutive_ones(vec![1, 1, 0, 1, 1, 1]));
    Ok(())
}
