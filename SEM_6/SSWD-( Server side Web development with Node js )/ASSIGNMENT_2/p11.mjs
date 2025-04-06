import express from "express";

const app = express();
const PORT = 3000;

app.get("/check-neon/:num", (req, res) => {
  const num = parseInt(req.params.num);
  const square = num * num;

  const digitSum = square
    .toString()
    .split("")
    .reduce((sum, digit) => sum + parseInt(digit), 0);

  if (digitSum === num) {
    res.send(`${num} is a Neon number`);
  } else {
    res.send(`${num} is NOT a Neon number`);
  }
});

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});

/*
http://localhost:3000/check-neon/9

9 is a Neon number
*/