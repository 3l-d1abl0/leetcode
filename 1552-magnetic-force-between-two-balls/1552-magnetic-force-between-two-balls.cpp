class Solution {
public:
    
    int canPlace(vector<int> &position, int m, int dist){
        
        int cnt =1;
        int pos= position[0];
        
        for(int i=1; i<position.size(); i++){
            
            if(position[i]-pos >= dist){
                cnt++;
                pos = position[i];
            }
            
            if(cnt==m)
                return true;
            
        }
        
        return false;
        
    }
    
    int maxDistance(vector<int>& position, int m) {
     
        
        sort(position.begin(), position.end());
             
        int n = position.size();
             
        int l =1; int r = position[n-1]-position[0];
        int ans = l;
             
        while(l<=r){
            
            int mid = l +(r-l)/2;
            
            if(canPlace(position, m, mid)){
                l=mid+1;
                ans= mid;
            }else{
                r=mid-1;
            }
            
        }
             
        return ans;
    }
};