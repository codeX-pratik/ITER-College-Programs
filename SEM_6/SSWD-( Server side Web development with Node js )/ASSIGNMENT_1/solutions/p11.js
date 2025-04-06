import { isPrime } from './checkPrime.js';

const number = 29;

if (isNaN(number)) {
  console.log('Invalid number!');
} else {
  const result = isPrime(number);
  console.log(`${number} is ${result ? 'a prime' : 'not a prime'} number.`);
}

/*

29 is a prime number.

*/