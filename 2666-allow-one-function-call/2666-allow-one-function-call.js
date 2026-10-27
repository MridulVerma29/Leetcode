/**
 * @param {Function} fn
 * @return {Function}
 */
var once = function(fn) {
    let hasbeencalled=false;
    let result;
    return function(...args){
        if(!hasbeencalled){
            result=fn(...args);
            hasbeencalled=true;
            return result;
        }
        else{
            return undefined;
        }
    }
};

/**
 * let fn = (a,b,c) => (a + b + c)
 * let onceFn = once(fn)
 *
 * onceFn(1,2,3); // 6
 * onceFn(2,3,6); // returns undefined without calling fn
 */
