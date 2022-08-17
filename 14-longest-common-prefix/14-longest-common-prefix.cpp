class Solution {
public:
    
    
    string method1(vector<string>& strs){
        
        //trake string at 0 as possible prefix
        int j=0;
        int i=1;
        for(; j<strs[0].size(); j++){
                
            for(i=1; i<strs.size(); i++){
                
                
                if(j<strs[0].size() && j<strs[i].size() && strs[0][j]== strs[i][j]){
                    //cout<<strs[0][j]<<" "<<strs[i][j]<<endl;
                    continue;
                }
                
                  //  cout<<j<<endl;
                    return strs[0].substr(0, j);
                
                
            }// for j
            
        }//for i
        
        if (j == strs[0].size()-1)
            return strs[0];
        else
            return strs[0].substr(0,j+1);
        
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() ==0)
            return "";
        
        //take strin1 as prefix, iterate over others
        return method1(strs);   //N* size of smallest str
        
        
        
    }
};