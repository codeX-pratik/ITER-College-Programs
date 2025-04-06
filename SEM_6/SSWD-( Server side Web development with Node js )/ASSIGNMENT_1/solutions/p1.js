import { getFullName, calculateAge, ageAfterYears } from "./mymodule.js";
import readline from "readline";

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

rl.question("Enter First Name: ", (firstName) => {
    rl.question("Enter Middle Name (or press enter to skip): ", (middleName) => {
        rl.question("Enter Last Name: ", (lastName) => {
            rl.question("Enter Date of Birth (DD-MM-YYYY): ", (dob) => {
                const fullName = getFullName(firstName, middleName, lastName);
                const currentAge = calculateAge(dob);
                const futureAge = ageAfterYears(currentAge, 24);

                console.log(`Full Name: ${fullName}`);
                console.log(`Current Age: ${currentAge}`);
                console.log(`Age After 24 Years: ${futureAge}`);

                rl.close();
            });
        });
    });
});

/*
Enter First Name: pratik
Enter Middle Name (or press enter to skip): kumar
Enter Last Name: muduli
Enter Date of Birth (DD-MM-YYYY): 02-11-2003
Full Name: pratik kumar muduli
Current Age: 21
Age After 24 Years: 45
*/