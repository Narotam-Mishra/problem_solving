
// Problem link - https://leetcode.com/problems/design-a-food-rating-system/?envType=daily-question&envId=2025-09-17

class CustomMaxHeap {
    constructor(compare) {
        this.data = [];
        this.compare = compare;
    }

    _swap(i, j) {
        [this.data[i], this.data[j]] = [this.data[j], this.data[i]];
    }

    _parent(i) { return Math.floor((i - 1) / 2); }
    _left(i) { return 2 * i + 1; }
    _right(i) { return 2 * i + 2; }

    push(val) {
        this.data.push(val);
        this._heapifyUp(this.data.length - 1);
    }

    _heapifyUp(i) {
        while (i > 0) {
            let p = this._parent(i);
            if (this.compare(this.data[i], this.data[p]) < 0) break;
            this._swap(i, p);
            i = p;
        }
    }

    pop() {
        if (this.data.length === 0) return null;
        const top = this.data[0];
        const end = this.data.pop();
        if (this.data.length > 0) {
            this.data[0] = end;
            this._heapifyDown(0);
        }
        return top;
    }

    _heapifyDown(i) {
        let n = this.data.length;
        while (true) {
            let l = this._left(i), r = this._right(i), largest = i;
            if (l < n && this.compare(this.data[l], this.data[largest]) > 0) largest = l;
            if (r < n && this.compare(this.data[r], this.data[largest]) > 0) largest = r;
            if (largest === i) break;
            this._swap(i, largest);
            i = largest;
        }
    }

    peek() {
        return this.data.length ? this.data[0] : null;
    }
}

/**
 * @param {string[]} foods
 * @param {string[]} cuisines
 * @param {number[]} ratings
 */
let FoodRatings = function(foods, cuisines, ratings) {
    this.foodRating = new Map();   // food -> rating
    this.foodCuisine = new Map();  // food -> cuisine
    this.cuisineHeap = new Map();  // cuisine -> MaxHeap

    const compare = (a, b) => {
        // rating desc, food name asc
        if (a.rating !== b.rating) return a.rating - b.rating;
        return b.food.localeCompare(a.food);
    };

    for (let i = 0; i < foods.length; i++) {
        let food = foods[i], cuisine = cuisines[i], rating = ratings[i];
        this.foodRating.set(food, rating);
        this.foodCuisine.set(food, cuisine);

        if (!this.cuisineHeap.has(cuisine)) {
            this.cuisineHeap.set(cuisine, new CustomMaxHeap(compare));
        }
        this.cuisineHeap.get(cuisine).push({ rating, food });
    }
};

/** 
 * @param {string} food 
 * @param {number} newRating
 * @return {void}
 */
FoodRatings.prototype.changeRating = function(food, newRating) {
    let cuisine = this.foodCuisine.get(food);
    this.foodRating.set(food, newRating);

    // push new entry (lazy deletion of old one)
    this.cuisineHeap.get(cuisine).push({ rating: newRating, food });
};

/** 
 * @param {string} cuisine
 * @return {string}
 */
FoodRatings.prototype.highestRated = function(cuisine) {
    let heap = this.cuisineHeap.get(cuisine);

    while (true) {
        let top = heap.peek();
        // check if top is valid
        if (this.foodRating.get(top.food) === top.rating) {
            return top.food;
        }
        heap.pop(); // discard stale entry
    }
};

function runTest(){
    const foods1 = ["kimchi", "miso", "sushi", "moussaka", "ramen", "bulgogi"];
    const cuisines1 = ["korean", "japanese", "japanese", "greek", "japanese", "korean"];
    const ratings1 = [9, 12, 8, 15, 14, 7];
    
    const foodRatings1 = new FoodRatings(foods1, cuisines1, ratings1);
    
    console.log("Highest rated Korean food:", foodRatings1.highestRated("korean")); // Expected: kimchi
    console.log("Highest rated Japanese food:", foodRatings1.highestRated("japanese")); // Expected: ramen
    
    foodRatings1.changeRating("sushi", 16);
    console.log("After changing sushi rating to 16:");
    console.log("Highest rated Japanese food:", foodRatings1.highestRated("japanese")); // Expected: sushi
    
    foodRatings1.changeRating("ramen", 16);
    console.log("After changing ramen rating to 16 (tie with sushi):");
    console.log("Highest rated Japanese food:", foodRatings1.highestRated("japanese")); // Expected: ramen
}

runTest();