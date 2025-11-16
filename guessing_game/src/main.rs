extern crate rand;

use rand::Rng;
use std::io;
use std::cmp::Ordering;


fn main() {
    println!("Guess the number!");
    //let secret_number = rand::thread_rng().gen_range(1.101);
    let secret_number = rand::thread_rng().gen_range(1..=100);

    println!("The secret number is: {}", secret_number);
    
    loop{
    println!("Please input your guess.");
    

    let mut guess = String::new();

    io::stdin().read_line(&mut guess).expect("Failed to read line");

    //let guess: u32 = guess.trim().parse().expect("Please type a number");


    let guess : u32 = match guess.trim().parse(){
        Ok(num) => num,
        Err(_) => continue,
    };

    println!("You guessed: {}",guess);


    match guess.cmp(&secret_number){
        Ordering::Less => println!("Too small!"),
        Ordering::Greater => println!("Too big!"),
        Ordering::Equal =>{ 
            println!("You win");
            return;
        }
    }
}
    //mut -> mutable (if not mentioned it can't bre changed).
    /* let mut guess = String::new();

    io::stdin().read_line(&mut guess).expect("Failed to read line");

    println!("You guessed: {}",guess); */

/*     
    let mut x = 10; // if! mut it will THrow error
    x = 20;
    println!("{}",x); */
}
