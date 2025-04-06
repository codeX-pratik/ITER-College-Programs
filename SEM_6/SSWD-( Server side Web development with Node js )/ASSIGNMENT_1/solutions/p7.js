import { readFileSync } from "fs";

const data = JSON.parse(readFileSync("./data.json", "utf-8"));

console.log(data);

/*

{
  name: 'John',
  lastName: 'Singh',
  dob: 1990,
  city: 'Chennai',
  age: 36,
  salary: 100000
}

*/