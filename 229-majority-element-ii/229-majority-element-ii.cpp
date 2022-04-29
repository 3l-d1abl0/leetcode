class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int maj1 = INT_MIN, maj2=INT_MIN;
        int c1=0, c2=0;
        
        
        for(int ele: nums){
            if(maj1== ele){
                c1++;
            }else if(maj2== ele){
                c2++;
            }else if(c1==0){
                maj1= ele;   c1=1;
            }else if(c2==0){
                maj2= ele; c2=1;
            }else {
                c1--;
                c2--;
            }
        }
        
        
        c1=0, c2=0;
        for(int ele: nums){
            if(ele==maj1)   c1++;
            else if (ele == maj2) c2++;
        }
        
        //cout<<maj1<<" "<<maj2<<endl;
        vector<int> me;
        
        if(c1 > nums.size()/3) me.push_back(maj1);
        
        if(c2 > nums.size()/3) me.push_back(maj2);
        
        
        return me;
    }
};