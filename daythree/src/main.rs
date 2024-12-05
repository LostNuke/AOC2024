use std::fs;
use regex::Regex;

fn main() {
    let input = fs::read_to_string("./input").unwrap();

    println!("Part One: {}", part_one(&input));
    println!("Part Two: {}", part_two(&input));
}

fn part_two(input: &String) -> i32 {
    let mut processed_input = input.clone();
    loop {
        let firsti = processed_input.find("don't()");
        if firsti == None { break }
        let secondi = processed_input[firsti.unwrap()..].find("do()");
        if secondi == None {
            processed_input.replace_range(firsti.unwrap().., "");
        } else {
            processed_input.replace_range(firsti.unwrap()..secondi.unwrap() + firsti.unwrap(), "")
        }
    }
    part_one(&processed_input)

}


fn part_one(input: &String) -> i32 {
    let re = Regex::new(r"mul\(\d+,\d+\)").unwrap();

    let mut sum = 0;
    for line in re.captures_iter(&*input) {
        let nums: Vec<i32> = line[0].to_string().replace("mul(", "").replace(")", "").split(",").map(|num| num.parse().unwrap()).collect();
        sum += nums.iter().product::<i32>();
    }


    sum
}
