class Solution {
public:
    
    int getMaxFrex(unordered_map<char, int> &mp){
        
        int maxx=0;
        for(auto pp: mp){
            maxx= max(pp.second, maxx);
        }
        
        return maxx;
    }
    
    int method1(string &s, int k){
        
        
        unordered_map<char, int> mp;
        
        int lf=0, rt=0, maxx=-1;
        for(rt=0; rt<s.size(); rt++){
            
            
            mp[s[rt]]++;
            
            int currLen = rt-lf+1;
            while((currLen - getMaxFrex(mp)) >k){
                
                mp[s[lf]]--;
                lf++;
                
                currLen = rt-lf+1;
            }
            
            
            maxx = max(maxx, rt-lf+1);
        }//for
        
        return maxx;
    }
    
    int characterReplacement(string s, int k) {
        
        /*  TC: O(26.N)
          SC: O(N)
          */
        //return method1(s, k);
        
        
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
            }
                maxLen = max(maxLen, rt-lf+1);
            
            
        }//for
        
        return maxLen;
    }
};