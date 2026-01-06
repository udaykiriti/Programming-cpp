use std::io::{self, Read};
use std::fmt::Write as FmtWrite;

#[allow(dead_code)]
struct fastio {
    buf: Vec<u8>,
    pos: usize,
}

impl fastio {
    #[inline]
    fn new() -> Self {
        let mut input = Vec::new();
        io::stdin().read_to_end(&mut input).expect("read stdin");
        Self { buf: input, pos: 0 }
    }

    #[inline(always)]
    fn is_whitespace(b: u8) -> bool {
        b == b' ' || b == b'\n' || b == b'\r' || b == b'\t' || b == b'\x0b' || b == b'\x0c'
    }

    #[inline]
    fn skip_whitespace(&mut self) {
        while self.pos < self.buf.len() && Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
    }

    #[inline]
    fn next_u64(&mut self) -> u64 {
        self.skip_whitespace();
        let mut x: u64 = 0;
        while self.pos < self.buf.len() {
            let b = self.buf[self.pos];
            if b < b'0' || b > b'9' { break; }
            x = x * 10 + (b - b'0') as u64;
            self.pos += 1;
        }
        x
    }

    #[inline]
    fn next_i64(&mut self) -> i64 {
        self.skip_whitespace();
        let mut neg = false;
        if self.pos < self.buf.len() && self.buf[self.pos] == b'-' {
            neg = true;
            self.pos += 1;
        }
        let mut x: i64 = 0;
        while self.pos < self.buf.len() {
            let b = self.buf[self.pos];
            if b < b'0' || b > b'9' { break; }
            x = x * 10 + (b - b'0') as i64;
            self.pos += 1;
        }
        if neg { -x } else { x }
    }

    #[inline(always)]
    fn next_usize(&mut self) -> usize { self.next_u64() as usize }

    #[inline]
    fn next_string(&mut self) -> String {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buf.len() && !Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
        String::from_utf8_lossy(&self.buf[start..self.pos]).into_owned()
    }

    #[inline]
    fn next_bytes(&mut self) -> &'_ [u8] {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buf.len() && !Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
        &self.buf[start..self.pos]
    }
}


#[inline]
fn gcd(mut a: i64, mut b: i64) -> i64 {
    while b != 0 {
        let t = a % b;
        a = b;
        b = t;
    }
    a.abs()
}

#[inline]
fn lcm(a: i64, b: i64) -> i64 {
    (a / gcd(a, b)) * b
}

#[inline]
fn pow_mod(mut a: i128, mut e: i128, m: i128) -> i128 {
    a %= m; if a < 0 { a += m }
    let mut r: i128 = 1;
    while e > 0 {
        if (e & 1) == 1 { r = (r * a) % m; }
        a = (a * a) % m;
        e >>= 1;
    }
    r
}

#[inline]
fn inv_mod(a: i128, m: i128) -> i128 {
    pow_mod(a, m - 2, m)
}

#[inline]
fn binary_search<F>(mut lo: i64, mut hi: i64, mut pred: F) -> i64
where F: FnMut(i64) -> bool {
    while lo < hi {
        let mid = lo + (hi - lo) / 2;
        if pred(mid) { hi = mid; } else { lo = mid + 1; }
    }
    lo
}

#[allow(dead_code)]
struct Dsu {
    parent: Vec<usize>,
    size: Vec<usize>,
}

#[allow(dead_code)]
impl Dsu {
    fn new(n: usize) -> Self {
        Self { parent: (0..n).collect(), size: vec![1; n] }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] == x { x } else {
            let p = self.find(self.parent[x]);
            self.parent[x] = p;
            p
        }
    }

    fn unite(&mut self, a: usize, b: usize) -> bool {
        let mut a = self.find(a);
        let mut b = self.find(b);
        if a == b { return false; }
        if self.size[a] < self.size[b] { std::mem::swap(&mut a, &mut b); }
        self.parent[b] = a;
        self.size[a] += self.size[b];
        true
    }
}

#[allow(dead_code)]
struct Fenwick {
    n: usize,
    bit: Vec<i64>,
}

#[allow(dead_code)]
impl Fenwick {
    fn new(n: usize) -> Self { Self { n, bit: vec![0; n+1] } }

    fn add(&mut self, mut idx: usize, delta: i64) {
        while idx <= self.n {
            self.bit[idx] += delta;
            idx += idx & (!idx + 1);
        }
    }

    fn sum(&self, mut idx: usize) -> i64 {
        let mut res = 0i64;
        while idx > 0 {
            res += self.bit[idx];
            idx -= idx & (!idx + 1);
        }
        res
    }

    fn range_sum(&self, l: usize, r: usize) -> i64 {
        if r < l { 0 } else { self.sum(r) - self.sum(l - 1) }
    }
}


fn solve(sc: &mut fastio, out: &mut String) {
    let n = sc.next_usize();
    let mut s: i64 = 0;
    for _ in 0..n {
        s += sc.next_i64();
    }
    writeln!(out, "{}", s).unwrap();
}

fn main() {
    let mut sc = fastio::new();
    let mut out = String::with_capacity(1 << 20);

    solve(&mut sc, &mut out); 
    print!("{}", out);
}

/* Look for |>
 * Non-trivial problems with simple solutions, proofs, and implementations.
 * Check upper/lower bounds (UB/LB).
 * Try working backward or from end cases.
 * Do not make large assumptions without a basic proof idea.
 * Overflow, bounds checks, and panics kill solutions—check them first.
 * Use DP to relax constraints; store only the minimum required state.
 * Handle special cases (n = 1?) and edge cases.
 * Do something instead of nothing; stay organized.
 * WRITE STUFF DOWN.
 * Eliminate wrong ideas first.
 * Don’t get stuck on one approach for too long.
 * If there’s no solution within the time limit, give up.
 */
