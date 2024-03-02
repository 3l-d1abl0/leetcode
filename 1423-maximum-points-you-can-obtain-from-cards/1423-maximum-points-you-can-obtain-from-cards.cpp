class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        
        int total_sum =0, sub_sum =0, min_sum=INT_MAX;
        int lf=0;
        
        int sz = cardPoints.size()-k;
        for(int rt=0; rt<cardPoints.size(); rt++){
            
            total_sum += cardPoints[rt];
            sub_sum +=cardPoints[rt];
            
            while(rt-lf+1 > sz){
                
                sub_sum-=cardPoints[lf];
                lf++;
            }
            
            if(sz==rt-lf+1){
                min_sum = min(min_sum, sub_sum);
            }
        }//for
        
        
        
        return total_sum-min_sum;
    }
};