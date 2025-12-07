use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    let mut out = String::new();

    const INF: i64 = 9_000_000_000_000_000_000i64;

    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut a: Vec<i64> = Vec::with_capacity(n);
        for _ in 0..n {
            a.push(it.next().unwrap().parse::<i64>().unwrap());
        }
        let mut pref = a.clone();
        for i in 1..n {
            if pref[i - 1] > pref[i] {
                pref[i] = pref[i - 1];
            }
        }

        let mut b = a.clone();
        let mut j = 1usize;
        while j < n {
            b[j] = pref[j];
            j += 2;
        }

        let mut ans: i64 = 0;
        let mut i = 0usize;
        while i < n {
            let left = if i == 0 { INF } else { b[i - 1] };
            let right = if i + 1 >= n { INF } else { b[i + 1] };
            let mn = if left < right { left } else { right };

            let need = if b[i] > mn - 1 { b[i] - (mn - 1) } else { 0 };
            ans += need;
            i += 2;
        }

        out.push_str(&format!("{}\n", ans));
    }

    print!("{}", out);
}
