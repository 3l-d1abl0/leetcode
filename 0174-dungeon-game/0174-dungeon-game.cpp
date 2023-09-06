class Solution {
public:
    
    int recur(int i, int j, vector<vector<int>> &dungeon, int &R, int &C, vector<vector<int>> &memo){
        
        if(i>=R || j>=C)
            return INT_MAX;
        
        if(i==R-1 && j==C-1){
            
            if(dungeon[i][j]<=0)
                return -dungeon[i][j] +1;   //just 1 more the required to avoid zero health
            else
                return 1;  //if positive we just need 1 health
        }
        
        if(memo[i][j]!=-1)
            return memo[i][j];
        
        
        int goRight= recur(i, j+1, dungeon, R, C, memo);
        int goDown= recur(i+1, j, dungeon, R, C, memo);
        
        //cout<<min(goRight, goDown)<<" "<<endl;
        //How much you need currently
        //Spend the energy obtained from current cell for the next cell
        int currentEnergy =0;
        //if(dungeon[i][j]==0)    //cant take any enery from current cell
          //  currentEnergy = min(goRight, goDown);
        //else
            currentEnergy = dungeon[i][j] - min(goRight, goDown);
        
        
        if(currentEnergy<0){
            //cout<<i<<" "<<j<<" ---> "<<-currentEnergy<<endl;
            return memo[i][j] = -currentEnergy;
        }else{
            //cout<<i<<" "<<j<<" --> "<<1<<endl;
            return memo[i][j] = 1;
        }
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        
        int R= dungeon.size();
        int C= dungeon[0].size();
        
        vector<vector<int>> memo(R, vector<int>(C, -1));
        
        return recur(0, 0, dungeon, R, C, memo);
        
    }
};