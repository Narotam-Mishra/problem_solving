// Using filter and reduce method, write a JS function to take arry of objects with properties name and value and return the sum of the object whose name starts with 'A' or 'a'

let arrObj = [
    {
        name: "Alice",
        value: 21,
    },
    {
        name: "Aryan",
        value: 27,
    },
    {
        name: "Bob",
        value: 24,
    },
    {
        name: "alok",
        value: 31,
    },
    {
        name: "Arun",
        value: 41,
    },
    {
        name: "Cann",
        value: 51,
    },
    {
        name: "Andrew",
        value: 46,
    }
];

function findSum(arrObj){
    // filter array objects whose name start with 'A' or 'a'
    const filteredObj = arrObj.filter(obj => obj.name && (obj.name[0] === 'A' || obj.name[0] === 'a'));
    
    // then find the sum of all values
    const sum = filteredObj.reduce((acc,obj) => {
        return acc + obj.value
    },0)

    return sum;
}

console.log(findSum(arrObj));