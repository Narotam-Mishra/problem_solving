
// create a function that takes an array like object with numeric keys and tranforms it into a proper array. For Example - {0:'a', 1:'b', 2:'c', lenght:3} into ['a', 'b', 'c']


// Trnsform array like object into actual array

// Approach - 1 (using Array.from() method)

let obj = { 0: "a", 1: "b", 2: "c", length: 3 };

function transformIntoArray1(obj) {
  const newArr = Array.from(obj, (v, i) => v);
  console.log(newArr);
}

transformIntoArray1(obj);


// Approach - 2 (using for in loop)

function transformIntoArray2(obj){
    let len = obj.length || 0;
    const resultArr = [];

    for(let id=0; id<len; id++){
        if(id in obj){
            resultArr.push(obj[id]);
        }
    }
    return resultArr;
}

console.log(transformIntoArray2(obj));

