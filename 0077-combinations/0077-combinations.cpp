class Solution {
public:
    
    void recur(int n, int k, vector<int> &comb, vector<vector<int>> &ans){
        
        
        if(k==0){
            ans.push_back(comb);
            return;
        }
        
        if(n==0)
            return;
        
        //Include
        comb.push_back(n);
        recur(n-1, k-1, comb, ans);
        comb.pop_back();
        
        //Exclude
        recur(n-1, k, comb, ans);
        
    }
    
    vector<vector<int>> combine(int n, int k) {
        
        //Include + Exclude
        vector<int> comb;
        vector<vector<int>> ans;
        recur(n, k, comb, ans);
        
        return ans;
    }
};