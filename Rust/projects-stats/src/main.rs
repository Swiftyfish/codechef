use std::io;
use std::collections::HashMap;

fn main() {
   let mut a = String::new();
   
   println!("Please input space-separated array");

   io::stdin()
       .read_line(&mut a)
       .expect("Failed to read");
   
   let mut vec = a.split_whitespace()
       .map(|x| x.parse::<isize>().expect("Error parsing input"))
       .collect::<Vec<isize>>();

   vec.sort();

   let (mut mean, mut mode, median) : (f64, isize, f64);

   mean = 0.0;

   mode = *vec.first().expect("Empty array");

   let mut occurences = HashMap::new();

   let n = vec.len();

   if n == 0 {
       println!("Empty array");
       return;
   }

   for i in &vec {
       //increment mean by value divided by number of inputs
        mean += (*i as f64)/(n as f64);

        // count occurences of values using hashmap
        let count = occurences.entry(i)
            .or_insert(0);
        *count += 1;
   }

   for (key, value) in &occurences {
       if occurences.get(&mode).unwrap() < value{
           mode = **key;
       }
   }

   if n&1 == 1 {
       median = vec[n/2 - 1] as f64;
   } else{
       median = (vec[n/2 - 1] as f64 + vec[n/2] as f64)/2.0;
   }

   println!("Mean : {} \nMedian: {}\nMode: {}", mean, median, mode);
}
