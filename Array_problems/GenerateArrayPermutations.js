
// generate different pertutations of array

function generateArrayPermutations(arr){
    const res = [];

    function permuteArray(current, remaining){
        if(remaining.length === 0){
            res.push(current);
        }else{
            for(let i = 0; i < remaining.length; i++){
                let nextCurr = current.concat(remaining[i]);
                let nextRemaining = remaining.slice(0,i).concat(remaining.slice(i + 1));
                permuteArray(nextCurr, nextRemaining);
            }
        }
    }

    permuteArray([], arr);
    // console.log(res);
    // for(let i = 0; i < res.length; i++){
    //     console.log(res[i]);
    // }
    return res;
}

module.exports = generateArrayPermutations;

// let arr = [3,5,1,2];
// generateArrayPermutationa(arr);