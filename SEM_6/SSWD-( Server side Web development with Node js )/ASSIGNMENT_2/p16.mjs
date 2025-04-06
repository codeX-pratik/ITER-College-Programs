function factorial(num) {
    if (num === 0 || num === 1) return 1;
    let fact = 1;
    for (let i = 2; i <= num; i++) {
        fact *= i;
    }
    return fact;
}

function isStrongNumber(number) {
    let sum = 0;
    let temp = number;

    while (temp > 0) {
        let digit = temp % 10;
        sum += factorial(digit);
        temp = Math.floor(temp / 10);
    }

    return sum === number;
}

const number = 145;

if (isStrongNumber(number)) {
    console.log(`${number} is a Strong number.`);
} else {
    console.log(`${number} is not a Strong number.`);
}

/*
145 is a Strong number.
*/