
// Problem link - https://leetcode.com/problems/compare-version-numbers/?envType=daily-question&envId=2025-09-23

let compareVersion = function(version1, version2) {
    // step 1 - split both versions of input strings by dot
    const rev1 = version1.split('.');
    const rev2 = version2.split('.');

    // step 2 - find maximum length of input strings
    // this is to handle cases where versions have different numbers of revisions 
    const maxLen = Math.max(rev1.length, rev2.length);

    // step 3 - compare each revision position from left to right
    for(let i=0; i<maxLen; i++){
        // step 4 - get revision at current position, defaulting to "0" if missing
        const strVer1 = rev1[i] || "0";
        const strVer2 = rev2[i] || "0";

        // step 4 - convert string revision to number for easy comparison
        const num1 = parseInt(strVer1);
        const num2 = parseInt(strVer2);

        // step 5 - compare the current revision numbers
        if(num1 < num2){
            // case 1 - return -1
            return -1;
        }else if(num1 > num2){
            // case 2 - return 1
            return 1;
        }
    }

    // step 6 - All revisions are equal so return 0
    return 0;
};

// const version1 = "1.2", version2 = "1.10";

// const version1 = "1.01", version2 = "1.001";

const version1 = "1.0", version2 = "1.0.0.0";
console.log(compareVersion(version1, version2));