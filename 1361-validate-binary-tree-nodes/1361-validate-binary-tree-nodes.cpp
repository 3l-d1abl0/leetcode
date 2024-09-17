class Solution {
public:
    
bool validateBinaryTreeNodes(int n, std::vector<int>& leftChild, std::vector<int>& rightChild) {
    
        /*
            Basically,
            Each node can be child of only 1 child (1-indegree)
            Except root node - 0 indegree (There can be only 1 Root)
            
            Check for no cycles
        */
    
        //1.
        vector<int> indegree(n, 0);
        for (int i = 0; i < n; ++i) {
            if (leftChild[i] != -1) indegree[leftChild[i]]++;
            if (rightChild[i] != -1) indegree[rightChild[i]]++;
        }
    
        //2.
        int root = -1;
        for (int i = 0; i < n; ++i) {
            if (indegree[i] == 0) {
                if (root == -1)
                    root = i;
                else
                    return false;
            }
        }
    
        if (root == -1) return false;
        //3.
        vector<bool> visited(n, false);
        queue<int> queue;
        queue.push(root);
        while (!queue.empty()) {
            int node = queue.front(); queue.pop();
            if (visited[node])
                return false;
            visited[node] = true;
            if (leftChild[node] != -1)
                queue.push(leftChild[node]);
            if (rightChild[node] != -1)
                queue.push(rightChild[node]);
        }
    
        return accumulate(visited.begin(), visited.end(), 0) == n;
    }
    
};