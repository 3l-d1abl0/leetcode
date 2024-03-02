class Solution {
public:
    int numberOfSubstrings(string s) {
  
        unordered_map<char, int> map;
        
        int lf =0, count =0;
        for(int rt=0; rt<s.size(); rt++){
            
            map[s[rt]]++;
            while(map['a']>=1 && map['b']>=1 && map['c']>=1){
                
                count += (s.size()-rt);
                
                map[s[lf]]--;
                lf++;
            }
            
        }//for
        
        
        return count;
        
    }
};