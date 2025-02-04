class DSU{

    int _size;
    vector<int> parent;
    vector<int> rank;
    vector<int> size;

    public:

    DSU(int n){

        _size = n;
        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i]=i;
        }
    }

    int findParent(int node){

        if(node == parent[node])
            return node;
        else
            return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){

        int pu = findParent(u);
        int pv = findParent(v);

        if(pu != pv){
            
            if(rank[pu] < rank[pv]){
                parent[pu] = pv;
            }else if(rank[pu] > rank[pv]){
                parent[pv] = pu;
            }else{
                parent[pv] = pu;
                rank[pu]++;
            }
        }

    }
};


class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        
        //1. Sort the edges by ascending order of weight
        auto sortByDist = [&](vector<int>& v1, vector<int>& v2) {
            return v1[2] < v2[2];   //asc
        };
        sort(edgeList.begin(), edgeList.end(), sortByDist); //Lambda Function

        
        //2. Add index to queries - to maintain the order in answer
        int idx =0;
        for (vector<int> &row: queries){
            row.push_back(idx);
            idx++;
        }
       
        //3. sort queries by ascending order of weight
        auto sortByLimit = [&](vector<int> &v1, vector<int> &v2){
            return v1[2] < v2[2];   //asc
        };
        sort(queries.begin(), queries.end(), sortByLimit);


        vector<bool> ans (queries.size(), false);

        DSU gr(n);
        int edgeIdx =0;
        int edgeListSize = edgeList.size();
        
        /*
        Basically use DSU on the edges less than the limit,
        (use DSU on the edges which are less than the Limit)
        then check if the two nodes have same parent.
        
        If they have same parent , that means 
        both nodes canbe connected with edges less than the limit
        */
        for(int i=0; i<queries.size(); i++){

            int limit = queries[i][2];

            
            while(edgeIdx < edgeListSize && edgeList[edgeIdx][2]<limit){

                int u = edgeList[edgeIdx][0], v = edgeList[edgeIdx][1];

                //cout<<"adding... Idx: "<<edgeIdx<<" "<<u<<"  "<<v<<" wt:"<<edgeList[edgeIdx][2]<<endl;
                //if(gr.findParent(u) != gr.findParent(v)){
                    gr.unionByRank(u,v);
                //}


                edgeIdx++;
            }//while
            
            //cout<<"Not adding... Idx: "<<edgeIdx<<" "<<edgeList[edgeIdx][0]<<"  "<<edgeList[edgeIdx][1]<<" wt:"<<edgeList[edgeIdx][2]<<endl;
            int queryIndex = queries[i][3];
            ans[queryIndex]= gr.findParent(queries[i][0]) == gr.findParent(queries[i][1]);

        }



        return ans;

        /*
            Time Complexity: O(mlogm+qlogq+m+q)
            Space Complexity: O(n+m+q)
        */      
    }
};