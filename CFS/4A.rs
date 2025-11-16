use std::io::*;

fn main(){
    /* use std::io::{stdin , stdout , Write};
    let mut s = String::new(); */
    let stdin = stdin();
    let mut reader = stdin.lock();

    let mut s = String::new();
    reader.read_line(&mut s).unwrap();

    let w : i64 = s.trim().parse().unwrap();

    if w % 2 == 0 && w > 2 {
        println!("YES");
    } else {
        println!("NO");
    }
}