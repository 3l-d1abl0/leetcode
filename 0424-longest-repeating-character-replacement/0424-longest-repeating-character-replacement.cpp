class Solution {
public:
    int characterReplacement(string s, int k) {
        
        
        int maxLen = INT_MIN;
        int maxFreq = INT_MIN;
        unordered_map<int,int> mp;
        
        int rt=0, lf=0;
        for(rt=0; rt < s.size(); rt++){
            
            mp[s[rt]]++;
            
            maxFreq = max(maxFreq, mp[s[rt]]);
            
            int replaceLen = (rt-lf+1)-maxFreq;
            if(replaceLen > k){ //cant replace as > k, hence make window small
                mp[s[lf]]--;
                lf++;
            }else{
                maxLen = max(maxLen, rt-lf+1);
            }
            
            
        }//for
        
        return maxLen;
    }
};