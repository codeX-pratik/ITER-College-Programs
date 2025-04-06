import fs from 'fs';

const data = await fs.promises.readFile('test.txt', 'utf-8');
console.log(data);

/*

Hello there
This is me !!

*/