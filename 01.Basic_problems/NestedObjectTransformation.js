
// Question - 4 (from a2 pdf)

//Q.4 Write a function in JS that takes an array of object with nested objects and tranform each nested object's key-value pairs into arrays of [key, value], using map and reduce.

function transformNestedObjects(inputArray) {
  // Use map to iterate over each object in the array
  return inputArray.map((obj) => {
    // Use Object.entries to get an array of [key, value] pairs for each nested object
    const transformedNestedObjects = Object.entries(obj).reduce(
      (acc, [key, value]) => {
        // Check if the value is an object (nested object)
        if (typeof value === "object" && value !== null) {
          // Transform nested object's key-value pairs into arrays of [key, value]
          const nestedArray = Object.entries(value);
          // Append the transformed nested array to the accumulator
          return acc.concat([[key, nestedArray]]);
        } else {
          // If the value is not an object, simply append the [key, value] pair
          return acc.concat([[key, value]]);
        }
      },
      []
    );

    // Return the original object with nested objects transformed
    return Object.fromEntries(transformedNestedObjects);
  });
}

// Example usage:
const inputArray = [{ a: 1, b: { c: 2, d: 3 } }, { x: { y: 4, z: { w: 5 } } }];

const result = transformNestedObjects(inputArray);
console.log(result);
  