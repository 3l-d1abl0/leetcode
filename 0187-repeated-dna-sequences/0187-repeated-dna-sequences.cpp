class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        
        vector<string> ans;
        //true - freq>1 ans added to ans, freq==1 not added to ans
        unordered_map<string, bool> map;
        
        if(s.size() <10)
            return ans;
        
        
        for(int i=0; i+9<= s.size()-1 ; i++){
            
            string str = s.substr(i, 10);
            
            if(map.find(str) != map.end()){//already exists
                
                if(map[str]==true)  //already in ans
                    continue;
                
                map[str] = true;
                ans.push_back(str);
                
            }else{
                map[str] = false;   //not yet added to ans
            }
            
        }//for
        
        
        return ans;
    }
};