import util from "util";

const user = {
  id: 101,
  name: "Alice",
  roles: ["admin", "editor"],
  contact: {
    email: "alice@example.com",
    phones: ["123-456-7890", "987-654-3210"],
  },
  metadata: {
    created: new Date(),
    updated: new Date(),
    preferences: {
      theme: "dark",
      notifications: {
        email: true,
        sms: false,
      },
    },
  },
};

const inspected = util.inspect(user, {
  showHidden: false,
  depth: null,
  colors: true,
  compact: false,
});

console.log("User Object Details:\n");
console.log(inspected);

/*

User Object Details:

{
  id: 101,
  name: 'Alice',
  roles: [
    'admin',
    'editor'
  ],
  contact: {
    email: 'alice@example.com',
    phones: [
      '123-456-7890',
      '987-654-3210'
    ]
  },
  metadata: {
    created: 2025-04-06T03:54:54.559Z,
    updated: 2025-04-06T03:54:54.559Z,
    preferences: {
      theme: 'dark',
      notifications: {
        email: true,
        sms: false
      }
    }
  }
}

*/
