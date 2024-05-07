
// Design Generic Tree (n-Ary Tree)

// TreeNode class represents a node in the generic tree
class TreeNode{
    constructor(value){
        this.value = value;
        this.children = [];
    }
}

class GenericTree{
    constructor(){
        // Initialize the root node as null
        this.root = null;
    }

    // Method to insert a new node with a given value under a node with a given parent value
    insertInTree(value, parentValue){
        const newNode = new TreeNode(value);
        // If no parent value is provided, insert as root
        if(!parentValue){
            if(!this.root){
                // If root doesn't exist, set new node as root
                this.root = newNode;
            }else{
                console.error("Can not insert root node more than once!");
            }
        }else{
            // Find the parent node
            const parentNode = this._findNode(this.root, parentValue);
            if(parentNode){
                // Add the new node as a child of the parent
                parentNode.children.push(newNode);
            }else{
                // Log an error if parent node not found
                console.error("Parent node not found.");
            }
        }
    }

    // Helper method to find a node with a given value in the tree
    _findNode(node, value){
        if(!node) return null;
        if(node.value === value) return node;
        for(const child of node.children){
            const foundNode = this._findNode(child, value);
            if(foundNode) return foundNode;
        }
        return null;
    }

    searchInTree(value){
        return this._searchNode(this.root, value);
    }

    // Helper method to recursively search for a value in the tree
    _searchNode(node, value){
        if(!node){
            // Return false if node is null
            return false;
        }else if(node.value === value){
            // Return true if value is found in the current node
            return true;
        }else{
            for(const child of node.children){
                if(this._searchNode(child, value)){
                    // Return true if value is found in any of the child nodes
                    return true;
                }
            }

            // Return false if value is not found in the node or its children
            return false;
        }
    }
}

const tree = new GenericTree();
tree.insertInTree(1);
tree.insertInTree(2,1);
tree.insertInTree(3,1);
tree.insertInTree(4,2);
tree.insertInTree(5,2);
tree.insertInTree(6,3);
tree.insertInTree(7,3);

console.log(tree.searchInTree(5));
console.log(tree.searchInTree(8));

