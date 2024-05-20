
// class example - 3

class Product{

    constructor(n,p,d,i){
        this.name = n;
        this.desc = d;
        this.price = p;
        this.image = i;
    }

    displayProduct(){
        console.log("Product details:",this);
    }
}

const p1 = new Product("i-Phone15", 98760, "Apple IPhone", "some image1");
// console.log(p1);
p1.displayProduct();