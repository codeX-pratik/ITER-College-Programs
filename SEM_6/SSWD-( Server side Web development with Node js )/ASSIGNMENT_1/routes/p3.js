const findRoots = (a, b, c) => {
    const discriminant = b * b - 4 * a * c;
    let root1, root2;

    if (discriminant > 0) {
        root1 = (-b + Math.sqrt(discriminant)) / (2 * a);
        root2 = (-b - Math.sqrt(discriminant)) / (2 * a);
        return { type: "Real and Distinct", root1, root2 };
    } else if (discriminant === 0) {
        root1 = root2 = -b / (2 * a);
        return { type: "Real and Equal", root1, root2 };
    } else {
        const realPart = (-b / (2 * a)).toFixed(2);
        const imaginaryPart = (Math.sqrt(-discriminant) / (2 * a)).toFixed(2);
        return {
            type: "Complex (Imaginary)",
            root1: `${realPart} + ${imaginaryPart}i`,
            root2: `${realPart} - ${imaginaryPart}i`
        };
    }
}

export const quadratic = (req, res) => {
    const { a, b, c } = req.query;
    if (!a || !b || !c) {
        return res.status(400).json({ error: "Please provide values for a, b, and c." });
    }

    const A = parseFloat(a);
    const B = parseFloat(b);
    const C = parseFloat(c);

    if (A === 0) {
        return res.status(400).json({ error: "Coefficient 'a' cannot be zero." });
    }

    const result = findRoots(A, B, C);
    res.json({ equation: `${A}x² + ${B}x + ${C} = 0`, result });
}