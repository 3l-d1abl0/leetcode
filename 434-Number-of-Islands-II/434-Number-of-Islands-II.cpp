class DSU
{

    int __size;
    vector<int> parent, size, rank;

public:
    DSU(int N)
    {

        __size = N;

        for (int i = 0; i <= N; i++)
        {
            parent.push_back(i); // everyone is aprent of self
            size.push_back(1);   // every component is of size 1
            rank.push_back(0);   // default rank is 0
        }
    }

    int findParent(int node)
    {
        if (parent[node] == node)
            return node;

        return parent[node] = findParent(parent[node]);
    }

    void unionSize(int u, int v)
    {

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu != pv)
        {

            if (size[pu] > size[pv])
            {
                parent[pv] = pu;
                size[pu] += size[pv];
            }
            else
            {
                parent[pu] = pv;
                size[pv] += size[pu];
            }
        }
    }

    void unionRank(int u, int v)
    {

        int pu = findParent(u);
        int pv = findParent(v);

        if (pu != pv)
        {

            // if rank equal then increase
            if (rank[pu] == rank[pv])
            {
                parent[pu] = pv;
                rank[pv]++;
            }
            else if (rank[pu] < rank[pv])
            {
                parent[pu] = pv;
            }
            else
            {
                parent[pv] = pu;
            }
        }
    }
};

class Solution
{
public:
    /**
     * @param n: An integer
     * @param m: An integer
     * @param operators: an array of point
     * @return: an integer array
     */
    vector<int> numIslands2(int N, int M, vector<Point> &operators)
    {
        // write your code here

        vector<vector<int>> grid(N, vector<int>(M, 0));
        vector<int> ans;

        DSU ds(N * M);
        int islands = 0;

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};

        for (Point p : operators)
        {
            if (grid[p.x][p.y] == 1)
            {
                ans.push_back(islands);
                continue;
            }

            islands++;
            grid[p.x][p.y] = 1;

            int u = p.x * M + p.y;
            // cout<<"Init "<<islands<<" ";
            for (int i = 0; i < 4; i++)
            {

                int newX = p.x + dx[i];
                int newY = p.y + dy[i];

                if (newX >= 0 && newX < N && newY >= 0 && newY < M && grid[newX][newY] == 1)
                {

                    int v = newX * M + newY;

                    if (ds.findParent(u) != ds.findParent(v))
                    {

                        // ds.unionSize(u, v);
                        ds.unionRank(u, v);
                        islands--;
                    }
                }
            }
            // cout<<"Final "<<islands<<endl;

            ans.push_back(islands);
        } // for

        return ans;
    }
};
