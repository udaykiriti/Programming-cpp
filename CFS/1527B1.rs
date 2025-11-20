use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    
    for _ in 0..t {
        let _n: usize = it.next().unwrap().parse().unwrap();

        let s: &str = it.next().unwrap();

        let zeros = s.chars().filter(|&ch| ch == '0').count();




        if zeros % 2 == 0 || zeros == 1 {
            println!("BOB");
        } else {
            println!("ALICE");
        }
    }
}
