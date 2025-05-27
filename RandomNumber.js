// Generate a random number between 1 and 100 (inclusive)
function getRandomNumber() {
    return Math.floor(Math.random() * 30) + 1;
}

const randomNum = getRandomNumber();
console.log(randomNum);