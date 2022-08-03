/*class Solution {
public:
    int MOD = 1e9+7;
    int minn;
    
    int sumSubarrayMins(vector<int>& arr) {
        
        vector<int> left;
        vector<int> right;
        
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
        
        long int sum = 0;
        for(int i=0; i<arr.size(); i++){
            sum = (sum + (left[i]* arr[i]* right[i])%MOD)%MOD;
        }
        
        
        
        return sum;
    }
    
};*/


class Solution {
public:
  int sumSubarrayMins(vector<int>& A) {
    stack<pair<int, int>> in_stk_p, in_stk_n;
    // left is for the distance to previous less element
    // right is for the distance to next less element
    vector<long int> left(A.size()), right(A.size());
		
    //initialize
    for(int i = 0; i < A.size(); i++) left[i] =  i + 1;
    for(int i = 0; i < A.size(); i++) right[i] = A.size() - i;
		
    for(int i = 0; i < A.size(); i++){
      // for previous less
      while(!in_stk_p.empty() && in_stk_p.top().first > A[i]) in_stk_p.pop();
      left[i] = in_stk_p.empty()? i + 1: i - in_stk_p.top().second;
      in_stk_p.push({A[i],i});
			
      // for next less
      while(!in_stk_n.empty() && in_stk_n.top().first > A[i]){
        auto x = in_stk_n.top();in_stk_n.pop();
        right[x.second] = i - x.second;
      }
      in_stk_n.push({A[i], i});
    }

    int ans = 0, mod = 1e9 +7;
    for(int i = 0; i < A.size(); i++){
      ans = (ans + A[i]*left[i]*right[i])%mod;
    }
    return ans;
  }
};