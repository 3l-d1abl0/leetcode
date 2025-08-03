class Solution {
public:
        vector<int> findBall(vector<vector<int>>& grid) {
        int R = grid.size(), C = grid[0].size();
        vector<int> res;
        for (int i = 0; i < C; ++i) {
           
            int col = i, next;
            for (int row = 0; row < R; ++row) {
                cout<<row<<" "<<col<<endl;
                next = col + grid[row][col];

                if (next < 0 || next >= C || grid[row][next] != grid[row][col]) {
                    col = -1;
                    break;
                }
                //if the next colum has the same slope go down.
                col = next;
            }

            cout<<"================="<<endl;
            res.push_back(col);
        }
        return res;
    }
};