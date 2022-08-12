class Solution {
public:
    int trap(vector<int>& h) {
        
        int N = h.size();
        
        vector<int> l(N);
        vector<int> r(N);
        
        l[0] = h[0];
        r[N-1] = h[N-1];
        
        for(int i=1; i<N; i++){
            
            l[i] = max(l[i-1], h[i]);    
            r[N-i-1] = max(r[N-i], h[N-i-1]);
        }
        
        
        int cnt =0;
        for(int i=0; i<N; i++)
            cnt+= min(l[i], r[i]) - h[i];
        
        return cnt;
    }
};