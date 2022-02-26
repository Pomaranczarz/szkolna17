use std::time::{ Duration, Instant };

fn main() {
    let mut measure_sum: u128 = 0;
    let mut num_of_cases: i128 = 5000;
    let mut count: i64 = 1;

    while num_of_cases < 1000000 {
        for _i in 0..100 {
            measure_sum += measure(num_of_cases).as_micros()
        }

        println!("Average exec time for {} cases: {} mircoseconds", num_of_cases, measure_sum / 100);
        num_of_cases += 5000 * count as i128;
        measure_sum = 0;
        count += 1;
    }
}

fn dec_to_bin(mut dec_number: i128) -> String {
    let mut result = String::new();
    while dec_number > 0 {
        result.push({
            if dec_number % 2 == 0 {
                '0'
            } else {
                '1'
            }
        });

        dec_number /= 2;
    }


    result.chars().rev().collect()
}

fn measure(number_of_cases: i128) -> Duration {
    let start = Instant::now();

    for i in 0..number_of_cases {
        dec_to_bin(i);
    }

    start.elapsed()
}