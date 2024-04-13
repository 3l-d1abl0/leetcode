class Solution {
public:
    
    bool is_palindrome(string& s, int i, int j)   //check the left part from i to j is palindrome or not
    {
        while(i<j)
        {
            if(s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    
    vector<vector<int>> dp;
    bool solve(string& s, int i, int size, int k)   // variables for memoization are index i and value k
    {
        if(i>size) return false;
        if(dp[i][k] != -1) return dp[i][k];
        if(k == 1)    // when only rightmost part is remaining to check 
        {
            if(is_palindrome(s,i,size))
            return dp[i][k] = true;
            else return dp[i][k] = false;
        }
        
        bool ans = false;
        for(int l = i; l<=size; l++)   //try all valid partitions
        {
            if(is_palindrome(s,i,l))
            {
                ans = ans || solve(s,l+1,size,k-1); 
            }
        }
        
        return dp[i][k] = ans;
    }
    
    bool checkPartitioning(string s) {
        dp = vector<vector<int>> (s.length(), vector<int> (4,-1));
        return solve(s,0,s.length()-1,3);
    }
};