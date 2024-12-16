
// Sort array elements using setTimeout() method

const arr = [1, 10, 3, 5, 6, 2, 4, 9];

function sorting(num){
    setTimeout(() => {
        console.log(num);
    }, num);
}

arr.forEach(num => sorting(num));