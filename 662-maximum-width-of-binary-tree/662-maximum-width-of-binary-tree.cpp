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
    int widthOfBinaryTree(TreeNode* root) {
        
        /*queue<TreeNode *> q;
        
        int first_idx, last_idx, maxx =-1;
        
        q.push(root);
        bool isNull = false;
        while(!q.empty()){
            
            
            if(isNull == true)
                return maxx;
            
            TreeNode *curr;
            int sz = q.size();
            first_idx = -1;
            last_idx = -1;
            
            isNull = true;
            for(int i=0; i<sz; i++){
                
                curr = q.front(); q.pop();
                if(curr==NULL){
                    
                    q.push(NULL);
                    q.push(NULL);
                    
                }else{
                    if(curr->left!= NULL || curr->right !=NULL)
                        isNull = false;
                    
                    q.push(curr->left);
                    q.push(curr->right);
                    
                    if(first_idx == -1)
                        first_idx = i;
                    
                    last_idx = i;
                }
            }//for
            
            maxx = max(maxx, last_idx -first_idx+1);
        }//while
        
        return maxx;
        */
        
          if (!root)
    return 0;
  int ans = 0;
  queue < pair < TreeNode * , long long >> q;
  q.push({
    root,
    0
  });
  while (!q.empty()) {
    int size = q.size();
    int curMin = q.front().second;
    int leftMost, rightMost;
    for (int i = 0; i < size; i++) {
      long long cur_id = q.front().second - curMin; // subtracted to prevent integer overflow
      TreeNode * temp = q.front().first;
      q.pop();
      if (i == 0) leftMost = cur_id;
      if (i == size - 1) rightMost = cur_id;
      if (temp -> left)
        q.push({
          temp -> left,
          cur_id * 2 + 1
        });
      if (temp -> right)
        q.push({
          temp -> right,
          cur_id * 2 + 2
        });
    }
    ans = max(ans, rightMost - leftMost + 1);
  }
  return ans;
    }
};