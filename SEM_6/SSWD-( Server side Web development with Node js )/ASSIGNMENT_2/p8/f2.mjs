import { calcgcd, calclcm } from "./f1.mjs";

const a = 120, b = 300, c = 480;

const gcdValue = calcgcd(a, b, c);
const lcmValue = calclcm(a, b, c);

console.log(`GCD of ${a}, ${b}, ${c} is: ${gcdValue}`);
console.log(`LCM of ${a}, ${b}, ${c} is: ${lcmValue}`);

function countFactors(num) {
  let count = 0;
  for (let i = 1; i <= num; i++) {
    if (num % i === 0) count++;
  }
  return count;
}

const fc_gcd = countFactors(gcdValue);
const fc_lcm = countFactors(lcmValue);

console.log(`Factors of GCD (${gcdValue}): ${fc_gcd}`);
console.log(`Factors of LCM (${lcmValue}): ${fc_lcm}`);

export { fc_gcd, fc_lcm };