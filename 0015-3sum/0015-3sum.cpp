class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        int N = arr.size();
        sort(arr.begin(), arr.end());
        
        
        vector<vector<int> > ans;
        
        for(int i=0; i<N-2; i++){
            
            
            if (i == 0 || (i > 0 && arr[i] != arr[i-1])) {
            
                int l= i+1;
                int r= N-1;


                while(l<r){

                    if(arr[i]+arr[l]+arr[r]==0){
                        ans.push_back({arr[i], arr[l], arr[r]});

                        

                       while(l<r && arr[l]==arr[l+1]) l++;
                       while(l<r && arr[r]==arr[r-1]) r--;
                        
                       l++; r--;

                    }else if(arr[i]+arr[l]+arr[r]<0){
                        l++;
                    }else{
                        r--;
                    }

                }//while
                
            }
        }//for
        
        
        return ans;
    }
};