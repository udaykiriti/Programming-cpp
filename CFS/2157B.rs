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
        b == b' ' || b == b'\n' || b == b'\r' || b == b'\t'
    }

    #[inline]
    fn skip_whitespace(&mut self) {
        while self.pos < self.buf.len() && Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
    }

    #[inline]
    fn next_usize(&mut self) -> usize {
        self.next_i64() as usize
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
    fn next_string(&mut self) -> String {
        self.skip_whitespace();
        let start = self.pos;
        while self.pos < self.buf.len() && !Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
        String::from_utf8_lossy(&self.buf[start..self.pos]).into_owned()
    }
}

fn move_towards_zero(v: &mut i64) {
    if *v > 0 { *v -= 1; }
    else if *v < 0 { *v += 1; }
}

fn main() {
    let mut sc = FastScanner::new();
    let t = sc.next_usize();
    let mut out = String::with_capacity(1 << 20);

    for _case in 0..t {
        let n = sc.next_usize();
        let mut x = sc.next_i64();
        let mut y = sc.next_i64();
        let s = sc.next_string();
        let bs = s.as_bytes();

        for i in (0..n).rev() {
            if bs[i] == b'8' {
                move_towards_zero(&mut x);
                move_towards_zero(&mut y);
            } else {
                if x.abs() >= y.abs() {
                    move_towards_zero(&mut x);
                } else {
                    move_towards_zero(&mut y);
                }
            }
        }

        if x == 0 && y == 0 {
            writeln!(out, "Yes").unwrap();
        } else {
            writeln!(out, "No").unwrap();
        }
    }

    print!("{}", out);
}
