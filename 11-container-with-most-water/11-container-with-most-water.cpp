class Solution {
public:
    int maxArea(vector<int>& height) {
     
        int l=0, r= height.size()-1;
        
        int max_water=-1;
        
        while(l<r){
            max_water = max(max_water, (r-l) * min(height[l], height[r]));
            //cout<<l<<" "<<r<<" "<<max_water<<endl;
            
            if(height[l]<height[r]){
                l++;
            }else if(height[l]> height[r]){
                r--;
            }else{
                l++;
                r--;
            }
            
        }
        
        return max_water;
    }
};