    bool comp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }

class Solution {
public:
    

    
    int eraseOverlapIntervals(vector<vector<int>>& iv){
        
        
        int N = iv.size();
        
        if(N==0) return 0;
        
        sort(iv.begin(), iv.end(), comp);
        /*for(auto ele: iv)
            cout<<ele[0]<<" "<<ele[1]<<endl;
        */
        
        
        
        pair<int, int> prevInterval = {iv[0][0], iv[0][1]} ;
        
        int ctr=0;
        for(int i=1; i<N; i++){
        
            if(prevInterval.second<= iv[i][0]){ //doesn't Overlap
                prevInterval = { iv[i][0], iv[i][1] };
            }else{
                
                //overlap - remove the interval with max end time
                // as it can cause omre conflict
                int low = min(prevInterval.first, iv[i][0]);
                int high = min(prevInterval.second, iv[i][1]);
                
                prevInterval ={low, high};
                
                ctr++;
            }
            
        }
        
        //cout<<ctr<<endl;
        
        return ctr;
    }
};