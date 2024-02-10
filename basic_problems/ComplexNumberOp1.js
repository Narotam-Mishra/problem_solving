
class ComplexNumber{
    constructor(real, imag){
        this.real = real;
        this.imag = imag;
    }

    addComplexNumber(cn){
        return `${this.real + cn.real} + i ${this.imag + cn.imag}`;
    }

    multiplyComplexNumber(cn){
        return `${this.real * cn.real - this.imag * cn.imag} + i${this.real * cn.imag + this.imag * cn.real}`
    }
}

const c1 = new ComplexNumber(3,5);
const c2 = new ComplexNumber(4,10);

console.log("Addition of Complex Number:", c1.addComplexNumber(c2));
console.log("Multiplication of Complex Number:", c1.multiplyComplexNumber(c2));
