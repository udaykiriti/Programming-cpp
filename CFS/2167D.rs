use std::io::{self,Read};

fn sieve(limit :usize) -> Vec<i64>{
    let mut isp = vec![true; limit+1];
    let mut primes = Vec::new();
    isp[0] = false;
    if limit >= 1{
        isp[1] = false;
    }

    for i in 2..=limit{
        if isp[i]{
            primes.push(i as i64);
            let mut j = i * i;
            if j > limit{
                continue;
            }
            while j <= limit{
                isp[j]= false;
                j += i;    
            }
        }
    }
    primes
}


fn gcd(mut a:i64,mut b:i64) -> i64{
    while 0 != b{
        let r = a %b;
        a = b;
        b = r;
    }
    a
}

fn main(){
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let primes = sieve(202);

    let t:usize = it.next().unwrap().parse().unwrap();

    for _ in 0..t{
        let n:usize = it.next().unwrap().parse().unwrap();
        let mut curr :i64 = 0;
        for i in 0..n{
            let x: i64 = it.next().unwrap().parse().unwrap();
            if 0 == i {
                curr = x;
            }
            else{
                curr = gcd(curr,x);
            }
        }

        let mut res : i64 = -1;
        for &p in &primes {
            if curr % p != 0{
                res = p;
                break;
            }
        }
        println!("{}",res);
    }
}