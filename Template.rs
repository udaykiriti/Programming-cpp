use std::io::{self, Read};
use std::fmt::Write as FmtWrite;

/// Fast buffered input reader.
#[allow(dead_code)]
struct FastIO {
    buf: Vec<u8>,
    pos: usize,
}

impl FastIO {
    fn new() -> Self {
        let mut input = Vec::new();
        io::stdin()
            .read_to_end(&mut input)
            .expect("failed to read stdin");
        Self { buf: input, pos: 0 }
    }

    fn is_whitespace(b: u8) -> bool {
        matches!(b, b' ' | b'\n' | b'\r' | b'\t' | b'\x0b' | b'\x0c')
    }

    fn skip_whitespace(&mut self) {
        while self.pos < self.buf.len() && Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
    }

    fn next_u64(&mut self) -> u64 {
        self.skip_whitespace();
        let mut num = 0u64;
        while self.pos < self.buf.len() && self.buf[self.pos].is_ascii_digit() {
            num = num * 10 + (self.buf[self.pos] - b'0') as u64;
            self.pos += 1;
        }
        num
    }

    fn next_i64(&mut self) -> i64 {
        self.skip_whitespace();
        let is_negative = self.pos < self.buf.len() && self.buf[self.pos] == b'-';
        if is_negative {
            self.pos += 1;
        }
        let mut num = 0i64;
        while self.pos < self.buf.len() && self.buf[self.pos].is_ascii_digit() {
            num = num * 10 + (self.buf[self.pos] - b'0') as i64;
            self.pos += 1;
        }
        if is_negative { -num } else { num }
    }

    fn next_usize(&mut self) -> usize {
        self.next_u64() as usize
    }

    fn next_string(&mut self) -> String {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buf.len() && !Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
        String::from_utf8_lossy(&self.buf[start..self.pos]).into_owned()
    }

    fn next_bytes(&mut self) -> &[u8] {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buf.len() && !Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
        &self.buf[start..self.pos]
    }
}

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


/// Disjoint set union (union-find) data structure.
#[allow(dead_code)]
struct Dsu {
    parent: Vec<usize>,
    size: Vec<usize>,
}

#[allow(dead_code)]
impl Dsu {
    fn new(n: usize) -> Self {
        Self {
            parent: (0..n).collect(),
            size: vec![1; n],
        }
    }

    fn find(&mut self, x: usize) -> usize {
        if self.parent[x] != x {
            self.parent[x] = self.find(self.parent[x]);
        }
        self.parent[x]
    }

    /// Returns true if a and b were in different sets.
    fn unite(&mut self, a: usize, b: usize) -> bool {
        let mut root_a = self.find(a);
        let mut root_b = self.find(b);
        if root_a == root_b {
            return false;
        }
        if self.size[root_a] < self.size[root_b] {
            let temp = root_a;
            root_a = root_b;
            root_b = temp;
        }
        self.parent[root_b] = root_a;
        self.size[root_a] += self.size[root_b];
        true
    }
}


/// Fenwick tree (binary indexed tree) for prefix sum queries.
#[allow(dead_code)]
struct Fenwick {
    n: usize,
    tree: Vec<i64>,
}

#[allow(dead_code)]
impl Fenwick {
    fn new(n: usize) -> Self {
        Self {
            n,
            tree: vec![0; n + 1],
        }
    }

    fn add(&mut self, mut idx: usize, delta: i64) {
        while idx <= self.n {
            self.tree[idx] += delta;
            idx += self.lowbit(idx);
        }
    }

    /// Returns `x & (-x)`, the lowest set bit of `x`.
    fn lowbit(&self, x: usize) -> usize {
        x & (x.wrapping_neg())
    }

    fn sum(&self, mut idx: usize) -> i64 {
        let mut result = 0i64;
        while idx > 0 {
            result += self.tree[idx];
            idx -= self.lowbit(idx);
        }
        result
    }

    fn range_sum(&self, l: usize, r: usize) -> i64 {
        if r < l {
            0
        } else {
            self.sum(r) - if l > 0 { self.sum(l - 1) } else { 0 }
        }
    }
}

fn _GO(io: &mut FastIO, out: &mut String) {
    let n = io.next_usize();
    let mut sum: i64 = 0;
    for _ in 0..n {
        sum += io.next_i64();
    }
    writeln!(out, "{}", sum).unwrap();
}

fn main() {
    let mut io = FastIO::new();
    let mut out = String::with_capacity(1 << 20);

    _GO(&mut io, &mut out);
    print!("{}", out);
}

