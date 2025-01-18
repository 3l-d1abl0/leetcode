class Solution {
public:
    unordered_map<int, int> memo;

    int dfs(int target) {
        if (target == 0) return 0;
        if (memo.count(target)) return memo[target];

        int res = target;
        for (int i = 1; i * i <= target; i++) {
            res = min(res, 1 + dfs(target - i * i));
        }

        return memo[target] = res;
    }

    int numSquares(int n) {
        return dfs(n);
    }
};