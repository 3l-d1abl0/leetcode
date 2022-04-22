// SIMULTANEOUS BFS

class Solution
{
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */

    void addNewCell(int x, int y, vector<vector<int>> &rooms, queue<pair<int, int>> &q, int dist)
    {

        if (x < 0 || x >= rooms.size() || y < 0 || y >= rooms[0].size() || rooms[x][y] != INT_MAX)
            return;

        rooms[x][y] = dist;
        q.push({x, y});
    }

    void wallsAndGates(vector<vector<int>> &rooms)
    {
        // write your code here

        // cout<<INT_MAX<<endl;
        int M = rooms.size();
        int N = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {

                if (rooms[i][j] == 0)
                {
                    q.push({i, j});
                }
            }
        } // for

        int dist = 1;
        while (!q.empty())
        {

            int len = q.size();

            for (int i = 0; i < len; i++)
            {

                pair<int, int> co = q.front();
                q.pop();

                addNewCell(co.first + 1, co.second, rooms, q, dist);
                addNewCell(co.first - 1, co.second, rooms, q, dist);
                addNewCell(co.first, co.second + 1, rooms, q, dist);
                addNewCell(co.first, co.second - 1, rooms, q, dist);
            }
            dist++;
        }
    }
};