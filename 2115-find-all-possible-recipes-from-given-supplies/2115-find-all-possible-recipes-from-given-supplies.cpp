class Solution {
public:
    
    vector<string> method1(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies){
        
        //create a set of all supplies
        unordered_set<string> suppliesSet(supplies.begin(), supplies.end());
        
        vector<string> ans;
        
        int N = recipes.size();
        bool newSupply = false;
        do{
            /*
                In a cycle of recipe check if a new supply is created,
                that new supply could be an ingredient for another recipe.
                
                If no new supply is made, exit.
            */
            newSupply = false;
            for(int idx=0; idx<N; idx++){

                //if recepie alread exist
                if(suppliesSet.find(recipes[idx])!= suppliesSet.end())
                    continue;


                bool found = true;
                for(string ingredient: ingredients[idx]){

                    //does not exists
                    if(suppliesSet.find(ingredient)==suppliesSet.end()){
                        found = false;
                        break;
                    }

                }

                //all ingredients for recipe was found
                if(found==true){
                    suppliesSet.insert(recipes[idx]);
                    ans.push_back(recipes[idx]);
                    newSupply = true;
                }

            }//for
            
        }while(newSupply==true);
        
        
        return ans;
    }
    
        vector<string> method2(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies){
            
                
                int N = recipes.size();

                unordered_map<string, int> indegree;
                unordered_map<string, vector<string> > adj;

                //ingred --> recipe
                //Create undirected edge and calculate Indegree
                for(int i=0; i<N;i ++){

                    for(string ingr: ingredients[i]){


                        adj[ingr].push_back(recipes[i]);
                        indegree[recipes[i]]++;
                    }
                }


                //Queue to hold nodes with zero indegree
                queue<string>q;
                //all ingredient in the supies has indegree 0
                for(string sup: supplies){
                    q.push(sup);
                }


                //process the indegree 0
                while(!q.empty()){

                    string ing = q.front();
                    q.pop();


                    for(string in: adj[ing]){
                        indegree[in]--;


                        if(indegree[in]==0){
                            q.push(in);
                        }
                    }
                }//while

            
                /*
                Check the recipes which have been processed,
                i.e 0 indegree
                */
                vector<string> ans;
                for(string res: recipes){
                    if(indegree[res]==0) ans.push_back(res);
                }


                return ans;
            
        }
    
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        
        //Method1: Using Sets   - 1180ms    - O(N*N)
        //return method1(recipes, ingredients, supplies);
        
        //Method2 - Topological Sorting
        return method2(recipes, ingredients, supplies);
        
    }
};