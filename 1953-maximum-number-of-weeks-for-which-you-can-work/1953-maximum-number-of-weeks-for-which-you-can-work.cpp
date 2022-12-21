class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        
        
        //case 1 - find element with max freq
        //case 2 - evenly distributed
        long long sum =0;
        int maxx =-1;
        
        for(int ele: milestones){
            maxx = max(maxx, ele);
            sum += ele;
        }
        
        long long int rest = sum -maxx;
        
        return min({2ll*rest+1, sum});    //min of case1 and case 2
    }
};