fn main() {
    print_labeled_measurement(5, 'h');
}

fn print_labeled_measurement(value: i32, unit_label: char) {
    println!("The measurement is: {value}{unit_label}");

    let x = five();

    println!("The value of x is: {x}");
}

fn five() -> i32 {
    5
}
