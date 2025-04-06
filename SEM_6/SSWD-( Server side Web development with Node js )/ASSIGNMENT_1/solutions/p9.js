import express from "express";
const app = express();
const PORT = 3000;
const HOST = "127.0.0.2";

app.get("/", (req, res) => {
  const number = parseInt(req.query.number);
  if (!isNaN(number) && number >= 0) {
    const fact = (n) => {
      if (n === 0 || n === 1) return 1;
      return n * fact(n - 1);
    };

    const factors = (n) => {
      let count = 0;
      for (let i = 1; i <= n; i++) {
        if (n % i === 0) count++;
      }
      return count;
    };

    res.send(`Number: ${number}, Factorial: ${fact(number)}, Factors: ${factors(number)}`);
  } else {
    res.send("Please provide a valid non-negative integer in the query string. Example: /?number=5");
  }
});


app.listen(PORT, HOST, () => {
  console.log(`Server running at http://${HOST}:${PORT}`);
});

/*

http://127.0.0.2:3000/?number=5
Number: 5, Factorial: 120, Factors: 2

*/