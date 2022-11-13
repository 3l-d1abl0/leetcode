/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int minSwaps(vector<int> nums){
        
        int len = nums.size();
        map<int, int> map;
        for (int i = 0; i < len; i++)
            map[nums[i]] = i;

        sort(nums.begin(), nums.end());

        vector<int> visited(len, false);

        
        int ans = 0;
        for (int i = 0; i < len; i++) {


            if (visited[i] || map[nums[i]] == i)
                continue;

            int j = i, cycle_size = 0;
            while (!visited[j]) {
                visited[j] = true;

                
                j = map[nums[j]];
                cycle_size++;
            }

            
            if (cycle_size > 0) {
                ans += (cycle_size - 1);
            }
        }
        return ans;
    }
    
    
    int minimumOperations(TreeNode* root) {
        
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        int ans =0;
        while(!q.empty()){
            
            int len = q.size();
            
            vector<int> arr;
            for(int i=0; i<len; i++){
                
                TreeNode* top = q.front(); q.pop();
                arr.push_back(top->val);
                
                if(top->left){
                    q.push(top->left);
                }
                
                if(top->right){
                    q.push(top->right);
                }    
            }
            
            
            ans +=minSwaps(arr);
            
            
            
        }
        
        
        return ans;
    }
};