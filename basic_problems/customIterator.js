
// custom Iterator method

function customIterator(arr){
    let idx = 0;

    function next(){
        if(idx === arr.length){
            return{
                value: undefined,
                done: true,
            };
        }

        let nextElement = arr[idx];
        idx++;
        return {
            value: nextElement,
            done: false,
        }
    }
    return {next};
}

let arr = [1,2,3,4,5,6,7];

x = customIterator(arr);

console.log(x.next());
console.log(x.next());
console.log(x.next());
console.log(x.next());
console.log(x.next());
console.log(x.next());
console.log(x.next());
console.log(x.next());
