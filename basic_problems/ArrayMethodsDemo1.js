
const arr = [2,3,4,1,5];

// forEach() method demo

const res = arr.forEach((ele) => {
    console.log("Array's element is:",ele);
})

console.log(res);

// map() method demo
const res1 = arr.map((e) => {
    console.log("Element is", e);
    return e*e;
})

console.log(res1);


// more examples of map()

const products = [
    {id:1, name:"I-phone16", price:24000},
    {id:2, name:"Macbook", price:84000},
    {id:3, name:"Airpods", price:4000},
]

const modifiedProducts = products.map((product,idx) => {
    console.log(idx);
    return {productId: product.id, name: product.name}
})

console.log(modifiedProducts);
