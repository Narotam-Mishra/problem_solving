
/*

Given `data` in array of objects, Group the names of person by age

const data = [
  { id: 1, name: "Arjun", age: 23 },
  { id: 2, name: "Brian", age: 27 },
  { id: 3, name: "Cyril", age: 25 },
  { id: 4, name: "Daniel", age: 23 },
  { id: 5, name: "Jacob", age: 27 }
]

Output should be like this 

{
  23: ["Arjun", "Daniel"],
  27: ["Brian", "Jacob"],
  25: ["Cyril"] 
}

*/

const data = [
  { id: 1, name: "Arjun", age: 23 },
  { id: 2, name: "Brian", age: 27 },
  { id: 3, name: "Cyril", age: 25 },
  { id: 4, name: "Daniel", age: 23 },
  { id: 5, name: "Jacob", age: 27 },
];

function groupResult(){
    const res = {};
    for(const person of data){
        if(!res[person.age]){
            res[person.age] = [];
        }
        res[person.age].push(person.name);
    }
    return res;
}

let ans = groupResult();
console.log(ans);