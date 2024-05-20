

// Object and prototype example-1

function Product(name, price){
    this.name = name;
    this.price = price;
}

const p1 = new Product("i-Phone16", 98766);

Product.prototype.display = function() {
    console.log('Details of product are:', this);
}

p1.display();
console.log(p1.__proto__);