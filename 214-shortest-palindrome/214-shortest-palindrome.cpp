class Solution {
public:
    void calc_lps(string &str, vector<int> &LPS){

	int N = str.size();

	int len =0;
	int idx =1;
	LPS[0]=0;


	while(idx < N){

		if(str[idx]==str[len]){

			LPS[idx] = len+1;
			len++;
			idx++;
		}else{

			if(len==0){
				LPS[idx] = 0;
			idx++;
			}else{
				len= LPS[len-1];
			}

		}
	}//wwhile
}
    
    string shortestPalindrome(string s) {
 
        int N = s.size();
        string rev(s);
        reverse(rev.begin(), rev.end());
        
        string str = s+'$'+rev;
        
        vector<int>  LPS(2*N+1);
        
        calc_lps(str, LPS);

        /*
        for(char ele: str){
            cout<<ele<<" ";
        }cout<<endl;
        
        for(int ele: LPS){
            cout<<ele<<" ";
        }cout<<endl;
        */
            
        cout<<rev.substr(0, N-LPS[2*N])+s;
        
        return rev.substr(0, N-LPS[2*N])+s;
        
    }
};