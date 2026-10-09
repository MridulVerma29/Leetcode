/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
class counter{
    constructor(init){
        this.init=init;
        this.presentcount=init;
    }
    increment(){
        this.presentcount+=1;
        return this.presentcount;
    }
    decrement(){
        this.presentcount-=1;
        return this.presentcount;
    }
    reset(){
        this.presentcount=this.init;
        return this.presentcount;
    }
}
var createCounter = function(init) {
    return new counter(init);
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */