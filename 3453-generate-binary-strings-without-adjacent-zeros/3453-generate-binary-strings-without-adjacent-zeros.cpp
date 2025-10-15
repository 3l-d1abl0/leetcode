class Solution {
public:

    void noAdjZero(string &str,  int last_digit, int n, vector<string> &ans){
        
        if(str.size()==n){
            ans.push_back(str);
            return ;
        }
            
        if(last_digit==0){
             str.push_back('1');
             noAdjZero(str, 1, n, ans);
             str.pop_back();
        }else{

            str.push_back('1');
            noAdjZero(str, 1, n, ans);
            str.pop_back();


            str.push_back('0');
            noAdjZero(str, 0, n, ans);
            str.pop_back();
        }
            
    

        return ;
    }

    vector<string> validStrings(int n) {

       //1. Recursion
	   //vector<vector<int>> memo(n, vector<int>(2, -1));


       vector<string> ans;

       string a="0";
       string b="1";

	   noAdjZero(a, 0, n, ans);
       noAdjZero(b, 1, n, ans);
	   return ans;
	   
        
    }
};