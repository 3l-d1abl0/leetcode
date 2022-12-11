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
    
    string frequencySort(string s) {
        
        
        //1. sort based on frequency
        return method1(s);
    }
};