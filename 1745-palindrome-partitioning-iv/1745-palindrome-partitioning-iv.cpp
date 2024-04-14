class Solution {
public:
    
    int ispalindrome(int i, int j, string &str) {

          while (i<=j) {

              if(str[i] != str[j])
                return false;

            i++; j--;

          }

          return  true;
    }

    int recur(int idx, int part, string &str, int K, vector<vector<int>> &memo) {

        //1 partition remaining - char if its palin
        if(part==K-1){
            
            //If partition cannot be made
            if(idx==str.size())
                return false;
            
            return ispalindrome(idx, str.size()-1, str);
        }
        
        
        if(idx==str.size())
            return false;

        if(memo[idx][part]!=-1)
            return memo[idx][part];

        int made = false;
        for (int i= idx; i<str.size(); i++) {

            
            if (ispalindrome(idx, i, str)) {
                made = made || recur(i+1, part+1, str, K, memo);
            }

        }


        return memo[idx][part] = made;
    }
    
    bool checkPartitioning(string str) {
     
        //1. Memoization
        int K = 3;
        int N = str.size();
        vector<vector<int>> memo(N, vector<int> (K, -1));
        
        return recur(0, 0, str, K, memo);
        
        
    }
};