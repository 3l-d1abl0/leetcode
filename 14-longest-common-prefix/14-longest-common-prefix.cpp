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
    
    string method2(vector<string> &strs, int l, int r){
        
        if(l==r){
            return strs[l];
        }else{
            
            int mid = l+ (r-l)/2;
            
            string str1 = method2(strs, l, mid);
            string str2 = method2(strs, mid+1, r);
            
            
            return findPrefix(str1, str2);
        }
        
        
    }
    
    
    string findPrefix(string str1, string str2){
        
        if(str1.size()==0 || str2.size()==0)
            return "";
        
        int len = min(str1.size(), str2.size());
        
        for(int i=0; i<len ; i++){
            
            if(str1[i]!= str2[i])
                return str1.substr(0, i);
        }
        
        
        return str1.substr(0, len);
    }
    
    
    string longestCommonPrefix(vector<string>& strs) {
        
        if(strs.size() ==0)
            return "";
        
        //take strin1 as prefix, iterate over others
        //return method1(strs);   //N* size of smallest str
        
        
        return method2(strs, 0, strs.size()-1);
        
        
        
    }
};