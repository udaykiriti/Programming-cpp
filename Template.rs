fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let temp = b;
        b = a % b;
        a = temp;
    }
    a
}

fn lcm(a: i64, b: i64) -> i64 {
    (a / gcd(a, b)) * b
}

/// Computes `a^e mod m` using binary exponentiation.
fn pow_mod(mut base: i128, mut exp: i128, modulus: i128) -> i128 {
    base = ((base % modulus) + modulus) % modulus;
    let mut result = 1i128;
    while exp > 0 {
        if exp & 1 == 1 {
            result = (result * base) % modulus;
        }
        base = (base * base) % modulus;
        exp >>= 1;
    }
    result
}

/// Modular multiplicative inverse (assumes m is prime).
fn inv_mod(a: i128, m: i128) -> i128 {
    pow_mod(a, m - 2, m)
}

/// Binary search for the first value where `pred` returns true.
fn binary_search<F>(mut lo: i64, mut hi: i64, mut pred: F) -> i64
where
    F: FnMut(i64) -> bool,
{
    while lo < hi {
        let mid = lo + (hi - lo) / 2;
        if pred(mid) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    lo
}

fn solve() {
}

fn main() {
    solve();
}
