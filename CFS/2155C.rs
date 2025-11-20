/*
 *                                                     ----~~~~~~~~~~~------___
 *                                    .  .   ~~//====......          --~ ~~
 *                    -.            \_|//     |||\  ~~~~::::... /~
 *                 ___-==_       _-~o~  \/    |||  \            _/-
 *         ---~~~.==~||\=_    -_--~/_-~|-   |\   \        _/~
 *     _-~~     .=~    |  \-_    '-~7  /-   /  ||    \      /
 *   .~       .~       |   \ -_    /  /-   /   ||      \   /
 *  /  ____  /         |     \ ~-_/  /|- _/   .||       \ /
 *  |~~    ~~|--~~~~--_ \     ~==-/   | \~--===~~        .\
 *           '         ~-|      /|    |-~\~~       --
 *                       |--_/ |    |   ~\_   _-~            /\
 *                            /  \     \__   \/~                \__
 *                        _--~ _/ | .-____--~-/                  ==.
 *                       ((->/~   '.|||' -_|    -/ ,              . _||
 *                                  -_     ~\      ---l__i__i__i--_/
 *                                  _-~-__   ~)  \--______________--
 *                                //.-~~~-~_--~- |-------~~~~~~
 *                                       //.-~--\
 *                       ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
 *
 *                       DiVine BeAst bleSSes, may there be no buGs
 */


 use std::io::{self, Read};

const MOD: i64 = 676_767_677;

fn valid(n: usize, q: &Vec<i64>, L: i64) -> bool {
    if L < 0 || L as usize > n { return false; }
    let mut prev: i64 = 0;
    for i in 1..=n {
        let r = L + q[i] - prev;
        let s = r - prev;
        if s != 0 && s != 1 { return false; }
        if r < 0 || r > i as i64 { return false; }
        prev = r;
    }
    prev == L
}

fn main() {
    // fast input
    let mut s = String::new();
    io::stdin().read_to_string(&mut s).unwrap();
    let mut it = s.split_whitespace();

    let t: usize = it.next().unwrap().parse().unwrap();
    for _case in 0..t {
        let n: usize = it.next().unwrap().parse().unwrap();
        let mut p = vec![0i64; n + 1];
        for i in 1..=n {
            p[i] = it.next().unwrap().parse().unwrap();
        }
        let mut q = vec![0i64; n + 1];
        for i in 1..=n {
            q[i] = p[i] - (n as i64 - i as i64 + 1);
        }

        let mut ans: i64 = 0;
        let c1 = -q[1];
        let c2 = 1 - q[1];
        if valid(n, &q, c1) { ans += 1; }
        if c1 != c2 && valid(n, &q, c2) { ans += 1; }

        println!("{}", (ans % MOD + MOD) % MOD);
    }
}
