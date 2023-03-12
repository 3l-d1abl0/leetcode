class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        
        sort(asteroids.begin(), asteroids.end());
        
        
        
        //int sum = mass;
        int N = asteroids.size();
        for(int ele: asteroids){
            
            if(mass >= asteroids[N-1]){
                return true;
            }else if(mass < ele){
                return false;
            }else{
                mass +=ele;
            }
            
        }
        
        
        return true;
    }
};