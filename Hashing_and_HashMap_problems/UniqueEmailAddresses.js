
// Problem link - https://leetcode.com/problems/unique-email-addresses/description/?envType=problem-list-v2&envId=hash-table

let numUniqueEmails = function(emails) {
    // step 1: create a set to store unique emails
    const uniqueEmails = new Set();

    // step 2: iterate over each email
    for(let email of emails){
        // step 3: split the email into local and domain part
        let [local, domain] = email.split('@');

        // step 4 - remove all dots from local part
        local = local.replace(/\./g, '');

        // step 5 - remove everything after '+' from local part
        local = local.split('+')[0];

        // step 6 - add the email to set
        uniqueEmails.add(local + '@' + domain);
    }

    // step 7 - return the size of set
    return uniqueEmails.size;
};

// const emails = ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"];

const emails = ["a@leetcode.com","b@leetcode.com","c@leetcode.com"];
console.log(numUniqueEmails(emails));
