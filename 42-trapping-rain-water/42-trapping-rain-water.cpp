class Solution {
public:
    int trap(vector<int>& h) {
        
        int N = h.size();
        vector<int> lmax(N, -1);
        vector<int> rmax(N, -1);
        
        int lm = -1e6;
        int rm = -1e6;
        for(int i=0; i<N; i++){
            
            lm = max(lm, h[i]);
            
            if(lm == h[i])
                lmax[i] = -1;
            else
                lmax[i] = lm;
            
            //find rignt max
            rm = max(rm, h[N-i-1]);
            if(rm == h[N-i-1])
                rmax[N-i-1] = -1;
            else
                rmax[N-i-1] = rm;
            
        }//for
        
        
        /*for(int i=0; i<N; i++){
            cout<<lmax[i]<<" ";
        }cout<<endl;
        
        for(int i=0; i<N; i++){
            cout<<rmax[i]<<" ";
        }cout<<endl;*/
        
        int cnt =0;
        for(int i=0; i<N; i++){
            
            if(lmax[i]==-1 || rmax[i]==-1) continue;
            
            cnt +=(min(lmax[i], rmax[i]) - h[i]);
        }
        
        return cnt;
    }
};