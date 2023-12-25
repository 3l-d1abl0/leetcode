class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        
        priority_queue<int> maxH;
        int minE = INT_MAX;
        
        for(int ele: nums){
            
            if(ele &1)  //odd - can be doubled
                ele *=2;
            
            minE = min(minE, ele);  //keep track of max ele so far
            maxH.push(ele);
        }
        
        int minDev = INT_MAX;
        while(maxH.top() %2 ==0){
            
            int maxE = maxH.top();
            minDev = min(minDev, maxE-minE);
            
            maxH.pop();
            maxH.push(maxE/2);
                
            minE = min(minE, maxE/2);
            
        }//while
        
        
        return min(minDev, maxH.top() - minE);
    }
};