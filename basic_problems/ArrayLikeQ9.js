
// Question - 9 from Sanket sir's assignment

function forEachArrayLike(obj, callback) {
  // Check if the object is array-like (has a length property)
  if (typeof obj.length !== "undefined") {
    // Iterate over each property
    for (let i = 0; i < obj.length; i++) {
      // Check if the property exists in the object
      if (Object.prototype.hasOwnProperty.call(obj, i)) {
        // Call the callback with the current element and index
        callback(obj[i], i, obj);
      }
    }
  } else {
    console.error("The provided object is not array-like.");
  }
}

// Example usage:
const arrayLikeObject = { 0: "apple", 1: "banana", 2: "orange", length: 3 };

forEachArrayLike(arrayLikeObject, (element, index) => {
  console.log(`Index: ${index}, Element: ${element}`);
});
