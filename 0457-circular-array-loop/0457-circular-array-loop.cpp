class Solution {
public:
    
        int nextIdx(bool dir, int idx, vector<int> &nums){
        
        bool curr_dir = nums[idx]>=0?true:false;
        
        //opp dirn - can't have both forward and backward dirn in  list
        if(curr_dir != dir)
            return -1;
        
        int next_idx = (idx + nums[idx]+nums.size())%nums.size();
        
        //Single Element Cycle
        if(next_idx==idx)
            return -1;
        
        return next_idx;
    }
    
    bool circularArrayLoop(vector<int>& nums) {
        
        //true ->fwd
        //false ->bk
        //check cycle for each Index
        for(int idx=0; idx<nums.size(); idx++){

            //original direction of the list            
            bool dir = nums[idx]>=0?true:false;
            int slow=idx, fast=idx;
            
            while(1){

                //slow takes 1 steps
                slow = nextIdx(dir, slow, nums);
                //fast takes 2 steps
                fast = nextIdx(dir, fast, nums);
                if(fast !=-1)
                    fast = nextIdx(dir, fast, nums);

                if(slow==-1 || fast ==-1 || fast ==slow)
                    break;
                
                //cout<<slow<<" "<<fast<<endl;
            }
            
            if(fast==slow && slow!=-1)
                return true;
            
        }
        
        return false;
    }
    
};