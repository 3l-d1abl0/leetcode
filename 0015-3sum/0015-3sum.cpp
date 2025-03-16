class Solution {
public:
    
    vector<vector<int>> method2(vector<int> &arr){
        
        int N = arr.size();
        set< vector<int> > triplets;
        
        for(int i=0; i<N; i++){
            
            
            unordered_set<int> hashMap;
            for(int j=i+1; j<N; j++){
                
                int sum = - (arr[i]+arr[j]);
                if( hashMap.find(sum) != hashMap.end() ){
                    
                    vector<int> triplet = {arr[i], arr[j], sum};
                    sort(triplet.begin(), triplet.end());
                    
                    triplets.insert(triplet);
                }
                
                hashMap.insert(arr[j]);
                
            }
            
            
        }//for i

            
        vector<vector<int>> ans (triplets.begin(), triplets.end());
        
        return ans;
        
    }
    
        
        vector<vector<int>> method3(vector<int> &arr){
        
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
        

    
    
    vector<vector<int>> threeSum(vector<int>& arr) {
        
        //1. Three nested loop with a set to store unique triplet
        //return method1(arr);
        
        /*2. TC: O(n^2) + O(1) (hashMap) + O(1)(log(3)) 
            SC: O(N)+ O(no of unique triplets)*2
        
        */
        
        //return method2(arr);
        
        
        /*
        */
        return method3(arr);
        //O(NlogN)+O(N2),
        
    }
};