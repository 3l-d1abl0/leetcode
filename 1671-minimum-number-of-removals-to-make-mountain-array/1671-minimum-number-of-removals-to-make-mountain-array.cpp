class Solution {
public:
    
int lbs(vector<int> &arr,int n ){
        
  
   /* Allocate memory for LIS[] and initialize LIS values as 1 for
      all indexes */
    vector<int> lis(n,1);
  
   /* Compute LIS values from left to right */
   for (int i = 1; i < n; i++)
      for (int j = 0; j < i; j++)
         if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            lis[i] = lis[j] + 1;
  
   /* Allocate memory for lds and initialize LDS values for
      all indexes */
    vector<int> lds(n, 1);
  
   /* Compute LDS values from right to left */
   for (int i = n-2; i >= 0; i--)
      for (int j = n-1; j > i; j--)
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
            lds[i] = lds[j] + 1;
  
  
   /* Return the maximum value of lis[i] + lds[i] - 1*/
   int maxx = 0;
   for (int i = 1; i < n-1; i++){
    
       if(lis[i]>1 && lds[i]>1)
         maxx = max( maxx, lis[i] + lds[i] - 1);
   }
    
   return n-maxx;
}
    
    
    int minimumMountainRemovals(vector<int>& nums) {
        
        int N = nums.size();
        return lbs(nums, N);
    }
};