
// Problem link : https://leetcode.com/problems/most-common-word/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let mostCommonWord = function(paragraph, banned) {
    // step 1 : normalize the paragraph
    const normalizedPara = paragraph.toLowerCase().replace(/[^a-z0-9\s]/g, ' ');

    // step 2 : split the paragraph into words by removing extra spaces
    const words = normalizedPara.split(/\s+/);

    // step 3 : convert banned words to a Set for efficient lookup
    const bannedSet = new Set(banned);

    // step 4 : count the frequency of non-banned words
    const wordMap = new Map();
    for(const word of words){
        // ignore empty strings and banned words
        if(word && !bannedSet.has(word)){
            wordMap.set(word, (wordMap.get(word) || 0) + 1);
        }
    }

    // step 5 : find the most frequent word
    let mostFreqWord = '';
    let maxCount = 0;

    for(let [word, count] of wordMap.entries()){
        if(count > maxCount){
            mostFreqWord = word;
            maxCount = count;
        }
    }
    return mostFreqWord;
};

let paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"];

// let paragraph = "a.", banned = [];
console.log(mostCommonWord(paragraph, banned));
