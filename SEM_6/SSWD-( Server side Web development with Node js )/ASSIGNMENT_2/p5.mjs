import express from 'express';

const app = express();
const PORT = 3000;

app.get('/', (req, res) => {
    const n = req.query.n;

    if (n && !isNaN(n)) {
        const r = parseInt(n);
        const vol = (4 / 3) * Math.PI * Math.pow(r, 3);
        const result = `The_volume_of_a_sphere_with_radius_${r}_is_${vol.toFixed(2)}`;
        res.redirect(`/result/${encodeURIComponent(result)}`)
    }
});

app.get('/result/:result', (req, res) => {
    const result = req.params.result.replace(/_/g, ' ');
    res.send(`Result: ${result}`);
})

app.listen(PORT, () => {
  console.log(`Server is running on http://localhost:${PORT}`);
});

/*

http://localhost:3000/?n=2
http://localhost:3000/result/The_volume_of_a_sphere_with_radius_2_is_33.51

Result: The volume of a sphere with radius 2 is 33.51

*/