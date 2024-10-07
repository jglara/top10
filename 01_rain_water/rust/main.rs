use std::cmp::max;

use anyhow::Result;

fn trap(height: Vec<i32>) -> i32 {
    let rev_heigh_acum = height.iter().rev().scan(0, |a, &h| {
        *a = max(*a,h);
        Some(*a)
    }).collect::<Vec<_>>();

    height
        .iter()
        .scan(0, |a, &h| {
            *a = max(*a,h);
            Some(*a)
        })
        .zip(rev_heigh_acum.iter().rev())
        .map(|(x, &y)| std::cmp::min(x, y))
        .zip(height.iter())
        .map(|(x, &y)| x - y)
        .sum()
}

fn main() -> Result<()> {
    println!("{:?}", trap(vec![0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]));
    println!("{:?}", trap(vec![4,2,0,3,2,5]));
    Ok(())
}

#[cfg(test)]
mod tests {

    #[test]
    fn test_1() {
        let h = vec![0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1];

        println!("{:?}", h.iter().rev().scan(0, |a, &h| {
            *a = std::cmp::max(*a,h);
            Some(*a)
        }).collect::<Vec<_>>());
    }

}