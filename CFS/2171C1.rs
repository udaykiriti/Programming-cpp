use std::io::{self, Read};

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
        matches!(b, b' ' | b'\n' | b'\r' | b'\t' | 0x0c)
    }
    #[inline]
    fn skip_whitespace(&mut self) {
        while self.pos < self.buf.len() && Self::is_whitespace(self.buf[self.pos]) {
            self.pos += 1;
        }
    }
    #[inline]
    fn next_i32(&mut self) -> i32 {
        self.skip_whitespace();
        let mut neg = false;
        if self.pos < self.buf.len() && self.buf[self.pos] == b'-' {
            neg = true;
            self.pos += 1;
        }
        let mut x: i32 = 0;
        while self.pos < self.buf.len() {
            let b = self.buf[self.pos];
            if b < b'0' || b > b'9' { break; }
            x = x * 10 + (b - b'0') as i32;
            self.pos += 1;
        }
        if neg { -x } else { x }
    }
    #[inline]
    fn next_usize(&mut self) -> usize { self.next_i32() as usize }
}

fn solve(sc: &mut FastScanner, out: &mut String) {
    let t = sc.next_usize();
    for _ in 0..t {
        let n = sc.next_usize();
        let mut a = vec![0i32; n];
        for i in 0..n { a[i] = sc.next_i32(); }
        let mut b = vec![0i32; n];
        for i in 0..n { b[i] = sc.next_i32(); }

        let mut tx = 0i32;
        let mut last = None;
        for i in 0..n {
            let d = a[i] ^ b[i];
            tx ^= d;
            if d == 1 { last = Some(i); }
        }

        if tx == 0 {
            out.push_str("Tie\n");
        } else {
            match last {
                Some(i) => {
                    if i % 2 == 0 {
                        out.push_str("Ajisai\n");
                    } else {
                        out.push_str("Mai\n");
                    }
                }
                None => {
                    out.push_str("Tie\n");
                }
            }
        }
    }
}

fn main() {
    let mut sc = FastScanner::new();
    let mut out = String::with_capacity(1 << 20);
    solve(&mut sc, &mut out);
    print!("{}", out);
}
