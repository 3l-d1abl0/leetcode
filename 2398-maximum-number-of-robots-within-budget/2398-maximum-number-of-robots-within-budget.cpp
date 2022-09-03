class Solution {
public:
    int maximumRobots(vector<int>& CT, vector<int>& RC, long long budget) {
     
        int N = CT.size();
        int lf =0, rt=0;
        
        vector<long long int> sm(N, 0);
        sm[0]= RC[0];
        for(int i=1; i<N; i++){
            sm[i] = sm[i-1]+ RC[i];
        }
        
        deque<int> dq;
        int maxx = 0;
        for(rt=0; rt<N; rt++){
            
            while(!dq.empty() && dq.front() <lf)
                dq.pop_front();
            
            //remove the smaller number before ele
            while(!dq.empty() && CT[dq.back()] <CT[rt]){
                dq.pop_back();
            }
            
            //put the element
            dq.push_back(rt);
            
            //MAX
            //CT[dq.front()];
                
                
            //max(chargeTimes) + k * sum(runningCosts)
            int k = rt-lf+1;
            long long int l = (lf-1<0)?0:sm[lf-1]; 
            while(!dq.empty() && (CT[dq.front()]+ k *(sm[rt]-l)) > budget && lf<=rt){
                
                lf++;
                while(!dq.empty() && dq.front() <lf)
                dq.pop_front();
                
                k = rt-lf+1;
                l = (lf-1<0)?0:sm[lf-1]; 
                
                
            }
            
            
            maxx = max(maxx, rt-lf+1);
            
        }
        
        return maxx;
    }
};