
// Problem link - https://leetcode.com/problems/relative-ranks/description/?envType=problem-list-v2&envId=array

let findRelativeRanks = function(score) {
    // step 1 - create score to original index mapping to track original positions
    const scoreWithIndex = score.map((s,i) => [s,i]);

    // step 2 - sort in descending order of score
    scoreWithIndex.sort((a,b) => b[0] - a[0]);

    // step 3 - create mapping from score to rank
    const scoreToRank = new Map();

    // step 4 - iterate on each score to assign its rank
    for(let i=0; i<scoreWithIndex.length; i++){
        // step 5 - destructure score from `scoreWithIndex` pairs
        const [currentScore] = scoreWithIndex[i];
        // rank is based on 1-based indexing
        const rank = i+1;

        // step 6 - convert rank to appropiate string value
        let rankString = '';
        if(rank === 1){
            rankString = "Gold Medal";
        }else if(rank === 2){
            rankString = "Silver Medal";
        }else if(rank === 3){
            rankString = "Bronze Medal";
        }else{
            rankString = rank.toString();
        }

        scoreToRank.set(currentScore, rankString);
    }

    // step 7 - build result array using original order
    const res = [];
    for(let i=0; i<score.length; i++){
        res.push(scoreToRank.get(score[i]));
    }

    // step 8 - return resultant array `res`
    return res;
};

// const score = [5,4,3,2,1];

const score = [10,3,8,9,4];
console.log(findRelativeRanks(score));