class Solution {
public:
    int MOD = 1e9+7;
    int minn;
    
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<long int> left;
        vector<long int> right;
        
        for(int i=0; i<arr.size(); i++){
            left.push_back(i+1);
            right.push_back(arr.size()-i);
        }
        
        stack<int> stLeft;
        stack<int> stRight;
        
        
        for(int i=0; i<arr.size(); i++){
            
            while(!stLeft.empty() && arr[stLeft.top()] >arr[i]){
                stLeft.pop();
            }
            
            if(stLeft.empty())
                left[i] = i+1;
            else
                left[i] = i-stLeft.top();
            
            stLeft.push(i);
            
            //Right           
            while(!stRight.empty() && arr[stRight.top()] > arr[i]){
                right[stRight.top()] = i - stRight.top();
                stRight.pop();
            }
            
            stRight.push(i);
            
        }
        
        int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum = (sum + (left[i]* arr[i]* right[i])%MOD)%MOD;
        }
        
        
        
        return sum;
    }
    
};
