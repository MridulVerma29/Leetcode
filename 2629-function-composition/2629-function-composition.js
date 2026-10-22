/**
 * @param {Function[]} functions
 * @return {Function}
 */
var compose = function(functions) {
    if(functions.length===0){
        return function(x){
            return x
        }
    }
    return functions.reduceRight(function(prevfn,nextfn){
        return function(x){
            return nextfn(prevfn(x));
        }
    })
    return function(x) {
        
    }
};

/**
 * const fn = compose([x => x + 1, x => 2 * x])
 * fn(4) // 9
 */