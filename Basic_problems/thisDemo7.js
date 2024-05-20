
// this example - 7 

class Product{
   
    constructor(n,p,d,i){
        this.name = n;
        this.price = p;
        this.description = d;
        this.image = i;
    }
    
    displayProduct(){
        setTimeout(() => {
            console.log(`Product details are: ${this.name}, ${this.description}, ${this.price}, ${this.image}`);
        }, 3000)
    }
}

const pObj1 = new Product("iPhone16", 78900, "Apple Iphone 16", "some image1");
console.log(pObj1);
pObj1.displayProduct();

const pObj2 = new Product("S23", 90900, "Samsung Galaxy S23", "some image2");
console.log(pObj2);
pObj2.displayProduct();
