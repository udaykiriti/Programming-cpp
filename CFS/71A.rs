use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();

    let mut it = input.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t {
        let s = it.next().unwrap();

        if s.len() > 10 {
            let chars: Vec<char> = s.chars().collect();
            println!("{}{}{}", chars[0], s.len() - 2, chars[chars.len() - 1]);
        } else {
            println!("{}", s);
        }
    }
}
