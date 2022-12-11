class Solution {
public:
    
    string method1(string &s){
        
        vector<int> freq(128, 0);
        
        for(char c: s){
            freq[c]++;
        }
        
        sort(s.begin(), s.end(), [&](char a, char b){
            //if same freq, sort ascendign by char
            return freq[a] == freq[b] ? a<b : freq[a]>freq[b];
            //else sort descending by freq
        });
        
        
        return s;
    }
    
    string method2(string &s){
        
        unordered_map<char, int> mp;
        
        for(char c: s){
            mp[c]++;
        }
        
        vector< pair<int, char>> arr;
        for(auto &[c, f]: mp){
            arr.push_back({f, c});
        }
        
        sort(arr.begin(), arr.end(), [](const auto &a, const auto &b){
            //descending order by freq
            return a.first > b.first;
        });
        
        string ans;
        for(auto &[f, c]: arr){
            ans.append(f, c); //f times c
        }
        
        return ans;
    }
    
    
    string method3(string &s){
        
        unordered_map<char, int> mp;
        
        for(char c: s){
            mp[c]++;
        }
        
        priority_queue<pair<int, char> > maxHeap;
        
        for(auto &[c, f]: mp){
            maxHeap.push({f, c});
        }
        
        string ans;
        while(!maxHeap.empty()){
            
            int f = maxHeap.top().first;
            char c = maxHeap.top().second;
            
            ans.append(f, c);
            maxHeap.pop();
        }
        
        return ans;
    }
    
    string method4(string &s){
        
        unordered_map<char, int> mp;
        
        for(char c: s){
            mp[c]++;
        }
        
        vector<vector<char> > bucket(s.size());
        
        for(auto &[c, f]: mp){
            bucket[f-1].push_back(c);
        }
        
        string ans;
        for(int idx= s.size()-1; idx>=0; idx--){
            
            for(char c: bucket[idx]){
                ans.append(idx+1, c);
            }
        }
        
        return ans;
        
    }
    
    string frequencySort(string s) {
        
        
        //1. sort based on frequency - TC:O(NlogN) SC: O(logN)
        //return method1(s);
        
        //2. sort by freq, char pair - TC O(N) +(KlogK) SC: O(N)
        //return method2(s);
        
        //3. heap sort - TC: O(N)+ O(KlogK), SC : O(N)+O(N)
        //return method3(s);
        
        //4.Bucket Sort
        return method4(s);
    }
};