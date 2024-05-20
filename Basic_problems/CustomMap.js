// CustomMap - create your own customMap() method that mimics map() method behaviour.

const arr = [1,4,5,7,9];

function customMap(arr, callback){
    const res = [];

    for(let i=0; i<arr.length; i++){
        let val = callback(arr[i],i);
        res.push(val);
    }

    return res;
}

const ans = customMap(arr, (num) => {
    return num*num;
})

console.log(arr);
console.log(ans);
