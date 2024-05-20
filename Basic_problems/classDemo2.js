
// class example - 2 

class Product{
    // behaviour --> class members / data memebers
    // name;
    // price;
    // description;
    // image;

    constructor(n,p,d,i){
        console.log("logging this before allocting values to object:",this);
        
        this.name = n;
        this.price = p;
        this.description = d;
        this.image = i;
        this.rating = 0;

        console.log("creating an object:",this);
    }

    // behaviour --> class methods / member functions
    buyProduct(){
        console.log("bought a new product");
    }
}

const pObj = new Product();
console.log(pObj);

const pObj1 = new Product("iPhone16", 78900, "Apple Iphone 16", "some image1");
console.log(pObj1);

const pObj2 = new Product("S23", 90900, "Samsung Galaxy S23", "some image2");
console.log(pObj2);