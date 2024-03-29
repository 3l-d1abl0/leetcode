class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        
        
        
                for(vector<int>& e: dependencies) e[0] --, e[1] --;

        vector<vector<int>> bitsOfStates = vector<vector<int>>(n + 1);
        for(int state = 0; state < (1 << n); state ++) {
//            cout << num_of_ones(state) << endl;
            bitsOfStates[num_of_ones(state)].push_back(state);
        }

        vector<int> dp(1 << n, -1);
        return dfs(n, dependencies, k, (1 << n) - 1, dp);
        
        
    }
    
    
    
    private:
    int dfs(int n, const vector<vector<int>>& edges, int k, int state,
            vector<int>& dp){

        if(!state) return 0;
        if(dp[state] != -1) return dp[state];

        vector<int> indegrees(n, 0);
        for(const vector<int>& e: edges)
            if(state & (1 << e[0])) indegrees[e[1]] ++;

        vector<int> options;
        for(int i = 0; i < n; i ++)
            if((state & (1 << i)) && !indegrees[i]) options.push_back(i);

        int c = min(k, (int)options.size());
        vector<int> option_states;
        get_option_states(options, 0, c, 0, option_states);

        int res = INT_MAX;
        for(int option_state: option_states)
            res = min(res, 1 + dfs(n, edges, k, state - option_state, dp));
//        cout << state << " : " << res << endl;
        return dp[state] = res;
    }

    void get_option_states(const vector<int>& options, int index, int k, int state,
                           vector<int>& res){

        if(k == 0){
            res.push_back(state);
            return;
        }
        if(index == options.size()) return;

        for(int i = index; i < options.size(); i ++)
            get_option_states(options, i + 1, k - 1, state | (1 << options[i]), res);
    }

    int num_of_ones(int state){

        int res = 0;
        while(state){
            res += (state & 1);
            state >>= 1;
        }
        return res;
    }
};