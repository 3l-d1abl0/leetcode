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
    
    bool hasCommon(string &s1, string& s2) {
        
        vector<int> arr(26, 0);
        
        for(char &ch : s1) {
            if(arr[ch-'a'] > 0)
                return true;
            arr[ch-'a']++;
        }
        
        for(char &ch : s2) {
            if(arr[ch-'a'] > 0)
                return true;
        }
        
        return false;
    }
    
    
    int solve(int idx, vector<string>& arr, string concatString, int N, unordered_map<string, int> &mp) {
        
        if(idx >= N)
            return concatString.length();
        
        if(mp.find(concatString) != mp.end())
            return mp[concatString];
        
        int include = 0;
        int exclude = 0;
        if(hasCommon(arr[idx], concatString)) {
            exclude = solve(idx+1, arr, concatString, N, mp);//skip
        } else {
            exclude = solve(idx+1, arr, concatString, N, mp);//skip
            concatString += arr[idx];
            include = solve(idx+1, arr, concatString, N, mp);//include
        }
        
        return mp[concatString] = max(include, exclude);
    }
    
    int maxLength(vector<string>arr) {
        
        
        //1. Method 1 - DFS
        /*
            the overall time complexity of the code is O(2^n * L), where:
            n is the number of strings in arr
            L is the total length of all strings in arr
        */
        //return check(0, "", arr);
        
        //2. Method2 - Exclude-Include
        string concatString = "";
        unordered_map<string, int> mp;
        int N = arr.size();
        
        return solve(0, arr, concatString, N, mp);
        
        
    }
};