class Solution {
public:
    
    string method1(string s){
        
        vector<string> words;
        stringstream ss(s);
        string tmp;
        while (ss >> tmp)
            words.push_back(tmp);

        /*for(auto ele: words){
            cout<<ele<<" ";
        }cout<<endl;*/
        
        string ans;
        for (int i = words.size() - 1; i >= 0; --i) {
            if (i != words.size() - 1) ans += " ";
            ans += words[i];
        }
        
        return ans;
    }
    
    
    void rev(string::iterator begin, string::iterator end){
        
        end--;
        while(begin <end){
            swap((*begin), (*end));
            begin++;
            end--;
        }
        
    }
    string method2(string s){
        
        
        rev(s.begin(), s.end());
        
        int i=0, ptr =0, N = s.size();
        int wordEnd =0;
        while(i<N){
            
            while(i<N && s[i]==' '){
                i++;
            }
            
            int wordStart = ptr;
            while(i<N && s[i]!=' '){
                s[ptr] = s[i];
                wordEnd = ptr;
                ptr++;
                i++;
            }
            
            rev(s.begin()+wordStart, s.begin()+wordEnd+1);
            
            s[ptr]=' ';
            ptr++;
        }
        
        
        s.resize(wordEnd+1);
        return s;
    }
    string reverseWords(string s) {
        
        //return method1(s);
        
        return method2(s);
    }
};