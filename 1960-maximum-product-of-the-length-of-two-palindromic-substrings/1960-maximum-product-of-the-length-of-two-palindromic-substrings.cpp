class Solution {
public:
    
    int palinCheck(string &str){
        
        int i=0, j= str.size()-1;
        
        
        while(i<j){
                
            if(str[i]!=str[j])
                return false;
            
            i++; j--;
        }
        
        
        return true;
    }
    
    long long method1(string &s){
        
        int N = s.size();
        
        unordered_map<int, int> palins;
        for(int mask=1; mask<(1<<N); mask++){
            
            string str;
            
            int j =0;
            
            while(j<N && (mask&(1<<j))==0) //skip zeros
                j++;
            
            while(j<N && (mask&(1<<j))!=0){ //Gather 1s
                str.push_back(s[j]); 
                j++;
            }
            
            while(j<N && (mask&(1<<j))==0) //skip zeros
                j++;
            
            if(j==N && str.size() !=0)            
                if(palinCheck(str)){

                    //cout<<str<<" "<<mask<<" "<<str.size()<<endl;
                    palins.insert({mask, str.size()});
                }
        }//for mask
        
        
        int res =0;
        for(auto p1: palins){
            
            for(auto p2: palins){
                    
                //cout<<p1.first<<" "<<p2.first<<endl;
                if( (p1.first & p2.first) ==0 )
                    res = max(res, p1.second*p2.second);
            }
        }
        
        
        
        return res;
    }
    
    
    long long method2(string &s){
        
        //only odd length palins

        int N = s.size();

        vector<int> P(N, 0);
        int C = 0, R = 0;

        for (int i = 0; i < N; i++) {

            // Expand around i
            int mirror = 2 * C - i;
            if (i < R) {
                P[i] = min(R - i, P[mirror]);
            }

            //cout<<"#####"<<endl;
            // Expand manually
            while (i  + P[i] < N && i - P[i] >= 0 && s[i + P[i]] == s[i - P[i]]) {
                P[i]++;
            }

            //cout<<"#######"<<endl;
            // Update C and R
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }//for

        // Find the maximum length and start index
        /*int max_len = 0, start = 0;
        for (int i = 0; i < N; i++) {
            cout<<P[i]<<" ";
        }
        
        cout<<endl;
        */
        
        //will contain the window from left which migh overlap
        queue<pair<int, int>> q;    //idx, len
        
        vector<int> l2r(N, 0);
        
        for(int i=0; i<N; i++){
            
            while(!q.empty() && q.front().first+q.front().second -1 <i){
                q.pop();
            }
            
            if(i==0)
                l2r[i]=1;
            else{
                if(!q.empty())
                    l2r[i] = max(l2r[i-1], (i-q.front().first)*2 +1);
                else
                    l2r[i] = l2r[i-1];
            }
            
            q.push({i, P[i]});
        }
        

        /*
        for(int ele: l2r)
            cout<<ele<<" ";
        */
        queue<pair<int, int>> q1;
        vector<int> r2l(N, 0);
        for(int i=N-1; i>=0; i--){
            
            while(!q1.empty() && q1.front().first-q1.front().second +1 >i)
                q1.pop();
            
            
            if(i==N-1)
                r2l[i]=1;
            else{
                if(!q1.empty())
                    r2l[i] = max(r2l[i+1], (q1.front().first-i)*2 +1);
                else
                    r2l[i] = r2l[i+1];
            }
            
            q1.push({i, P[i]});
            
        }//for
        
        /*
        cout<<endl;
        for(int ele: r2l)
            cout<<ele<<" ";
        */
        
        
        int max_so_far =0;
        long long int max_prod=0;
        for(int i=0; i<N; i++){
            
            long long int res = 1ll*max_so_far * r2l[i];
            
            max_prod = max(max_prod, res);
            
            max_so_far = max(max_so_far, l2r[i]);
        }
        
        return max_prod;
        
    }
    
    long long maxProduct(string s) {
        
        //1. TLE
        //return method1(s);
        
        
        //2. Manacher
        return method2(s);
    }
};