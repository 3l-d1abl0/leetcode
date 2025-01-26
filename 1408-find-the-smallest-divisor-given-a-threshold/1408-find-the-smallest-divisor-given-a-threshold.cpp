class Solution {
public:
    
    int func(vector<int> &nums, int div){
        int sum =0;
        
        for(int ele: nums)
            sum+=ceil((float)ele/div);
        
        return sum;
    }
    
    int smallestDivisor(vector<int>& nums, int th) {
     
        int l=0, r=*max_element(nums.begin(), nums.end());
        //l=0 will yield , infinite sum, l=1 will yiels sum of nums
        //r=max_ele will result in smalles sum > 0
        
        while(r-l>1){
            
            int mid =  l+(r-l)/2;
            //premise: sum(div) <=threshold
            //int sum = func(nums, mid);
            //cout<<sum<<" "<<mid<<endl;
            if(func(nums, mid)<=th){
                r=mid;
            }else{
                l=mid;
            }
            
        }
        //cout<<":: "<<l<<" "<<r<<endl;
        return r;
    }
};