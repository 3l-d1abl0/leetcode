class Solution {
public:
    int method1(string &s, int k){

        unordered_map<char, int> map;
        
        int maxx =0;
        for(int lf=0; lf<s.size(); lf++){
            
            map.clear();
            int freqCount =0;
            for(int rt=lf; rt<s.size(); rt++){

                //if(map[s[rt]]==k)
                 //   freqCount--;
                   
                map[s[rt]]++;
                   
                if(map[s[rt]]==k)
                    freqCount++;
                   
                 if(map.size() == freqCount)    {
                     maxx = max(maxx, rt-lf+1);
                     //cout<<lf<<" "<<rt<<endl;
                 }
                 
            }//for rt
        }//for lf
        
        return maxx;
    }
    
    int longestSubstring(string s, int k) {
        
        
        return method1(s, k);
    }
    
};