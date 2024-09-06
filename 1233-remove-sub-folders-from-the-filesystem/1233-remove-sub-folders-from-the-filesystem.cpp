class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        
        //sort alphabetical
        sort(folder.begin(),folder.end());
        
        //find the root folders        
        vector<string> rootStore;
        rootStore.push_back(folder[0]);
        
        for(int i=1;i<folder.size();i++){
            
            string root=rootStore.back();
            
            //If it doesn't start with the current roor, its a new Root
            if(folder[i].substr(0,root.size())!=root){
                
                    rootStore.push_back(folder[i]);
            }else{
                if(folder[i][root.size()]!='/')
                    rootStore.push_back(folder[i]);
            }
        }
 
        return rootStore;
        
        
    }
};