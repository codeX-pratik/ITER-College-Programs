import express from "express";
import { palindrome } from "./p2.js";
import { quadratic } from "./p3.js";

const app = express();

app.get("/palindrome", palindrome);
app.get("/quadratic", quadratic);


app.listen(3000, () => {
  console.log("Server is running on port 3000");
});