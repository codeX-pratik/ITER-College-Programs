import fs from 'fs';

fs.readdir('./', (err, files) => {
    if(!err) {
        console.log(`Total files in the directory: ${files.length}`);
    } else {
        console.error('Error reading directory:', err);
    }
})

/*
Total files in the directory: 14
*/