
// Problem link : https://leetcode.com/problems/student-attendance-record-i/description/?envType=problem-list-v2&envId=string&status=TO_DO&difficulty=EASY

let checkRecord = function(s) {
    // step 1: check the number of absences
    const numOfAbsences = s.split('').filter(char => char === 'A').length;

    // if number of absences are 2 or more, the student is not eligible for award
    if(numOfAbsences >= 2){
        return false;
    }

    // step 2: check for 3 or more consecutive 'L's
    if(s.includes('LLL')){
        return false;
    }

    // if both conditions are satisfied, the student is eligible
    return true;
};

// let str = "PPALLP";

let str = "PPALLL";
console.log(checkRecord(str));
