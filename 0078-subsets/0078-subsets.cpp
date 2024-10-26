class Solution {
public:
    
    void usingBits(vector<int> &arr, vector<vector<int>> &ans){

        int N = arr.size();
        
        
        for(int counter=0; counter<= (1<<N); counter++){
            vector<int> subset;
            for(int j=0; j<N; j++){

                if( counter & (1<<j))
                    subset.push_back(arr[j]);
            }

            ans.push_back(subset);
        }
        ans.pop_back();
    } 
    
    void usingRecursion(int idx, vector<int> &arr, vector<int> &set, vector<vector<int>> &ans){
        
        if(idx == arr.size()){

            ans.push_back(set);
            return ;
        }

        //1. Include

        set.push_back(arr[idx]);
        usingRecursion(idx+1, arr, set, ans);

        //2. Exclude
        set.pop_back();
        usingRecursion(idx+1, arr, set, ans);
        
    }
    
    
    void usingIteration(int idx, vector<int> &arr, vector<int> subset, vector<vector<int>> &ans){

        ans.push_back(subset);

        if(idx==arr.size())
            return ;


        for(int i=idx; i <arr.size(); i++){

            subset.push_back(arr[i]);

            //Set Starts with [i],
            //all the eleemtns from 0- i-l are excluded
            usingIteration(i+1, arr, subset, ans);

            subset.pop_back();
        }
        
        /*
        
        0,1,2,3,4,5
        
        0               1           2               3           4       5
        \               \           \               \           \
        1,2,3,4,5       2,3,4,5     3,4,5           4,5          5
        
        
        
        
        */

    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans;
        
        //Method1
        //usingBits(nums, ans);
        //return ans;
        
        //Method2
        //vector<int> set;
        //usingRecursion(0, nums, set, ans);
        //return ans;
        
        //Method3
        vector<int> set;
        usingIteration(0, nums, set, ans);
        return ans;
    }
};