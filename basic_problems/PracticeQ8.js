// Predict Output

const obj = {
    a:1,
    b:2,
    c:3
};

Object.keys(obj).forEach(key => {
    obj[key] *= 2;
})

console.log(obj);