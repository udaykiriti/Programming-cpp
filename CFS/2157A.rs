use std::io::{self, Read};

fn main() {
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut it = input.split_whitespace();

    let t: usize = match it.next() {
        Some(x) => x.parse().unwrap(),
        None => return,
    };

    for _case in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut fre = vec![0usize; n + 1];

        for _ in 0..n {
            let ele: usize = it.next().unwrap().parse().unwrap();
            if ele <= n {
                fre[ele] += 1;
            }
        }

        let mut ans: usize = 0;
        ans += fre[0];
        for i in 1..=n {
            if fre[i] < i {
                ans += fre[i];
            } else {
                ans += fre[i] - i;
            }
        }

        println!("{}", ans);
    }
}
