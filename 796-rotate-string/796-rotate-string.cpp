class Solution {
public:
    
    void buildLPS(string &str, vector<int> &LPS){
        
        LPS[0] =0;
        int len =0, idx =1;
        
        
        while(idx<str.size()){
            
            
            if(str[idx]==str[len]){
                
                LPS[idx] = len+1;
                len++;
                idx++;
            }else{
                if(len==0){
                    LPS[idx]=0;
                    idx++;
                }else{
                    len = LPS[len-1];
                }
                
            }
            
        }
        
    }
    
    bool method2(string &str1, string &str2){
        
        vector<int> LPS(str2.size());
        buildLPS(str2, LPS);
        
        
        //perform KMP
        int idx1 =0, idx2=0;
        while(idx1<str1.size()){
            
            if(str1[idx1]==str2[idx2]){
                
                idx1++; idx2++;
                
                if(idx2== str2.size())
                    return true;
                
            }else{
                
                if(idx2==0)
                    idx1++;
                else
                    idx2 = LPS[idx2-1];
                
                
            }
            
        }//while
        
        
        return false;
        
    }
    
    
    bool method1(string &str1, string &str2){
        
        return (str1.find(str2) != string::npos);
        
    }
    
    bool rotateString(string str1, string str2) {
        
        
        if (str1.length() != str2.length())
        return false;
        
        
        string temp = str1 + str1;
        
        //1.STL function
        return method1(temp, str2);
        
        //2.KMP
        //return method2(temp, str2);
        
    }
};