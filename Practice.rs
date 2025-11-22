static mut ARR1 : [i32;5] = [1,2,2,3,2];

fn main() {
    let tup : (i32,f64,u8) = (500,6.4,1);
    let(x,y,z) = tup;
    println!("{}\n{}\n{}\n",x,y,z);

    let sis = tup.0;
    let bro = tup.1;
    let one = tup.2;

    println!("{}\n{}\n{}\n",sis,bro,one);

    let arr = [1,2,3,3,4];
    println!("{}\n",arr[0]);

    another_fn();
    let x:i32 = passpa(arr[1],arr[2]);
    println!("{}",x);
}

fn another_fn() {
    unsafe{
    ARR1[3] = 9;
    println!("{}\n",ARR1[2+1]);
    }
}

fn passpa(x : i32 , y : i32) -> i32{
    println!("{}",x);
    println!("{}",y);
    let sum : i32 = x + y;
    sum
}
