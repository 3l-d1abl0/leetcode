class Solution {
public:
    
    int MOD = 1e9+7;
    
    
    void oddEven(vector<int> &oe, int num){
        
        while(num > 0) {
            oe.push_back( num%2);
            num/= 2;
        }
    }
    
    void powerSum(vector<int> &ps, vector<int> &oe){
        
        for(int i = 0; i < oe.size(); i++) {
            if(oe[i] == 1) {
                ps.push_back(pow(2, i));
            }
        }
    }
    
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        
        vector<int> oe;
        oddEven(oe, n);
        
        vector<int> ps;
        powerSum(ps, oe);

        
        /*for(int ele: oe){
            cout<<ele<<" ";
        }cout<<endl;
        for(int ele: ps){
            cout<<ele<<" ";
        }cout<<endl;*/

        vector<int> ans;
        
        for(auto row : queries) {
            long long int prod = 1;
            for(int i = row[0]; i <= row[1]; i++) {
                prod = ((prod%MOD) * (ps[i] % MOD))%MOD;
            }
            ans.push_back((int)(prod %MOD));
            
        }

        return ans;
    }
    
};