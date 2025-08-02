class RLEIterator {

    int idx;
    int size;
    vector<int> arr;
    int currentHop;
public:
    RLEIterator(vector<int>& encoding) {
        
        this->size = encoding.size();
        this->idx =0;
        this->arr= encoding;
        this->currentHop = this->arr[this->idx];
    }
    
    int next(int n) {
    
        while(this->idx< this->size){

            if(n<=this->currentHop){
                this->currentHop -= n;
                return arr[this->idx+1];
            }

            n -=this->currentHop;
            this->idx +=2;

            if(this->idx< this->size)
                this->currentHop = this->arr[this->idx];
        }

        return -1;
    }
};

/**
 * Your RLEIterator object will be instantiated and called as such:
 * RLEIterator* obj = new RLEIterator(encoding);
 * int param_1 = obj->next(n);
 */