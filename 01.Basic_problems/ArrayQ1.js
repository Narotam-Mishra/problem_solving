// Given an array with some additional properties. WAP in JS to display its original properties only

Array.prototype.extraProp = 'range'

const arr = [2,3,1,5,1];

for(let num in arr){
    console.log(num);
}

// Note - All the additional properties that are added to object using prototype (here Array object) their 'hasOwnProperty' are set to false. so by using 'hasOwnProperty' we can ignore those additional properties.

// display only original property

for(let ele in arr){
    if(arr.hasOwnProperty(ele)){
        console.log(ele);
    }
}