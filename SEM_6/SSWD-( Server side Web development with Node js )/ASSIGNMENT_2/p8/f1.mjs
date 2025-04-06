function gcd(a, b) {
  return b === 0 ? a : gcd(b, a % b);
}

function lcm(a, b) {
  return (a * b) / gcd(a, b);
}

function calcgcd(a, b, c) {
  return gcd(gcd(a, b), c);
}

function calclcm(a, b, c) {
  return lcm(lcm(a, b), c);
}

export { calcgcd, calclcm };