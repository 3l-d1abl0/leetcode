int rowInd[500];
int colInd[500];

class Solution
{
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions, vector<vector<int>> &colConditions)
    {
        int n = rowConditions.size();
        int m = colConditions.size();
        fill(rowInd, rowInd+k+1, 0);
        fill(colInd, colInd+k+1, 0);
        vector<vector<int>> rgraph(k + 1), cgraph(k + 1);
        for (int i = 0; i < n; i++)
        {
            rowInd[rowConditions[i][1]]++;
            rgraph[rowConditions[i][0]].push_back(rowConditions[i][1]);
        }
        for (int i = 0; i < m; i++)
        {
            colInd[colConditions[i][1]]++;
            cgraph[colConditions[i][0]].push_back(colConditions[i][1]);
        }
        
        queue<int> cq, rq;
        for (int i = 1; i <= k; i++)
        {
            if (rowInd[i] == 0)
                rq.push(i);
            if (colInd[i] == 0)
                cq.push(i);
        }
        vector<int> rows(k + 1), cols(k + 1);
        int c = 0;
        while (cq.size())
        {
            int i = cq.front();
            cq.pop();
            cols[i] = c++;
            for (auto j = begin(cgraph[i]); j != end(cgraph[i]); j++)
            {
                --colInd[*j];
                if (colInd[*j] == 0)
                {
                    cq.push(*j);
                }
            }
        }
        if (c != k)
            return vector<vector<int>>();
        c = 0;
        while (rq.size())
        {
            int i = rq.front();
            rq.pop();
            rows[i] = c++;
            for (auto j = begin(rgraph[i]); j != end(rgraph[i]); j++)
            {
                --rowInd[*j];
                if (rowInd[*j] == 0)
                {
                    rq.push(*j);
                }
            }
        }
        if (c != k)
            return vector<vector<int>>();
        vector<vector<int>> ret(k, vector<int>(k, 0));
        for (int i = 1; i <= k; i++)
        {
            ret[rows[i]][cols[i]] = i;
        }
        return ret;
    }
};