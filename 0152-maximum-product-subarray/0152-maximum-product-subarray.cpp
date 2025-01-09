class Solution {
public:
    int maxProduct(vector<int>& arr) {
        
        
        int curr_max =arr[0];
        int curr_min = arr[0];
        int maxx = arr[0];
        
        for(int i=1; i<arr.size(); i++){
            
            int new_max = max(arr[i], max( arr[i]*curr_max, arr[i]*curr_min));
            curr_min = min(arr[i], min( arr[i]*curr_max, arr[i]*curr_min));
            
            curr_max = new_max;
            
            maxx = max(maxx, curr_max);
        }
        
        return maxx;
    }
};