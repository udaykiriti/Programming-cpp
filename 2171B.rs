use std::io::{self, Read};
use std::fmt::Write as FmtWrite;

struct FastScanner {
    buf: Vec<u8>,
    pos: usize,
}
impl FastScanner {
    #[inline]
    fn new() -> Self {
        let mut input = Vec::new();
        io::stdin().read_to_end(&mut input).expect("read stdin");
        Self { buf: input, pos: 0 }
    }
    #[inline]
    fn is_whitespace(b: u8) -> bool {
        b == b' ' || b == b'\n' || b == b'\r' || b == b'\t' || b == b'\x0c'
    }
    #[inline]
    fn skip_whitespace(&mut self) {
        while self.pos < self.buf.len() && Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
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
    #[inline]
    fn next_usize(&mut self) -> usize { self.next_i64() as usize }
}

fn solve(sc: &mut FastScanner, out: &mut String) {
    let t = sc.next_usize();
    for _ in 0..t {
        let n = sc.next_usize();
        let mut a: Vec<i64> = (0..n).map(|_| sc.next_i64()).collect();

        let lft = a[0] != -1;
        let ryt = a[n-1] != -1;

        let ans = if lft && ryt {
            (a[n-1] - a[0]).abs()
        } else {
            if !lft && ryt {
                a[0] = a[n-1];
            } else if lft && !ryt {
                a[n-1] = a[0];
            } else { 
                a[0] = 0;
                a[n-1] = 0;
            }
            0
        };

        for v in &mut a {
            if *v == -1 { *v = 0; }
        }

        writeln!(out, "{}", ans).unwrap();
        for (i, v) in a.iter().enumerate() {
            if i > 0 { out.push(' '); }
            write!(out, "{}", v).unwrap();
        }
        out.push('\n');
    }
}

fn main() {
    let mut sc = FastScanner::new();
    let mut out = String::with_capacity(1 << 20);
    solve(&mut sc, &mut out);
    print!("{}", out);
}
