use std::io::{self, Read};
fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace().map(|x| x.parse::<i32>().unwrap());
    let n = it.next().unwrap();
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(it.next().unwrap());
    }
    v.sort();
    for i in v {
        print!("{} ", i);
    }
}
