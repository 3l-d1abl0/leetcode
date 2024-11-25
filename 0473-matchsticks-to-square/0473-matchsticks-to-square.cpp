class Solution {
public:
    
    
    bool method2(vector<int> &nums) {
        
        if (nums.size() < 4) return false;
        int sum = 0;
        for (const int val: nums) {
            sum += val;
        }
        if (sum % 4 != 0) return false;
        //sort(nums.begin(), nums.end(), [](const int &l, const int &r){return l > r;}); // second
        vector<int> sidesLength(4, 0);
        return dfs(sidesLength, nums, 0, sum / 4);
        
    }
    
    bool dfs(vector<int> &sidesLength,const vector<int> &matches, int index, const int target) {
        if (index == matches.size())
            return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
        for (int i = 0; i < 4; ++i) {
            if (sidesLength[i] + matches[index] > target) // first
                continue;
            int j = i;
            while (--j >= 0) // third
                if (sidesLength[i] == sidesLength[j]) 
                    break;
            if (j != -1) continue;
            sidesLength[i] += matches[index];
            if (dfs(sidesLength, matches, index + 1, target))
                return true;
            sidesLength[i] -= matches[index];
        }
        return false;
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
        //return method1(matchsticks);
        
        
        /*2. Method2
        
        */
        
        return method2(matchsticks);
        
    }

};