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
    
    
    vector<vector<int>> method1(int n, int k){
        
        //Include + Exclude
        vector<int> comb;
        vector<vector<int>> ans;
        recur(n, k, comb, ans);
        
        return ans;
    }
    
    void iter(int idx, int n, int k, vector<int> &comb, vector<vector<int>> &ans){
     
        
        if(comb.size()==k){
            ans.push_back(comb);
        }
        
        if(idx>n)
            return;
        
        for(int i=idx; i<=n; i++){
            comb.push_back(i);
            iter(i+1, n, k, comb, ans);
            comb.pop_back();
        }
        
    }
    
    vector<vector<int>> method2(int n, int k){
        
        vector<int> comb;
        vector<vector<int>> ans;
        
        
        iter(1, n, k, comb, ans);
        
        return ans;    
    }
    
    
    vector<vector<int>> combine(int n, int k) {
        
        
        //Method1 - Recursion
        //return method1(n, k);
        
        
        //Method2 - Iteration
        return method2(n, k);

    }
};