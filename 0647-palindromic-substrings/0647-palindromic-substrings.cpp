class Solution {
    
private:
    int countPali(string s, int l, int r) {
        int res = 0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }
        return res;
    }
    
    int method1(string s){
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            res += countPali(s, i, i);
            res += countPali(s, i, i + 1);
        }
        return res;
    }
    
public:
    int countSubstrings(string s) {
        
        //1. Method 1: Expand at each index TC: O(N^2)
        return method1(s);
        
    }
};