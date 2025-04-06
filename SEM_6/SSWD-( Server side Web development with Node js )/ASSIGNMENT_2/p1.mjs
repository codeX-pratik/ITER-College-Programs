import fs from "fs";
const files = fs.readdirSync(".");
files.forEach((x) => console.log(x));
