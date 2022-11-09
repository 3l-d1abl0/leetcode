bool comp(vector<int> &a,vector<int> &b) {
    return a[1]<b[1];
}


class Solution {
public:
    

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
     
        int N=intervals.size();
        
        if(N==0)
            return N;
        
        sort(intervals.begin(), intervals.end(), comp);
        
        
        /*for(auto ele: intervals){
            cout<<ele[0]<<", "<<ele[1]<<endl;
        }*/
        
        
        pair<int, int> intv ={intervals[0][0], intervals[0][1]};
        
        //cout<<"-----"<<endl;
        
        int ctr=0; 
        for(int i=1; i<N; i++){
        
            //cout<<intv.first<<" "<<intv.second<<endl;
            
            if(intv.second<= intervals[i][0]){ //non-overlapping
                intv = { intervals[i][0], intervals[i][1]};
                ctr++;
                
            }
            
        }
        
        //cout<<intv.first<<" "<<intv.second<<endl;
        
        //cout<<ctr<<endl;
        
        return N-ctr-1;
        
    }
};