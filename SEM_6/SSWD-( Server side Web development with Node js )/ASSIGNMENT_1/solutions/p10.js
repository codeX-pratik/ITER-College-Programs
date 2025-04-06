import express from "express";

const app = express();
const PORT = 8185;

function isPalindrome(num) {
  const str = num.toString();
  return str === str.split("").reverse().join("");
}

app.get("/", (req, res) => {
  const number = req.query.number;

  if (number && !isNaN(number)) {
    const num = parseInt(number);
    const result = isPalindrome(num)
      ? `${num}-is-a-palindrome`
      : `${num}-is-not-a-palindrome`;

    res.redirect(`/result/${result}`);
  } else {
    res.send("Please provide a valid number using ?number=121 in the URL.");
  }
});

app.get("/result/:message", (req, res) => {
  const message = req.params.message.replace(/-/g, " ");
  res.send(`Result: ${message}`);
});

app.listen(PORT, () => {
  console.log(`Server is running at http://localhost:${PORT}`);
});

/*

http://localhost:8185/?number=121
http://localhost:8185/result/121-is-a-palindrome

Result: 121 is a palindrome

*/
