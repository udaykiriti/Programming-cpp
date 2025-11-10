use std::io::{self, Read};
fn perm(v: &mut Vec<i32>, l: usize, r: usize) {
    if l == r {
        for x in v.iter() {
            print!("{} ", x);
        }
        println!();
        return;
    }
    for i in l..=r {
        v.swap(l, i);
        perm(v, l + 1, r);
        v.swap(l, i);
    }
}
fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| x.parse::<i32>().unwrap());
    let n = it.next().unwrap();
    let mut v = Vec::new();
    for _ in 0..n {
        v.push(it.next().unwrap());
    }
    perm(&mut v, 0, n as usize - 1);
}
