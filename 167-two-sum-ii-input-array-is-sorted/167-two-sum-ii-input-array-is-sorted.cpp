class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
     
        int N = arr.size();
        int l =0, r= N-1;
        
        
        while(l<r){
            if(target==arr[l]+arr[r])
                return vector<int> {l+1, r+1};
            else if (target < arr[l]+arr[r])
                r--;
            else
                l++;
        }
        
        
        return vector<int> {};
        
    }
};