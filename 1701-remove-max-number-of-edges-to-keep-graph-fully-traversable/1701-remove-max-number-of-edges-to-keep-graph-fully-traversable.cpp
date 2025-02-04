class DSU {

    vector<int> parent;
    vector<int> size;
    vector<int> rank;

    int _size;


    public:
    DSU(int n){

        _size = n;

        parent.resize(n);
        rank.resize(n, 0);
        size.resize(n, 1);

        for(int i=0; i<n; i++){
            parent[i] = i;
        }
    }

    
    
    int findParent(int u){

            if(u == parent[u])
                return u;

            return parent[u] = findParent(parent[u]);
    }


    void merge(int u, int v){

        //merging by size

        int pu = findParent(u);
        int pv = findParent(v);

        if(pu != pv){

            if(size[pu] >= size[pv]){
                parent[pv] = parent[pu];
                size[pu] += size[pv];
            }else{
                parent[pu] = parent[pv];
                size[pv] += size[pu];
            }

            _size--;
        }
    }

    int getSize(){
        return _size;
    }

};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        /*
        Type1 : Alice
        Type2 : Bob
        Type3 : Both 

        Sort the edges such that type 3 is first
        */

       sort(edges.begin(), edges.end(), [](vector<int>& e1, vector<int>& e2){
            return e1[0]>e2[0]; //desc
       });

       /*
       auto compDun = [&](vector<int>& v1, vector<int>& v2) {
            return v1[0] > v2[0];
       };

       sort(edges.begin(), edges.end(), compFn);
       */


        DSU Alice(n);
        DSU Bob(n);


        int usedEdge =0;
        for(auto row: edges){

            if(row[0]==3){ //edge for boths

                bool merged = false;

                if(Alice.findParent(row[1]-1) != Alice.findParent(row[2]-1)){

                    Alice.merge(row[1]-1, row[2]-1);
                    merged = true;
                }

                if(Bob.findParent(row[1]-1) != Bob.findParent(row[2]-1)){

                    Bob.merge(row[1]-1, row[2]-1);
                    merged = true;
                }

                if(merged == true){
                    usedEdge++;
                    //cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<endl;
                }


            }else if(row[0]==2){    //Bob edge

                if(Bob.findParent(row[1]-1) != Bob.findParent(row[2]-1)){

                    Bob.merge(row[1]-1, row[2]-1);
                    usedEdge++;
                    //cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<endl;
                }

            }else{ //Alice edge

                 if(Alice.findParent(row[1]-1) != Alice.findParent(row[2]-1)){

                    Alice.merge(row[1]-1, row[2]-1);
                    usedEdge++;
                    //cout<<row[0]<<" "<<row[1]<<" "<<row[2]<<endl;
                }

            }
        }

        
        cout<<Alice.getSize()<<" "<<Bob.getSize()<<endl;
            
        if(Alice.getSize()==1 && Bob.getSize()==1)
            return edges.size() - usedEdge;

       return -1;
    }
};