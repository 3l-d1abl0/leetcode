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
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        
        //Method1: Using Sets
        return method1(recipes, ingredients, supplies);
        
    }
};