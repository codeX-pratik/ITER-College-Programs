import { EventEmitter } from 'events';

const eventBus = new EventEmitter();

eventBus.on('message', (from, content) => {
  console.log(`Message received from ${from}: "${content}"`);
});

function sendMessage(from, content) {
  console.log(`Sending message from ${from}...`);
  eventBus.emit('message', from, content);
}

sendMessage('Alice', 'Hello, Bob!');
sendMessage('Bob', 'Hi Alice! How are you?');


/*
Sending message from Alice...
Message received from Alice: "Hello, Bob!"
Sending message from Bob...
Message received from Bob: "Hi Alice! How are you?"
*/