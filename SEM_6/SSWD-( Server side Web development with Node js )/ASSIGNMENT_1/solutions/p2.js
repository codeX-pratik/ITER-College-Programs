import express from "express";
const app = express();

function isPalindrome(str) {
  const cleanedStr = str.replace(/[^a-zA-Z0-9]/g, "").toLowerCase();
  const reversedStr = cleanedStr.split("").reverse().join("");
  return cleanedStr === reversedStr;
}

app.get("/palindrome", (req, res) => {
  const { name } = req.query;

  if (!name) {
    return res.status(400).json({ error: "Please provide a name parameter." });
  }

  const result = isPalindrome(name);
  res.json({
    name: name,
    isPalindrome: result,
    message: result ? "It's a palindrome!" : "Not a palindrome.",
  });
});

app.listen(3000, () => {
  console.log(`Server is running on port http://localhost:3000`);
});

/*

http://localhost:3000/palindrome?name=madam

{
    "name": "madam",
    "isPalindrome": true,
    "message": "It's a palindrome!"
}

*/