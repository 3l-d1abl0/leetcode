class Solution {
public:
    int N;
    //vector<int> BIT(50001,0);
    vector<int> BIT = vector<int>(50001);
    
    void update(int idx, int val){
        
        for(idx=idx+1; idx<N; idx+= idx & (-idx))
            BIT[idx]+=val;
    }
    
    void updateRange(int l, int r, int val){
        
        update(l, val);
        update(r+1, -val);
        
    }
    
    int sum(int idx){
        
        int ans =0;
        for(idx=idx+1; idx>0; idx -= idx & (-idx))
            ans +=BIT[idx];
        
        return ans;
    }
    
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        
        N = s.size()+1;
        
        //reset the BIT
        //memset(&BIT[0], 0, sizeof(BIT[0]) * N);
        
        
        for(auto &row: shifts){
            
            if(row[2]!=1) row[2]=-1;
            updateRange(row[0], row[1], row[2]);
        }
        
        
        for(int i=0; i<s.size(); i++){
            //cout<<sum(i)<<" ";
            s[i] = 'a'+ (s[i]-'a'+ (sum(i)%26) + 26) % 26;
        }
        
        return s;
    }
};