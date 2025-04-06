import express from "express";

const app = express();
const PORT = 8125;
const HOST = "127.0.0.2";

function isArmstrong(num) {
  const digits = num.toString().split("");
  const power = digits.length;
  const sum = digits.reduce(
    (acc, digit) => acc + Math.pow(parseInt(digit), power),
    0
  );
  return sum === num;
}

app.get("/", (req, res) => {
  const number = parseInt(req.query.number);

  if (isNaN(number)) {
    res.send(
      "Please provide a valid number in the query string. Example: /?number=153"
    );
    return;
  }

  if (isArmstrong(number)) {
    res.send(`${number} is an Armstrong number.`);
  } else {
    res.send(`${number} is NOT an Armstrong number.`);
  }
});

app.listen(PORT, HOST, () => {
  console.log(`Server running at http://${HOST}:${PORT}`);
});

/*

http://127.0.0.2:8125/?number=153
153 is an Armstrong number.

*/