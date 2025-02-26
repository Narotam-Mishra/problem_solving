
// Problem link - https://leetcode.com/problems/unique-email-addresses/description/?envType=problem-list-v2&envId=hash-table

#include<bits/stdc++.h>
using namespace std;

int numUniqueEmails(vector<string>& emails) {
    // step 1 - create a set to store unique email addresses
    unordered_set<string> uniqueEmails;
    
    // step 2 - iterate over each email address
    for(string email : emails){
        string temp = "";
        bool ignore = false;
        bool domain = false;

        // step 3 - iterate over each character of the email address
        for(char c : email){
            if(c == '@'){
                ignore = false;
                domain = true;
            }
            // step 4 - ignore '.' and '+' characters
            if(c == '.' && !domain){
                continue;
            }
            if(c == '+' && !domain){
                ignore = true;
            }
            if(!ignore){
                temp += c;
            }
        }

        // step 5 - insert the email address in the set
        uniqueEmails.insert(temp);
    }

    // step 6 - return the size of the set
    return uniqueEmails.size();
}

int main(){
    // vector<string> emails = {"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    
    vector<string> emails = {"a@leetcode.com","b@leetcode.com","c@leetcode.com"};
    cout<<numUniqueEmails(emails)<<endl;
    return 0;
}