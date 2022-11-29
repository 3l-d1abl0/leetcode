class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        
        vector<vector<string>>  ans;
        
        sort(products.begin(), products.end());
        for(string st: products)
            cout<<st<<" ";
        cout<<endl;
        int N = products.size();
        string str ="";
        for(char ch : searchWord){
            
            str+=ch;
            
            int lidx = lower_bound(products.begin(), products.end(), str) - products.begin();
            //int uidx = upper_bound(products.begin(), products.end(), str) - products.begin();
            
            
            vector<string> sugg;
            
            
            int lim = min(N-1, lidx+2);
            
            for(int i=lidx; i<=lim; i++){
                
                if(products[i].find(str) == string::npos)
                   break;
                   
                sugg.push_back(products[i]);
            }
            
            ans.push_back(sugg);
            
        }
        
        
        return ans;
    }
};