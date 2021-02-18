use std::io;

fn get_fibonacci(n : usize) -> usize {
    if n == 1 {
        return 1 as usize;
    }else if n == 2 {
        return 1 as usize;
    }

    return get_fibonacci(n - 1) + get_fibonacci(n - 2);
}

fn get_fibo_iter(n : usize) -> usize {
    let mut prev = 1;
    let mut prevprev = 1;

    if n <= 0{
        return 1;
    }

    for _ in 0..n-2 {
        let temp = prev;
        prev += prevprev;
        prevprev = temp;
    }

    return prev;
}

fn main(){
    let mut n = String::new(); 

    println!("Enter a value between 0 and 255");

    io::stdin()
        .read_line(&mut n)
        .expect("Failed to parse number");

    let val: usize = n.trim().parse().expect("Failed to parse numbers");

    println!("Select calculation method: ITER/RECUR");

    let mut calc_type = String::new();

    io::stdin()
        .read_line(&mut calc_type)
        .expect("Failed to parse calculation type");
   
    let ans : usize = match calc_type.trim() as &str { 
        "ITER" => get_fibo_iter(val),
        "RECUR" => get_fibonacci(val),
        _ => 0, 
    };

    if ans == 0 {
        println!("Unknown calculation type, {:?}, {}", calc_type.trim(), calc_type.trim() == "ITER");
    }else{
        println!("{}th Fibonacci number was {}", val, ans); 
    }
}
