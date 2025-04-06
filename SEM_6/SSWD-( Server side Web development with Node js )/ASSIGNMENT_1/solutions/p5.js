import fs from "fs";

fs.readFile("./test1.txt", "utf8", (err, data) => {
  if (err) {
    console.error(err);
  } else {
    console.log(data);
  }
});

/*

Hello there
This is me !!

*/