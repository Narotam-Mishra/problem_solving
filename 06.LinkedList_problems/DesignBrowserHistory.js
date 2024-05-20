
// Problem link - https://leetcode.com/problems/design-browser-history/

/**
 * @param {string} homepage
 */
let BrowserHistory = function(homepage) {
    // Initialize the current page with the homepage
    this.page = {
        url: homepage, // URL of currnet page
        back: null,    // reference to the previous page
        next: null,    // reference to the next page
    };
};

/** 
 * @param {string} url
 * @return {void}
 */
BrowserHistory.prototype.visit = function(url) {
    // Create a new page object for the visited URL
    this.page.next = {
        url,             // set URL of the new page
        back: this.page, // set URL of the previous page
        next: null          // there is no next page yet
    };
    // update current page to the new page
    this.page = this.page.next;
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.back = function(steps) {
    // Traverse back through the linked list of pages
    // reaching the beginning of the history or the specified number of steps
    while(this.page.back && steps){
        // Move to the previous page
        this.page = this.page.back;
        // Decrement the steps counter
        steps--
    }

    // return current page URL
    return this.page.url;
};

/** 
 * @param {number} steps
 * @return {string}
 */
BrowserHistory.prototype.forward = function(steps) {
    // Traverse forward through the linked list of pages
    // reaching the end of the history or the specified number of steps
    while(this.page.next && steps){
        // Move to the next page
        this.page = this.page.next;
        // Decrement the steps counter
        steps--;
    }
    // return current page URL
    return this.page.url;
};

// test above code
// Create a new browser history with a homepage
let history = new BrowserHistory("leetcode.com");

// Visit some pages
history.visit("google.com");
history.visit("facebook.com");
history.visit("youtube.com");

// Navigate back two steps
console.log(history.back(2)); // Output: google.com
console.log(history.back(1))
console.log(history.forward(2))
console.log(history.back(3))
console.log(history.forward(7))

// Visit another page
history.visit("hackerrank.com");