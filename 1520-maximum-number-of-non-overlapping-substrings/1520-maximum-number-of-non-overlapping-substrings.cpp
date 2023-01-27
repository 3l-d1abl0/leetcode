class Solution {
public:
    
    void dfs(char ch, stack<char> &st, vector<bool> &visited, map<char, unordered_set<char>> &G){
       
        visited[ch-'a'] = true;
        
        for(char v: G[ch]){
            
            if(visited[v-'a']==false){
                dfs(v, st, visited, G);
            }
            
        }
        
        st.push(ch);
        
    }
    
    void dfsRev(char node, int ssc, vector<int> &sscno, vector<int> &canBeReached, map<char, unordered_set<char>> &revG, vector<vector<int>> &sscNodes){
        
        sscno[node-'a'] = ssc;
        
        sscNodes[ssc].push_back(node-'a');
        for(char v: revG[node]){
            
            if(sscno[v-'a']==-1){
                dfsRev(v, ssc, sscno, canBeReached, revG, sscNodes);
            }else{
                //v is already a part of component
                if(sscno[v-'a'] != ssc){
                    
                    //SSC sscno[v-'a'] can be reached via ssc
                    canBeReached[sscno[v-'a']] = ssc;
                }
            }
        }
    }
        
    void printGraph(map<char, unordered_set<char>> &G){
        
        for(auto st: G){
            
            cout<<st.first<<": ";
            for(auto v: st.second){
                cout<<v<<" ";
            }
            
            cout<<endl;
        }
        
    }
        
    vector<string> maxNumOfSubstrings(string s) {
        
        int N = s.size();
        map<char, pair<int,int>> pos;
        //find 1st last occur of each char
        for(int i=0; i<N; i++){
            
            if(pos.find(s[i])==pos.end()){
                pos.insert({s[i], {i,i}});
            }else{
                pos[s[i]].second= i; 
            }
        }
        
        
        map<char, unordered_set<char>> G;
        map<char, unordered_set<char>> revG;
        
        //Make the Graph
        for(int i=0; i<26; i++){
            
            char ch = i+'a';
            //if ch exists in string
            if(pos.find(ch)!= pos.end()){
                
                for(int idx=pos[ch].first; idx<=pos[ch].second; idx++){
                    
                    //if(ch==s[idx])
                    //    continue;
                    //s[idx] lies between start,end of ch
                    //there is an edge from ch to s[idx]
                    G[ch].insert(s[idx]);
                    
                    revG[s[idx]].insert(ch);
                }
            }
        }//i
        
        
        //printGraph(G);
        //cout<<"REDG:: "<<endl;
        //printGraph(revG);
        
        //DFS for Topo Ordering
        stack<char> st;
        vector<bool> visited (26, false);
        for(int i=0; i<26; i++){
            char ch = i+'a';
            //if ch exists in string
            if(pos.find(ch)!= pos.end() && visited[i]==false){
                dfs(ch, st, visited, G);
            }
        }
        
        //cout<<"-----DFS----"<<endl;
        //do a dfs on rev Graph
        
        /*while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;*/
        
        int ssc=0;
        vector<int> sscNo (26, -1);
        vector<int> canBeReached(26, -1);
        vector<vector<int>> sscNodes(26);
        while(!st.empty()){
            
            char node = st.top();
            st.pop();
            //cout<<"node: "<<node<<" ";
            if(sscNo[node-'a'] != -1) //already visited
                continue;
            
            dfsRev(node, ssc ,sscNo, canBeReached, revG, sscNodes);
            
            ssc++;
        }
        
        /*cout<<endl<<"SSC : "<<ssc-1<<endl;
        for(int i=0; i<ssc; i++){
            cout<<i<<" <-- "<<canBeReached[i]<<endl;
            for(auto v: sscNodes[i]){
                cout<<(char)(v+'a')<<" ";
            }
            cout<<endl;
        }*/
        
        //cout<<endl<<"compute---ans----"<<endl;
        vector<string> ans;
        //Check which ssc where not reachd
        for(int i=0; i<ssc; i++){
            
            if(canBeReached[i]== -1){//cant be reached by any other nodes
                
                //cout<<i<<" :: ";
                int minStart = N, maxEnd =-1;
                for(int v: sscNodes[i]){
                    
                    char ch= v+'a';
                    minStart = min(minStart, pos[ch].first);
                    maxEnd = max(maxEnd, pos[ch].second);
                    
                   // cout<<ch<<" "<<pos[ch].first<<" "<<pos[ch].second;
                }
                ans.push_back(s.substr(minStart, maxEnd-minStart+1));
                
               // cout<<endl;
            }
        }//for
        
        return ans;
    }
};