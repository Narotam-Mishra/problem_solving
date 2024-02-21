
class Electronics{
    getCategory(){
        return 'Electronics';
    }
}

class Camera extends Electronics{
    getSpecs(){
        console.log('Specs of Camers is....');
    }
}

const c1 = new Camera();
console.log(c1.toString());