const getVal = (n) =>
  new Promise((res, rej) => {
    setTimeout(() => {
      if (n % 2 === 0) {
        res(`${n} is even`);
      } else {
        rej(`${n} is odd`);
      }
    }, 1000);
  });

getVal(3).then(console.log).catch(console.log);

/*

value return asynchronously after 1 second
3 is odd

*/