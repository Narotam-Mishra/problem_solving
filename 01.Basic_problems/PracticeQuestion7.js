

// Multi Level Grouping

function groupObjectsByKeys(objectsArray, groupByKey, subGroupByKey) {
  return objectsArray.reduce((result, obj) => {
    // Extract the values for grouping
    const groupKey = obj[groupByKey];
    const subGroupKey = obj[subGroupByKey];

    // Check if the group key exists in the result
    if (!result[groupKey]) {
      // If not, initialize an empty object for the group key
      result[groupKey] = {};
    }

    // Check if the sub-group key exists in the group
    if (!result[groupKey][subGroupKey]) {
      // If not, initialize an empty array for the sub-group key
      result[groupKey][subGroupKey] = [];
    }

    // Push the current object into the appropriate sub-group
    result[groupKey][subGroupKey].push(obj);

    return result;
  }, {});
}

// Example usage:
const data = [
  { category: "A", type: "X", value: 1 },
  { category: "B", type: "Y", value: 2 },
  { category: "A", type: "X", value: 3 },
  { category: "B", type: "Z", value: 4 },
];

// Group by 'category' and then within each category, group by 'type'
const result = groupObjectsByKeys(data, "category", "type");

console.log(result);
