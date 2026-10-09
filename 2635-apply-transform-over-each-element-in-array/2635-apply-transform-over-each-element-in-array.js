/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var map = function(arr, fn) {
    const transformedarr= [];
    let index=0;
    for(const element of arr){
        transformedarr[index]=fn(element,index);
        index++;
    }
    return transformedarr;
};