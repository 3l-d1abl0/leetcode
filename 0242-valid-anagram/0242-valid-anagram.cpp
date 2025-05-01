class Solution {
public:
    bool isAnagram(string s, string t) {

        unordered_map<char, int> mp1;
        unordered_map<char, int> mp2;

        for(char ch: s)
            mp1[ch]++;


        for(char ch: t){

            if(mp1.find(ch) == mp1.end())
                return false;
            mp2[ch]++;
        }


        if(mp1.size() != mp2.size())
            return false;

        for(auto it: mp1){
            if(mp2.find(it.first) == mp2.end())
                return false;

            if(it.second != mp2[it.first])
                return false;
            
        }


        return true;      
    }
};