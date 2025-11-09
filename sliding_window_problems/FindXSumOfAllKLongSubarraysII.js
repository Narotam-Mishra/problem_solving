
// Problem link - https://leetcode.com/problems/find-x-sum-of-all-k-long-subarrays-ii/

/**
 * AVL Tree Node
 */
class TreeNode {
    constructor(freq, val) {
        this.freq = freq;
        this.val = val;
        this.left = null;
        this.right = null;
        this.height = 1;
    }
}

/**
 * AVL Tree Set with custom comparator
 */
class AVLSet {
    constructor(compare) {
        this.root = null;
        this.compare = compare;
        this.size = 0;
    }
    
    getHeight(node) {
        return node ? node.height : 0;
    }
    
    getBalance(node) {
        return node ? this.getHeight(node.left) - this.getHeight(node.right) : 0;
    }
    
    updateHeight(node) {
        if (node) {
            node.height = 1 + Math.max(this.getHeight(node.left), this.getHeight(node.right));
        }
    }
    
    rotateRight(y) {
        const x = y.left;
        const T2 = x.right;
        
        x.right = y;
        y.left = T2;
        
        this.updateHeight(y);
        this.updateHeight(x);
        
        return x;
    }
    
    rotateLeft(x) {
        const y = x.right;
        const T2 = y.left;
        
        y.left = x;
        x.right = T2;
        
        this.updateHeight(x);
        this.updateHeight(y);
        
        return y;
    }
    
    insert(freq, val) {
        this.root = this._insert(this.root, freq, val);
        this.size++;
    }
    
    _insert(node, freq, val) {
        if (!node) {
            return new TreeNode(freq, val);
        }
        
        const cmp = this.compare({freq, val}, {freq: node.freq, val: node.val});
        
        if (cmp < 0) {
            node.left = this._insert(node.left, freq, val);
        } else {
            node.right = this._insert(node.right, freq, val);
        }
        
        this.updateHeight(node);
        
        const balance = this.getBalance(node);
        
        // Left Left Case
        if (balance > 1 && this.compare({freq, val}, {freq: node.left.freq, val: node.left.val}) < 0) {
            return this.rotateRight(node);
        }
        
        // Right Right Case
        if (balance < -1 && this.compare({freq, val}, {freq: node.right.freq, val: node.right.val}) > 0) {
            return this.rotateLeft(node);
        }
        
        // Left Right Case
        if (balance > 1 && this.compare({freq, val}, {freq: node.left.freq, val: node.left.val}) > 0) {
            node.left = this.rotateLeft(node.left);
            return this.rotateRight(node);
        }
        
        // Right Left Case
        if (balance < -1 && this.compare({freq, val}, {freq: node.right.freq, val: node.right.val}) < 0) {
            node.right = this.rotateRight(node.right);
            return this.rotateLeft(node);
        }
        
        return node;
    }
    
    remove(freq, val) {
        this.root = this._remove(this.root, freq, val);
        this.size--;
    }
    
    _remove(node, freq, val) {
        if (!node) return null;
        
        const cmp = this.compare({freq, val}, {freq: node.freq, val: node.val});
        
        if (cmp < 0) {
            node.left = this._remove(node.left, freq, val);
        } else if (cmp > 0) {
            node.right = this._remove(node.right, freq, val);
        } else {
            // Node to be deleted found
            if (!node.left || !node.right) {
                node = node.left || node.right;
            } else {
                // Node with two children: get inorder successor
                let minNode = node.right;
                while (minNode.left) {
                    minNode = minNode.left;
                }
                
                node.freq = minNode.freq;
                node.val = minNode.val;
                node.right = this._remove(node.right, minNode.freq, minNode.val);
            }
        }
        
        if (!node) return null;
        
        this.updateHeight(node);
        
        const balance = this.getBalance(node);
        
        // Left Left Case
        if (balance > 1 && this.getBalance(node.left) >= 0) {
            return this.rotateRight(node);
        }
        
        // Left Right Case
        if (balance > 1 && this.getBalance(node.left) < 0) {
            node.left = this.rotateLeft(node.left);
            return this.rotateRight(node);
        }
        
        // Right Right Case
        if (balance < -1 && this.getBalance(node.right) <= 0) {
            return this.rotateLeft(node);
        }
        
        // Right Left Case
        if (balance < -1 && this.getBalance(node.right) > 0) {
            node.right = this.rotateRight(node.right);
            return this.rotateLeft(node);
        }
        
        return node;
    }
    
