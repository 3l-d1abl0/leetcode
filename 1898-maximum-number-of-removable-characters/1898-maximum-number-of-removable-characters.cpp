class Solution {
public:
    
    int func(vector<int> &skip, string &s, string &p, int mid){
        
        int idx=0;
        for(int i=0; i<s.size() && idx<p.size(); i++){
            
            if(skip[i] <= mid){
                //cout<<i<<" .. "<<endl;
                continue;
            }
            
            //cout<<s[i]<<" == "<<p[idx]<<endl;
            if(s[i]==p[idx]){
                idx++;
            }
        }
        
        return idx;
    }
    
    
    int maximumRemovals(string s, string p, vector<int>& rem) {
        
        int l=-1, r=rem.size();
        
        int psz = p.size();
        
        vector<int > skip(s.size(), INT_MAX);
        for(int i=0; i<rem.size(); i++){
            skip[rem[i]] = i;
        }
        
        /*for(int ele: skip){
            cout<<ele<<" ";
        }cout<<endl;
        */
        
        while(r-l>1){
            
            int mid = l+(r-l)/2;
            //cout<<l<<" "<<"k= "<<mid<<" "<<r<<endl;
            int ans = func(skip, s, p, mid);
            //cout<<ans<<endl<<endl;
            if( ans == psz){
                l=mid;
            }else{
                r=mid;
            }
            
        }//while
        
        //cout<<l<<" "<<r<<endl;
        return r;
        
    }
};