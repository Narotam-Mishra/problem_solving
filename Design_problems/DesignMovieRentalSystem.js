
// Problem link - https://leetcode.com/problems/design-movie-rental-system/description/?envType=daily-question&envId=2025-09-21

/**
 * @param {number} n
 * @param {number[][]} entries
 */
let MovieRentingSystem = function(n, entries) {
    // map for movie mapping with price and shop ordered pairs
    // movie -> Set of "price,shop" strings for fast lookup and removal
    this.availableMap = new Map();
    
    // map for movie -> sorted array of {price, shop} for efficient search
    this.availableSorted = new Map();
    
    // sorted array of rented movies as "price,shop,movie" strings
    this.rentedMovies = [];
    this.rentedSet = new Set(); // for O(1) existence check
    
    // map for movie mapping with shop and price
    // movie -> Map(shop -> price)
    this.movieShopPriceMap = new Map();
    
    // initialization
    for (const entry of entries) {
        const shop = entry[0];
        const movie = entry[1];
        const price = entry[2];
        
        // store movie -> Set of "price,shop" strings
        if (!this.availableMap.has(movie)) {
            this.availableMap.set(movie, new Set());
            this.availableSorted.set(movie, []);
        }
        
        const key = `${price},${shop}`;
        this.availableMap.get(movie).add(key);
        this.availableSorted.get(movie).push({price, shop});
        
        // store movie -> Map(shop -> price)
        if (!this.movieShopPriceMap.has(movie)) {
            this.movieShopPriceMap.set(movie, new Map());
        }
        this.movieShopPriceMap.get(movie).set(shop, price);
    }
    
    // sort all available movies by price, then shop
    for (const [movie, arr] of this.availableSorted) {
        arr.sort((a, b) => {
            if (a.price !== b.price) return a.price - b.price;
            return a.shop - b.shop;
        });
    }
};

/** 
 * @param {number} movie
 * @return {number[]}
 */
MovieRentingSystem.prototype.search = function(movie) {
    const res = [];
    const availableSet = this.availableMap.get(movie);
    const availableArr = this.availableSorted.get(movie);
    
    if (!availableSet || !availableArr) return res;
    
    let cnt = 0;
    for (const item of availableArr) {
        const key = `${item.price},${item.shop}`;
        if (availableSet.has(key)) {
            res.push(item.shop);
            cnt++;
            if (cnt >= 5) break;
        }
    }
    
    return res;
};

/** 
 * @param {number} shop 
 * @param {number} movie
 * @return {void}
 */
MovieRentingSystem.prototype.rent = function(shop, movie) {
    // get price from movieShopPriceMap - O(1) lookup
    const price = this.movieShopPriceMap.get(movie).get(shop);
    
    // remove from available set - O(1)
    const key = `${price},${shop}`;
    this.availableMap.get(movie).delete(key);
    
    // add to rented movies with binary search insertion
    const rentedKey = `${price},${shop},${movie}`;
    this.rentedSet.add(rentedKey);
    
    // binary search insertion to maintain sorted order
    const item = {price, shop, movie};
    let left = 0, right = this.rentedMovies.length;
    
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        const midItem = this.rentedMovies[mid];
        
        if (midItem.price < price || 
            (midItem.price === price && midItem.shop < shop) ||
            (midItem.price === price && midItem.shop === shop && midItem.movie < movie)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    this.rentedMovies.splice(left, 0, item);
};

/** 
 * @param {number} shop 
 * @param {number} movie
 * @return {void}
 */
MovieRentingSystem.prototype.drop = function(shop, movie) {
    // get price from movieShopPriceMap - O(1) lookup
    const price = this.movieShopPriceMap.get(movie).get(shop);
    
    // add back to available set - O(1)
    const key = `${price},${shop}`;
    this.availableMap.get(movie).add(key);
    
    // remove from rented movies
    const rentedKey = `${price},${shop},${movie}`;
    this.rentedSet.delete(rentedKey);
    
    // binary search removal
    let left = 0, right = this.rentedMovies.length;
    
    while (left < right) {
        const mid = Math.floor((left + right) / 2);
        const midItem = this.rentedMovies[mid];
        
        if (midItem.price < price || 
            (midItem.price === price && midItem.shop < shop) ||
            (midItem.price === price && midItem.shop === shop && midItem.movie < movie)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    
    if (left < this.rentedMovies.length && 
        this.rentedMovies[left].price === price && 
        this.rentedMovies[left].shop === shop && 
        this.rentedMovies[left].movie === movie) {
        this.rentedMovies.splice(left, 1);
    }
};

/**
 * @return {number[][]}
 */
MovieRentingSystem.prototype.report = function() {
    const res = [];
    let cnt = 0;
    
    for (const item of this.rentedMovies) {
        res.push([item.shop, item.movie]);
        cnt++;
        if (cnt >= 5) break;
    }
    
    return res;
};

// main runner function to test the MovieRentingSystem
function runTests() {
    // test case
    const entries = [
        [0, 1, 5], [0, 2, 6], [0, 3, 7],
        [1, 1, 4], [1, 2, 7], [2, 1, 5]
    ];
    
    // constrctor call
    const system = new MovieRentingSystem(3, entries);
    
    // test search
    console.log("Search movie 1:", system.search(1)); // [1, 0, 2]
    console.log("Search movie 2:", system.search(2)); // [0, 1]
    console.log("Search movie 17:", system.search(17)); // []
    
    // test rent
    system.rent(0, 1); // Rent movie 1 from shop 0
    system.rent(1, 2); // Rent movie 2 from shop 1
    
    // test report
    console.log("Report:", system.report()); // [[1, 2], [0, 1]]
    
    // test drop
    system.drop(1, 2); // Return movie 2 to shop 1
    
    // test search after drop
    console.log("Search movie 2 after drop:", system.search(2)); // [0, 1]
    
    // test report after drop
    console.log("Report after drop:", system.report()); // [[0, 1]]
}

// run the tests
runTests();