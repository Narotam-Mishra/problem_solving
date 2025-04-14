
// Problem link - https://leetcode.com/problems/split-strings-by-separator/description/?envType=problem-list-v2&envId=string

let splitWordsBySeparator1 = function(words, separator) {
    return words.flatMap(word => word.split(separator)).filter(word => word !== "");
};

let splitWordsBySeparator2 = function (words, separator) {
  // step 1 - store final result in `res`
  const res = [];

  // step 2 - iterate on each word of words
  for (let word of words) {
    // step 3 - split the word  by given separator
    const wordPart = word.split(separator);

    // step 4 - filter out empty strings
    const nonEmptyWordPart = wordPart.filter((word) => word !== "");

    // step 5 - push all non empty parts into `res` array
    res.push(...nonEmptyWordPart);
  }

  // step 6 - return result array `res`
  return res;
};

let splitWordsBySeparator = function(words, separator) {
    // split word by separator and remove empty word
    return words.join(separator).split(separator).filter(Boolean);
};

// const words = ["one.two.three","four.five","six"], separator = ".";

// const words = ["$easy$","$problem$"], separator = "$";

const words = ["|||"], separator = "|";
console.log(splitWordsBySeparator(words, separator));


