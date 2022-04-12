#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool build_graph(unordered_map<char, vector<char>> &graph, vector<string> &word, unordered_map<char, int> &indegree)
    {
        // Initialized
        for (string w : word)
        {

            for (char ele : w)
            {
                if (indegree.count(ele) == 0)
                    indegree[ele] = 0;
            }
        }

        for (int i = 0; i < word.size() - 1; i++)
        {

            string w1 = word[i];
            string w2 = word[i + 1];

            int idx = 0;
            while (idx < w1.size() && idx < w2.size() && w1[idx] == w2[idx])
            {
                idx++;
            }

            if (idx < w1.size() && idx < w2.size())
            { // characters are different

                indegree[w2[idx]]++;
                graph[w1[idx]].push_back(w2[idx]);
            }
            else if (idx >= w2.size() && idx < w1.size())
            {
                return false; // invalid list
            }
        }

        return true;
    }

    string alienOrder(vector<string> &words)
    {

        if (words.size() == 0)
            return "";

        unordered_map<char, vector<char>> graph;
        unordered_map<char, int> indegree;

        bool invalid_graph = build_graph(graph, words, indegree);

        if (invalid_graph == false)
            return "";

        string result = topoSort(indegree, graph); // use priority queu for keeping lexicographic order

        return result.size() == graph.size() ? result : "";
    }

    string topoSort(unordered_map<char, int> &indegree, unordered_map<char, vector<char>> &graph)
    {

        priority_queue<char, vector<char>, greater<char>> q;
        string result = "";

        for (pair<char, int> ele : indegree)
        {
            if (ele.second == 0)
                q.push(ele.first);
            ;
        }

        while (!q.empty())
        {
            char src = q.top();
            q.pop();
            result += src;

            for (char node : graph[src])
            {

                indegree[node]--;
                if (indegree[node] == 0)
                {
                    q.push(node);
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution ob;
    // vector<string> v = {"wrt", "wrf", "er", "ett", "rftt"}; //"wertf"
    //  vector<string> v = {"abc", "ab"};
    //  vector<string> v = {"zy", "zx"}; // yxz

    // vector<string> v = {"z", "x"}; // zx

    vector<string> v = {"ab", "adc"}; // abcd
    cout << (ob.alienOrder(v));
}