class Solution {
public:
    string largestPalindromic(string num) {
        map<char,int>m;
        for(auto x:num){
            m[x]++;
        }
        string res="";
        for(auto x:m){
            
                if(x.first!='0'){
                    int v=x.second/2;
                    string k(v,x.first);
                    res+=k; 
                }
            
            
        }
        cout<<res.length()<<endl;
        if(res.length()>0){
             int v=m['0']/2;
            //cout<<v<<endl;
                    string k(v,'0');
                    res+=k; 
        } 
        cout<<res<<endl;
        sort(res.begin(),res.end());
        reverse(res.begin(),res.end());
        string p=res;
        char ch='/';
        for(auto x:m){
            if(x.second%2) {
                ch=max(ch,x.first);
            }
        }
        if(ch!='/') res+=ch;
        
        reverse(p.begin(),p.end());
        
        res+=p;
        
        if(res=="")
            return "0";
        else
            return res;
    }
};