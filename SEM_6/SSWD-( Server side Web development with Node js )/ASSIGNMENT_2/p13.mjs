function sumOfDigits(number) {
  return new Promise((resolve, reject) => {
    if (number < 100000 || number > 999999) {
      reject("Please enter a six-digit number.");
    } else {
      const sum = number
        .toString()
        .split("")
        .map(Number)
        .reduce((acc, digit) => acc + digit, 0);
      resolve(sum);
    }
  });
}

const number = 123456;

sumOfDigits(number)
  .then((sum) => {
    console.log(`The sum of the digits is: ${sum}`);
  })
  .catch((error) => {
    console.error(error);
  });

/*
The sum of the digits is: 21
*/