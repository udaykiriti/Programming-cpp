use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();
    let t: usize = it.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let y: i64 = it.next().unwrap().parse().unwrap();
        let mut a = vec![0usize; n];
        let mut m: usize = 0;

        for i in 0..n {
            a[i] = it.next().unwrap().parse().unwrap();
            if a[i] > m { m = a[i]; }
        }

        let mut f = vec![0i64; m + 1];
        for &v in &a { f[v] += 1; }

        let mut p = vec![0i64; m + 1];
        for i in 1..=m { p[i] = p[i - 1] + f[i]; }

        let mut best = i64::MIN;

        for x in 2..=m + 1 {
            let mk = (m + x - 1) / x;
            let mut dp_s = vec![0i64; mk + 1];
            let mut dp_r = vec![0i64; mk + 1];
            for k in 1..=mk {
                let l = (k - 1) * x + 1;
                let r = std::cmp::min(k * x, m);
                
                if l > r {
                    dp_s[k] = dp_s[k - 1];
                    dp_r[k] = dp_r[k - 1];
                    continue;
                }

                let z = p[r] - p[l - 1];

                if z == 0 {
                    dp_s[k] = dp_s[k - 1];
                    dp_r[k] = dp_r[k - 1];
                } else {
                    dp_s[k] = dp_s[k - 1] + (k as i64) * z;
                    if k <= m {
                        dp_r[k] = dp_r[k - 1] + std::cmp::min(z, f[k]);
                    } else {
                        dp_r[k] = dp_r[k - 1];
                    }
                }
            }
            let s_val = dp_s[mk];
            let r_val = dp_r[mk];
            let pr = n as i64 - r_val;
            let inc = s_val - y * pr;
            if inc > best { best = inc; }
        }
        println!("{}", best);
    }
}
