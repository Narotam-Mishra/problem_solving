
// Problem link - https://leetcode.com/problems/defanging-an-ip-address/description/?envType=problem-list-v2&envId=string

let defangIPaddr = function(address) {
    return address.replaceAll('.', "[.]");
};

// const address = "1.1.1.1";

const address = "255.100.50.0";
console.log(defangIPaddr(address));
