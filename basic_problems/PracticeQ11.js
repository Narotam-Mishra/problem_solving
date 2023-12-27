
const myObject = {
    key1: 'value1',
    key2: 'value2'
  };
  
  // Check if myObject has a property named 'key1'
  if (myObject.hasOwnProperty('key1')) {
    console.log("myObject has 'key1'");
  } else {
    console.log("myObject does not have 'key1'");
  }
  
  // Check if myObject has a property named 'toString' (inherited from Object prototype)
  if (myObject.hasOwnProperty('toString')) {
    console.log("myObject has 'toString'");
  } else {
    console.log("myObject does not have 'toString'");
  }
  