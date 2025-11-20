use std::io::{self, Read};

fn main() {
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace().map(|x| x.parse::<i64>().unwrap());

    let t = it.next().unwrap() as usize;
    const INF: i64 = 9_000_000_000_000_000_000;

    for _case in 0..t {
        let n = it.next().unwrap() as usize;
        let mut a: Vec<i64> = Vec::with_capacity(n);
        let mut c: Vec<i64> = Vec::with_capacity(n);
        
        for _ in 0..n { 
            a.push(it.next().unwrap()); 
        }
        for _ in 0..n { 
            c.push(it.next().unwrap()); 
        }

        let mut vals = a.clone();
        vals.sort_unstable();
        vals.dedup();
        let m = vals.len();

        let mut dp_prev = vec![INF; m];
        let mut dp_cur  = vec![INF; m];

        for k in 0..m {
            dp_prev[k] = if a[0] == vals[k] { 0 } else { c[0] };
        }

        for i in 1..n {
            let mut pref = vec![INF; m];
            pref[0] = dp_prev[0];
            for k in 1..m {
                pref[k] = pref[k-1].min(dp_prev[k]);
            }

            for k in 0..m {
                let cost_i = if a[i] == vals[k] { 0 } else { c[i] };
                dp_cur[k] = pref[k].saturating_add(cost_i);
            }

            std::mem::swap(&mut dp_prev, &mut dp_cur);
            for x in dp_cur.iter_mut() { *x = INF; }
        }

        let ans = dp_prev.into_iter().min().unwrap_or(0);
        println!("{}", ans);
    }
}
