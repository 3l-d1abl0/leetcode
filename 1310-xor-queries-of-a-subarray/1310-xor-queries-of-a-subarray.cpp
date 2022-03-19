class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        vector<int> cumX (arr.size());
        cumX[0]=arr[0];
        
        
        vector<int> ans;
        
        for(int i=1; i<arr.size(); i++){
            
            cumX[i] = arr[i]^cumX[i-1];
        }
        
        
        for(int i=0; i<queries.size(); i++){
            
            if(queries[i][0] == 0){
                ans.push_back(cumX[queries[i][1]] ^ 0);
            }else{
                ans.push_back(cumX[queries[i][1]] ^ cumX[queries[i][0]-1]);
            }
        }
                                                         
                                                         
        return ans; 
    }
};