
class ComplexNumber{
    constructor(real, imaginary){
        this.real = real;
        this.imaginary = imaginary;
    }

    addComplexNumbers(cn1){
        const realNoSum = this.real + cn1.real;
        const imagNoSum = this.imaginary + cn1.imaginary;
        return new ComplexNumber(realNoSum, imagNoSum);
    }

    multiplyComplexNumbers(cn2){
        const realProduct = this.real * cn2.real - this.imaginary * cn2.imaginary;
        const imagProduct = this.real * cn2.imaginary + this.imaginary * cn2. real;
        return new ComplexNumber(realProduct, imagProduct);
    }
}


const c1 = new ComplexNumber(3, 2);
const c2 = new ComplexNumber(1, 4);

const complexSum = c1.addComplexNumbers(c2);
console.log("Sum:", complexSum.real, '+', complexSum.imaginary+'i');

const complexMultiplication = c1.multiplyComplexNumbers(c2);
console.log("Multiplication:", complexMultiplication.real, '+', complexMultiplication.imaginary+'i');
