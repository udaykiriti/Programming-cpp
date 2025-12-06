use std::io::{self, Read};
use std::fmt::Write;

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let l: usize = it.next().unwrap().parse().unwrap();
        let r: usize = it.next().unwrap().parse().unwrap();

        let mut px = vec![0i64; n + 1];
        for i in 1..=n {
            px[i] = i as i64;
        }
        px[r] = px[l - 1];

        for i in 1..=n {
            let ai = px[i] ^ px[i - 1];
            if i == n {
                write!(out, "{}\n", ai).unwrap();
            } else {
                write!(out, "{} ", ai).unwrap();
            }
        }
    }

    print!("{}", out);
}
