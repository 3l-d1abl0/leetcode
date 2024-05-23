class Solution {
public:
    
    
    int palinCheck(string &str){
        
        int i=0, j= str.size()-1;
        
        
        while(i<j){
                
            if(str[i]!=str[j])
                return false;
            
            i++; j--;
        }
        
        
        return true;
    }
    
    int recur(int idx, string &s, string &s1, string &s2){
        
        
        
        /*
            idx , cant be picked by both (disjoint)
            
            case1:
            idx , added to s1
            idx, added to s2
            
            idx at none (skipping)
        */
        
        
        //Base
        if(idx>= s.size()){
            
                if(palinCheck(s1) && palinCheck(s2)){
                    
                    return s1.size() * s2.size();
                }
                return 0;
        }
        
        
        //case1
        s1.push_back(s[idx]);
        int case1 = recur(idx+1, s, s1, s2);
        s1.pop_back();
        
        
        s2.push_back(s[idx]);
        int case2 = recur(idx+1, s, s1, s2);
        s2.pop_back();
        
        
        int case3 = recur(idx+1, s, s1, s2);
        
        
        return max({case1, case2, case3});
    }
    
    int method1(string &s){
        
        
        string s1= "";
        string s2 ="";
        
        return recur(0, s, s1, s2);
    }
    
    int method2(string &s){
        
        int N = s.size();
        
        unordered_map<int, int> palins;
        for(int mask=1; mask<(1<<N); mask++){
            
            string str;
            for(int j=0; j<N; j++){
                
                if(mask & 1<<j){
                    str.push_back(s[j]);
                }
            }
            
            if(palinCheck(str)){
                
                //cout<<str<<" "<<mask<<" "<<str.size()<<endl;
                palins.insert({mask, str.size()});
            }
        }//for mask
        
        
        int res =0;
        for(auto p1: palins){
            
            for(auto p2: palins){
                    
                //cout<<p1.first<<" "<<p2.first<<endl;
                if( (p1.first & p2.first) ==0 )
                    res = max(res, p1.second*p2.second);
            }
        }
        
        
        
        return res;
    }
    
    int maxProduct(string s) {
        
        
        //1. Recursion
        //return method1(s);
        
        //2. Bitmasking
        return method2(s);
    }
};