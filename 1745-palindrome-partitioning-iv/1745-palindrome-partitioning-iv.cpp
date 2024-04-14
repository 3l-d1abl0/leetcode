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
    
    
    int ispalindromeRec(int i, int j, string &str, vector<vector<int>> &palin) {

        if(i>j)
            return 0;
        
        if(i==j)
            return 1;
        
        if(abs(i-j)==1)
            return str[i] == str[j];
        
        if(palin[i][j]!=-1)
            return palin[i][j];
        

        if(str[i] != str[j])
                return palin[i][j] = false;

        
        return palin[i][j]=ispalindromeRec(i+1, j-1, str, palin);


    }
    

    int recur(int idx, int part, string &str, int K, vector<vector<int>> &memo, vector<vector<int>> &palin) {

        //1 partition remaining - char if its palin
        if(part==K-1){
            
            //If partition cannot be made
            if(idx==str.size())
                return false;
            
            return ispalindromeRec(idx, str.size()-1, str, palin);
            //return ispalindrome(idx, str.size()-1, str);
        }
        
        
        if(idx==str.size())
            return false;

        if(memo[idx][part]!=-1)
            return memo[idx][part];

        int made = false;
        for (int i= idx; i<str.size(); i++) {

            if(ispalindromeRec(idx, i, str, palin)){
            //if (ispalindrome(idx, i, str)) {
                made = made || recur(i+1, part+1, str, K, memo, palin);
            }

        }


        return memo[idx][part] = made;
    }
    
    bool checkPartitioning(string str) {
     
        //1. Memoization
        int K = 3;
        int N = str.size();
        vector<vector<int>> memo(N, vector<int> (K, -1));
        vector<vector<int>> palin(N, vector<int> (N, -1));
        
        return recur(0, 0, str, K, memo, palin);
        
        
    }
};