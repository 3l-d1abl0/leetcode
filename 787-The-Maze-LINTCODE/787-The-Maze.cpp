class Solution {
public:
    /**
     * @param maze: the maze
     * @param start: the start
     * @param destination: the destination
     * @return: whether the ball could stop at the destination
     */
    bool hasPath(vector<vector<int>> &maze, vector<int> &start, vector<int> &des) {
        // write your code here

        int N = maze.size();
        int M = maze[0].size();

        vector<vector<bool>> vis(N, vector<bool>(M, false));

        queue<tuple<int, int>> q;

        q.push({start[0], start[1]});

        vis[start[0]][start[1]]=true;

        while(!q.empty()){

            auto[x,y] = q.front(); q.pop();

            if(des[0]==x && des[1]==y)  return true;
            
             cout<<x<<" "<<y<<endl;

            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};

            int newX, newY;

            for(int i=0; i<4; i++){

                newX = x, newY = y;
                //cout<<"--> "<<newX<<" "<<newY<<endl;

                while(newX >=0 && newX < N && newY >=0 && newY <M && maze[newX][newY]!=1){

                    newX += dx[i];  newY += dy[i];
                }

                //hit a wall OR 1
                newX -=dx[i];   newY -= dy[i];
                //cout<<"x,y "<<newX<<" "<<newY<<endl;

                if(vis[newX][newY] == true) continue;

                vis[newX][newY]=true;

                q.push({newX, newY});

            }

        }//while


        return false;

    }
};