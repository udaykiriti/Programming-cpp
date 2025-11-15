use std::io::{self, Read};
fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let n: i32 = s.trim().parse().unwrap();

    println!("for loop:");
    for i in 1..=n {
        print!("{} ", i);
    }
    println!();

    println!("while loop:");
    let mut i = 1;
    while i <= n {
        print!("{} ", i);
        i += 1;
    }
    println!();

    println!("loop loop:");
    let mut j = 1;
    loop {
        if j > n { break; }
        print!("{} ", j);
        j += 1;
    }
    println!();
}
