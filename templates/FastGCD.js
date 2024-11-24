
function findGCD(a, b) {
    if (b === 0) return a;
    return findGCD(b, a % b);
}