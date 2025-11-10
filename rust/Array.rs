fn main() {
    let arr = [1, 2, 3, 4, 5];
    println!("arr:");
    for &x in &arr { print!("{} ", x); }
    println!();

    let mut marr = [1, 2, 3, 4, 5];
    marr[2] = 99;
    println!("mutable array:");
    for &x in &marr { print!("{} ", x); }
    println!();

    let v = vec![10, 20, 30, 40, 50];
    println!("vector:");
    for &x in &v { print!("{} ", x); }
    println!();

    let mut dv: Vec<i32> = Vec::new();
    dv.push(1);
    dv.push(2);
    dv.push(3);
    println!("dynamic vector (push):");
    for &x in &dv { print!("{} ", x); }
    println!();

    let mut cap = Vec::with_capacity(5);
    for i in 1..=5 { cap.push(i * 10); }
    println!("vector with capacity:");
    for &x in &cap { print!("{} ", x); }
    println!();

    let vs = vec!["apple".to_string(), "banana".to_string(), "cherry".to_string()];
    println!("vector of strings:");
    for s in &vs { print!("{} ", s); }
    println!();

    let mat = vec![vec![1, 2], vec![3, 4], vec![5, 6]];
    println!("2D vector (matrix):");
    for row in &mat {
        for &x in row { print!("{} ", x); }
        println!();
    }

    let mut ops = vec![3, 1, 4, 5, 2];
    ops.sort();
    println!("sorted:");
    for &x in &ops { print!("{} ", x); }
    println!();

    ops.reverse();
    println!("reversed:");
    for &x in &ops { print!("{} ", x); }
    println!();

    ops.push(6);
    ops.pop();
    ops.insert(1, 99);
    ops.remove(2);
    println!("after push/pop/insert/remove:");
    for &x in &ops { print!("{} ", x); }
    println!();
    println!("{}", if ops.contains(&99) { "Contains 99" } else { "No 99" });

    println!("while iteration:");
    let mut i = 0usize;
    while i < ops.len() {
        print!("{} ", ops[i]);
        i += 1;
    }
    println!();

    println!("loop iteration:");
    let mut j = 0usize;
    loop {
        if j >= ops.len() { break; }
        print!("{} ", ops[j]);
        j += 1;
    }
    println!();

    let t = (1, "a", 3.14);
    println!("tuple: {} {} {}", t.0, t.1, t.2);

    let slice = &arr[1..4];
    println!("slice:");
    for &x in slice { print!("{} ", x); }
    println!();
}
