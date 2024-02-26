class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        
        unordered_map<char, int> mp;
        
        int l_idx=0, r_idx=0;
        int N = s.size(), max_len =0;
        
        
        for(r_idx=0; r_idx<N; r_idx++){
            
            if(mp.find(s[r_idx]) != mp.end()){
                
                
                //get it last index and chec if it lies inside the range
                //if yes create new range
                int old_idx = mp[s[r_idx]];
                
                l_idx = max(l_idx, old_idx+1);
            }
            
            max_len = max(max_len, r_idx-l_idx+1);
            //cout<<l_idx<<" "<<r_idx<<" "<<max_len<<endl;
            mp[s[r_idx]] = r_idx;
            
        }
        
        
        return max_len;
    }
};