
// functional constructor example - 1

function Product(n, p, d, i){
    this.name = n;
    this.price = p;
    this.desc = d;
    this.image = i;

    this.dispalyDetails = function() {
        console.log(`Product Name: ${this.name}, Product Price: ${this.price}, Product Description: ${this.desc}, Product Image: ${this.image}`);
    }
}

const p1 = new Product("i-Phone16", 89760, "Apple iPhone", "Some_Image");
console.log(p1);
p1.dispalyDetails();