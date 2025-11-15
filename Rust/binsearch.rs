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
    let x = it.next().unwrap();
    v.sort();
    let mut l = 0;
    let mut r = n - 1;
    let mut f = false;
    while l <= r {
        let m = (l + r) / 2;
        if v[m as usize] == x {
            f = true;
            break;
        } else if v[m as usize] < x {
            l = m + 1;
        } else {
            if m == 0 { break; }
            r = m - 1;
        }
    }
    if f { println!("YES"); } else { println!("NO"); }
}
