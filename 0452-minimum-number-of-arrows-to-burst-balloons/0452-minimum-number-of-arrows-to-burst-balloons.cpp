bool comp(vector<int> &a, vector<int> &b){
    return a[1]<b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int N = points.size();
        
        if(N==0)
            return 0;
        
        sort(points.begin(), points.end(), comp);
        
        pair<int, int> common { points[0][0], points[0][1] };
        
        int ctr=1; //alread need 1 arrow
        for(int i=1; i<N; i++){
            
            if(common.second < points[i][0]){ // overlap
                common = { points[i][0], points[i][1] };
                ctr++;
            }else{
                common = {max(common.first, points[i][0]), min(common.second, points[i][1])};
            }
            
        }//for
        
        return ctr;
        
    }
};