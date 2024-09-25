class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        
        int LIM = 2;
        int lf=0;
        int type =0;
        
        unordered_map<int, int> mp;
        int maxx = INT_MIN;
        for(int rt=0; rt<fruits.size(); rt++){
            
            mp[fruits[rt]]++;
            
            while(mp.size()>LIM){
                
                mp[fruits[lf]]--;
                if(mp[fruits[lf]]==0){
                    mp.erase(fruits[lf]);
                }
                
                lf++;
                
            }//while
            
            maxx = max(maxx, rt-lf+1);
        }//for
        
        
        return maxx;
    }
    
    
};