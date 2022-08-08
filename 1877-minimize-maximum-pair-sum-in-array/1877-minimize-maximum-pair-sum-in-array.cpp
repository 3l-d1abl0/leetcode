class Solution {
public:
    int method1(vector<int> &nums){
        sort(nums.begin(), nums.end());
        
        int l =0, r = nums.size()-1;
        
        int maxx =-1;
        while(l<r){
            
            maxx = max(maxx, nums[l]+nums[r]);
            l++; r--;
        }
        
        
        return maxx;
    }
    int method2(vector<int> &nums){
        
        int minn = INT_MAX, maxx = INT_MIN;
        for(int ele:nums){
            minn = min(minn, ele);
            maxx = max(maxx, ele);
        }
        
        vector<int> vec(maxx-minn+1, 0);
        
        //sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            vec[nums[i]-minn]++;
        }
        
        cout<<endl;
        
        int i=0, j=vec.size()-1;
       // cout<<i<<" "<<j<<endl; 
        
        maxx = INT_MIN;
        
        while(i<=j){
            //cout<<i<<"-"<<j<<endl;
            if(vec[i] ==0 ){
                i++;
                continue;
            }else if(vec[j]==0){
                j--;
                continue;
            }else{
                maxx = max(maxx, i+minn+j+minn);
                vec[i]--;
                vec[j]--;
                
               // cout<<i<<" "<<j<<endl;
            }
        }
        
        return maxx;
        
    }
    int minPairSum(vector<int>& nums) {
        
        //return method1(nums);
        return method2(nums);
        
    }
};