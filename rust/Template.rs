use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| x.parse::<i64>().unwrap());
    let mut t = it.next().unwrap();
    while t > 0 {
        solve();
        t -= 1;
    }
}

fn solve() {

}
