import express from "express";

const app = express();
const PORT = 3000;

function greetUser(name, callback) {
  const greeting = `Hello, ${name}!`;
  callback(greeting);
}

app.get("/greet/:name", (req, res) => {
  const name = req.params.name;

  greetUser(name, (message) => {
    res.send(message);
  });
});

app.listen(PORT, () => {
  console.log(`Server running at http://localhost:${PORT}`);
});

/*
http://localhost:3000/greet/Pratik
Hello, Pratik!
*/