let score = 85;
console.log("Outer score:", score);

if (true) {
    let score = 95;
    console.log("Inner score:", score);
}

console.log("Outer score after block:", score);

const COUNTRY = "Japan";
console.log("Country:", COUNTRY);