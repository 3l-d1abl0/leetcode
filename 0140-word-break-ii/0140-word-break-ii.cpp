class Solution {
public:
    vector<string> method1(int idx, unordered_map<int, vector<string>> &memo, string &s, vector<string> &wd){

        //End of String
        vector<string> ans;
        if(idx==s.size()){
            ans.push_back("");
            return ans;
        }
        
        if(memo.find(idx) != memo.end())
            return memo[idx];
        
        vector<string> result;
        for(int i=0; i<wd.size(); i++){

            int len = wd[i].size();

            if(wd[i].compare(s.substr(idx, len))==0){

                vector<string> subResult = method1(idx+len, memo, s, wd);

                for(const string &sub: subResult){
                    if(sub.empty()){//previous call was valid and returned empty string
                        result.push_back(wd[i]);
                    }else{
                        result.push_back(wd[i]+" "+sub);
                    }
                }//for subResult
            }

        }//for

        return memo[idx] = result;
        

    }
    

    vector<string> method2(string s, vector<string>& wd){

            int N = s.size();

            vector <vector<string>> dp(N+1);
            dp[N] = {""}; 

            for(int idx=N-1; idx>=0; idx--){


                    vector<string> result;
                    for(int i=0; i<wd.size(); i++){

                        int len = wd[i].size();

                        if(idx + len <= N && wd[i].compare(s.substr(idx, len))==0 ){

                            vector<string> subResult = dp[idx+len];

                            for(const string &sentence: subResult){
                                dp[idx].push_back(wd[i]+(sentence.empty()?"":" "+sentence));
                            }//for subResult
                        }

                    }//for i

            }//for idx


            return dp[0];
    }


    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        //TC -  O(n.k. m)
        //unordered_map<int, vector<string>> memo;
        //vector<string> ans;
        //return method1(0, memo, s, wordDict);
        

        //TC - O(n×W),  SC - O(n×W) W is the number of words in the dictionary
        return method2(s, wordDict);
    }
};