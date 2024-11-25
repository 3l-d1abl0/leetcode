class Solution {
public:
    
    bool method1(vector<int> &matchsticks){
        
        int sum = 0;
        sum = accumulate(matchsticks.begin(), matchsticks.end(), sum);
        if (matchsticks.size() < 4 || sum % 4) return false;
        
        vector<int>visited(matchsticks.size(), false);
        return backtrack(matchsticks, visited, sum / 4, 0, 0, 4);
        
    }
    bool backtrack(vector<int>& matchsticks,vector<int> &visited, int target, int curr_sum, int idx, int side) {
    
        if (side == 1) // if k == 1 then we found all subsets, rest of the sides are Target
            return true;
        
        if (curr_sum == target) // we found one subset, go on to the next one starting from curr_sum = 0
            return backtrack(matchsticks, visited, target, 0, 0, side-1);
        
        for (int j = idx; j < matchsticks.size(); j++) {
            
            if (visited[j] || curr_sum + matchsticks[j] > target)
                continue; // if we visited this index already or curr_sum + matchsticks[j] > target then we can't use it
            
            visited[j] = true;
            if (backtrack(matchsticks, visited, target, curr_sum + matchsticks[j], j+1, side))
                return true;
            visited[j] = false;
        }
        
        return false;
    }
    
    
    
    bool makesquare(vector<int> &matchsticks) {
        
        /*1. Method1
        This method fiils one side with possible stick till it reaches its target,
        Once it reaches its target it moves on to the other side
        */
        return method1(matchsticks);
        
    }

};