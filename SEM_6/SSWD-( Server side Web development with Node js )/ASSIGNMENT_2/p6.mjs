import { EventEmitter } from 'events';

class MyEmitter extends EventEmitter {}

const myEmitter = new MyEmitter();

myEmitter.on('greet', (name) => {
  console.log(`Hello, ${name}! This is from ES6-style events.`);
});

myEmitter.emit('greet', 'Charlie');
myEmitter.emit('greet', 'Diana');

/*
Hello, Charlie! This is from ES6-style events.
Hello, Diana! This is from ES6-style events.
*/