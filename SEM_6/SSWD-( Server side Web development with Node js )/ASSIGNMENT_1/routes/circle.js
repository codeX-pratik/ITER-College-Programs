export const myarea = (radius) => {
    if (radius <= 0) {
        return "Invalid radius";
    }
    return Math.PI * Math.pow(radius, 2);
}

export const mycircumference = (radius) => {
    if (radius <= 0) {
        return "Invalid radius";
    }
    return 2 * Math.PI * radius;
}