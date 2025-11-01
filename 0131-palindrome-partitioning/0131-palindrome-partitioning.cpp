class Solution {
public:
    
    bool palindrome(string s, int start, int end){
        
        while(start<=end){
            if(s[start++]!=s[end--])
                return false;
        }
        
        return true;
    }
    
    void recur(int idx, string s, vector<vector<string >> &ans, vector<string> &combi){
        
        
        if(idx == s.size()){
            ans.push_back(combi);
            return;    
        }   
        
        
        for(int i=idx; i<s.size(); i++){
        
            //If idx - i is a plaindrone,
            //We have found one Partition,
            if(palindrome(s,idx, i)){
                
                //push [i-idx] to list
                combi.push_back(s.substr(idx, i - idx + 1));
                //now find partitions from rest of the String
                recur(i+1, s, ans, combi);
                combi.pop_back();
                
            }
            
        }//Otherwise just rry to increase the length of the current partition.

            
    }
    
    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> combi;
        
        //1. Method - recursion
        recur(0, s, ans, combi);
        
        return ans;
    }
};