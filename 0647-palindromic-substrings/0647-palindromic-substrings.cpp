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
    
    int method2(string &s){
        
        string  str = string((int)s.length() * 2 + 1, '_');
        for(int idx =0; idx<s.size(); idx++){
            str[idx*2] ='#';
            str[(idx*2)+1]= s[idx];
        }
        
        //Set last pos as #     #S#U#B_ --> #S#U#B# 
        int N = str.size();
        str[N-1]='#';

        //cout<<str<<endl;

        vector<int> P(N, 0); //stores half-lenght of the palindrome at the index
        int C = 0; //center of the rewcent palindrome
        int R = 0; //rightmost boundary of the recent palindrome
    
        int count =0;
        for (int i = 1; i < N - 1; i++) {

        
            int mirror = 2 * C - i; //mirror index of i wrt to C as center
            if (i < R) { //if current index is within the boundary of the recent Plaindrome
                P[i] = min(R - i, P[mirror]);
            }
            

            //Try expading if the current palindrome extens beyond the boundaries od recent Plaindrome
            while (i + 1 + P[i] < N && i - 1 - P[i] >= 0 && str[i + 1 + P[i]] == str[i - 1 - P[i]]) {
                P[i]++;
            }

            //Update C and R wrt to the current palindrome
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
            
            
            
            count+=(P[i]+1)/2;
        }
        
        //         for(int val: P){
        //     cout<<val<<" ";
        // }cout<<endl;
        
//         int count =0;
//         for(int i=0; i<N; i++){
            
//         }
        
        
        return count;
    }
    
    
public:
    int countSubstrings(string s) {
        
        //1. Method 1: Expand at each index TC: O(N^2)
        //return method1(s);
        
        //2. Method 2: 
        return method2(s);
    }
};