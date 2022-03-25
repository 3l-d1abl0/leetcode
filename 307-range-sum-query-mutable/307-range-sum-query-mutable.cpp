class NumArray {
public:
    
    vector<int> bit;
    NumArray(vector<int>& nums) {
        bit.resize(nums.size()+1,0);
        
        for(int i=0; i<nums.size(); i++){
            int idx = i+1;
            while(idx<bit.size()){
                bit[idx] += nums[i];
                idx += idx & (-idx);
            }
        }
        
        for(int ele: bit){
            cout<<ele<<" ";
        }cout<<endl;
        
    }
    
    void update(int index, int val) {
        
        int idx = index+1;
        int curr_val = sumRange(index,index);//- sumRange(0, index-1); 
        cout<<"curr_val"<<curr_val<<endl;
        int diff = val- curr_val;
        
        while(idx< bit.size()){
            bit[idx] += diff;
            idx += idx & (-idx);
        }
        
    }
    
    int sumRange(int left, int right) {
        
        right ++;
        left ++;
        
        if(left ==1)
            return query(right);
        else if(left == right)
            return query(right)- query(left-1);
        else
            return query(right) - query(left-1);

            
    }
    
    int query(int idx){
        //sent index is already +1
        int sum =0; 
        while(idx >0){
            sum += bit[idx];
            idx -= idx & (-idx);
        }
        
        return sum;
            
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */