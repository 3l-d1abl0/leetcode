class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        
        
        priority_queue<int> maxHeap;
        
        for(int i=1; i<heights.size(); i++){
            
            int diff = heights[i]-heights[i-1];
            if(diff<=0)
                continue;
            
            
            bricks -=diff;
            maxHeap.push(diff);
            
            if(bricks<0){
                if(ladders==0){
                    return i-1;
                }else{
                    ladders--;
                    bricks+= maxHeap.top();
                    maxHeap.pop();
                }
            }
        }//for
        
        
        return heights.size()-1;
    }
};