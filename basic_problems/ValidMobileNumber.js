
// Create a regular expression to validate if the given input is valid Indian mobile number or not

function validateMobile(str) {
    const regexMobile = /^(\+91|0)?\s?\d{10}$/;
    return regexMobile.test(str);
}