class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        int N = recipes.size();
        
        unordered_map<string, int> indegree;
        unordered_map<string, vector<string> > adj;
        
        unordered_set<string> ress;
        for(string res: recipes){
            ress.insert(res);
        }
        
        for(int i=0; i<N;i ++){
            
            for(string ingr: ingredients[i]){
                
                
                adj[ingr].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        
        
        queue<string>q;
        //all ingredient in the supies has indegree 0
        for(string sup: supplies){
            q.push(sup);
        }
        
        vector<string> ans;
        //process the indegree 0
        while(!q.empty()){
            
            string ing = q.front(); q.pop();
            
            if(ress.find(ing)!=ress.end())
                ans.push_back(ing);
            
            
            for(string in: adj[ing]){
                indegree[in]--;
                
                
                if(indegree[in]==0){
                    q.push(in);
                }
            }
        }//while
        
        return ans;
    }
};