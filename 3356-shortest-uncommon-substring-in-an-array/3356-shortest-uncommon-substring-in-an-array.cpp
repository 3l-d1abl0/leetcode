class Solution {
public:
    void build(string str, int idx, unordered_map<string, pair<bool, int>> &mp){

        int N = str.size();
        for(int i=0; i<N; i++){
            for(int j=i; j<N; j++){
                string subs = str.substr(i, j-i+1);
                
                if(mp.find(subs) == mp.end() || mp[subs].second==idx)
                    mp[subs] = {true, idx};
                else
                    mp[subs] = {false, -1};
            }
        }
    }

    static bool customCompare(const std::string &a, const std::string &b) {
        if (a.length() != b.length())
            return a.length() < b.length(); // sort by length
        return a < b; // if lengths are equal, sort lexicographically
    }

    vector<string> method1(vector<string>& arr) {
        //string => valid/invalid , idx
        unordered_map<string, pair<bool, int>> mp;
        int N = arr.size();
        for(int i=0; i<N; i++){
            build(arr[i], i, mp);
        }//for

        //gather the subs
        vector<string> ans(N, "");
        vector<vector<string>> temp(N);
        for(auto kv: mp){

            if(kv.second.first == false)
                continue;

            temp[kv.second.second].push_back(kv.first);

        }

        for(int i=0; i<N; i++){
            if(temp[i].size() == 0)
                continue;
            else if (temp[i].size()==1)
                ans[i]= temp[i][0];
            else{
                sort(temp[i].begin(), temp[i].end(), customCompare);
                ans[i]= temp[i][0];
            }
        }//for


        return ans;
    }

    vector<string> method2(vector<string>& arr) {
        return {};
    }

    vector<string> shortestSubstrings(vector<string>& arr) {

        //Method1 : generate substring, keep in Hash
        return method1(arr);

        //Methiod2 : Trie, mark substring index + dfs to collect
        //return method2(arr);
              
    }

};