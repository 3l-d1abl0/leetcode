class Solution {
public:
    
    int check(int idx, string concatenatedStr, vector<string> &arr){
        
        
        //check if the concatenated string has duplicate characters
        unordered_set<char> st(concatenatedStr.begin(), concatenatedStr.end());
        
        if(concatenatedStr.length() != st.size())   //if duplicate Characters
            return 0;
        
        if(idx == arr.size())
            return concatenatedStr.length();
        
        //cout<<": "<<concatenatedStr<<endl;
        int ans = concatenatedStr.length();
        for(int i=idx; i<arr.size(); i++){
            
            ans = max(ans, check(i+1, concatenatedStr+arr[i], arr));
        }
        
        return ans;
    }
    
    int maxLength(vector<string>arr) {
        
        
        
        return check(0, "", arr);
        
    }
};