    getMin() {
        if (!this.root) return null;
        let node = this.root;
        while (node.left) {
            node = node.left;
        }
        return {freq: node.freq, val: node.val};
    }
    
    getMax() {
        if (!this.root) return null;
        let node = this.root;
        while (node.right) {
            node = node.right;
        }
        return {freq: node.freq, val: node.val};
    }
    
    isEmpty() {
        return this.size === 0;
    }
    
    getSize() {
        return this.size;
    }
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} x
 * @return {number[]}
 */
let findXSum = function(nums, k, x) {
    const n = nums.length;
    const res = [];
    
    // Comparator: compares two {freq, val} objects
    const compare = (a, b) => {
        if (a.freq !== b.freq) return a.freq - b.freq;
        return a.val - b.val;
    };
    
    // Track frequency of each element in current window
    const freq = new Map();
    
    // Main set: stores top x elements (larger elements)
    const mainSet = new AVLSet(compare);
    
    // Secondary set: stores remaining elements
    const secondarySet = new AVLSet(compare);
    
    // Sum of (frequency * value) for all elements in mainSet
    let currentSum = 0;
    
    // Insert a {freq, val} pair into appropriate set
    const insertPair = (p) => {
        if (mainSet.getSize() < x) {
            // Main set has room, insert directly
            mainSet.insert(p.freq, p.val);
            currentSum += p.freq * p.val;
        } else {
            const smallest = mainSet.getMin();
            if (compare(p, smallest) > 0) {
                // New element is larger than smallest in main set
                mainSet.remove(smallest.freq, smallest.val);
                currentSum -= smallest.freq * smallest.val;
                
                mainSet.insert(p.freq, p.val);
                currentSum += p.freq * p.val;
                
                secondarySet.insert(smallest.freq, smallest.val);
            } else {
                // Element goes to secondary set
                secondarySet.insert(p.freq, p.val);
            }
        }
    };
    
    // Remove a {freq, val} pair from sets
    const removePair = (p) => {
        // Check if in main set by comparing with min/max
        const inMainSet = mainSet.getSize() > 0 && 
            compare(p, mainSet.getMin()) >= 0 && 
            compare(p, mainSet.getMax()) <= 0;
        
        if (inMainSet) {
            mainSet.remove(p.freq, p.val);
            currentSum -= p.freq * p.val;
            
            // Promote largest from secondary set
            if (!secondarySet.isEmpty()) {
                const largest = secondarySet.getMax();
                secondarySet.remove(largest.freq, largest.val);
                mainSet.insert(largest.freq, largest.val);
                currentSum += largest.freq * largest.val;
            }
        } else {
            secondarySet.remove(p.freq, p.val);
        }
    };
    
    // Sliding window approach
    let left = 0, right = 0;
    
    while (right < n) {
        // Remove old frequency pair if element already exists
        const currentFreq = freq.get(nums[right]) || 0;
        if (currentFreq > 0) {
            removePair({freq: currentFreq, val: nums[right]});
        }
        
        // Increment frequency and insert new pair
        freq.set(nums[right], currentFreq + 1);
        insertPair({freq: currentFreq + 1, val: nums[right]});
        
        // When window reaches size k, record result and slide
        if (right - left + 1 === k) {
            res.push(currentSum);
            
            // Remove leftmost element from window
            const leftFreq = freq.get(nums[left]);
            removePair({freq: leftFreq, val: nums[left]});
            
            // Update frequency map
            if (leftFreq === 1) {
                freq.delete(nums[left]);
            } else {
                freq.set(nums[left], leftFreq - 1);
                insertPair({freq: leftFreq - 1, val: nums[left]});
            }
            
            left++;
        }
        
        right++;
    }
    
    return res;
};

// const nums = [1,1,2,2,3,4,2,3], k = 6, x = 2;

const nums = [3,8,7,8,7,5], k = 2, x = 2;
console.log(findXSum(nums, k, x));