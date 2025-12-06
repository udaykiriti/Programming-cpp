use std::collections::HashSet;
use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut set: HashSet<i32> = HashSet::with_capacity(2048);

        for _ in 0..n {
            let x: i32 = it.next().unwrap().parse().unwrap();
            set.insert(x);
        }

        loop {
            let c = set.len() as i32;
            if set.contains(&c) {
                println!("{}", c);
                break;
            }
            set.insert(c);
        }
    }
}
