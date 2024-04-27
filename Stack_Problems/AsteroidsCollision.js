
// Problem link - https://leetcode.com/problems/asteroid-collision/

let asteroidCollision = function(ast) {
    let stack = [];
    for(let i=0; i<ast.length; i++){
        if(ast[i] > 0 || stack.length === 0){
            // If the current asteroid is positive, it will not collide with any previous asteroids, 
            // so we simply push it onto the stack.
            stack.push(ast[i]);
        }else{
            // If the current asteroid is negative
            while (stack.length > 0 && stack[stack.length-1] > 0 && stack[stack.length-1] < Math.abs(ast[i])){
                // If the top of the stack is positive and has a smaller magnitude than the current asteroid
                // then the top of the stack will be destroyed, 
                // so we pop it and repeat the collision check with the new top
                stack.pop();
            }
            if(stack.length === 0 || stack[stack.length-1] < 0){
                // If the stack is empty or the top of the stack is negative, 
                // then the current asteroid will not collide with any other asteroids, 
                // So, we push the current asteroid onto the stack.
                stack.push(ast[i]);
            }else if(stack.length > 0 && stack[stack.length - 1] === Math.abs(ast[i])){
                // If the top of the stack has the same magnitude as the current asteroid, both asteroids will explode
                stack.pop();
            }
        }
    }
    let res = Array(stack.length);
    for(let i=stack.length-1; i>=0; i--){
        res[i] = stack.pop();
    }
    return res;
};

let ast = [5,10,-5];

// let ast = [10,2,-5];

// let ast = [8,-8];

let ans = asteroidCollision(ast);
console.log(ans);

