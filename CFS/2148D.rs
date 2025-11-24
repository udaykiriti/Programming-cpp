use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| x.parse::<i64>().unwrap());

    let t = it.next().unwrap() as usize;
    let mut tcase: i32 = 0;

    for _ in 0..t {
        tcase += 1;

        let n = it.next().unwrap() as usize;
        let mut a: Vec<i64> = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap());
        }

        let mut b: Vec<i64> = Vec::new();
        let mut evensum: i64 = 0;

        for &val in &a {
            if val % 2 == 0 {
                evensum += val;
            } else {
                b.push(val);
            }
        }

        if b.is_empty() {
            println!("0");
            continue;
        }

        b.sort(); 
        let half = (b.len() + 1) / 2;
        let mut noo = evensum;
        for i in 0..half {
            noo += b[b.len() - 1 - i];
        }

        println!("{}", noo);
    }
}
