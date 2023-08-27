class Solution {
public:
    
    int memo[11][2][2][11][11][21];
    
    int solve(string str, int k, int idx, bool last, int digit_sum_mod, int even_count, int odd_count, bool started){
        
        if(idx== str.size()){
            
            if(even_count==odd_count && digit_sum_mod==0 && even_count!=0){
                //cout<<curr<<" "<<digit_sum_mod<<" "<<even_count<<" : "<<odd_count<<endl;
                return 1;
            }else
                return 0;
        }
        
        if(memo[idx][last][started][even_count][odd_count][digit_sum_mod]!=-1)
            return memo[idx][last][started][even_count][odd_count][digit_sum_mod];
        
        int ans =0;
        int limit = last ? str[idx]-'0': 9;
        
        for(int di =0; di<=limit; di++){
            
            bool hasStarted = started || di>0;
            
            int even = ( hasStarted && (di%2==0) );
            int odd = ( hasStarted && (di%2==1) );
            
            
                
    ans+= solve(str, k, idx+1, last && di==limit, (digit_sum_mod*10+di)%k, even_count+even, odd_count+odd, hasStarted );

            
        }//for
        
        
        return memo[idx][last][started][even_count][odd_count][digit_sum_mod] = ans;
        
    }
    
    int numberOfBeautifulIntegers(int low, int high, int k) {
        
        string hstr = to_string(high);
        memset(memo, -1, sizeof(memo));
        
        //str, idx, last, dig_sum_mod, even_count, odd_count
        int ans1 = solve(hstr, k, 0, true, 0, 0, 0, false);
        
        //cout<<"============"<<endl;
        
        string lstr = to_string(low-1);
        memset(memo, -1, sizeof(memo));
        int ans2 = solve(lstr, k, 0, true, 0, 0, 0, false);
        
        
        //cout<<ans1<<" :: "<<ans2<<endl;
        return ans1-ans2;
    }
};