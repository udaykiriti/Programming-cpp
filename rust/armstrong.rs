use std::io::{self, Read};
fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let s = s.trim();
    let n: i32 = s.parse().unwrap();
    let len = s.len() as u32;
    let mut sum = 0;
    let mut t = n;
    while t > 0 {
        let d = t % 10;
        sum += d.pow(len);
        t /= 10;
    }
    if sum == n {
        println!("YES");
    } else {
        println!("NO");
    }
}
