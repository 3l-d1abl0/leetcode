class Solution {
public:


    int calculateGroup(unordered_map<int, int> &mp, int size){

        int groupCount = 0;

        for(auto &[num, freq]: mp){

            int groups = freq/size;
            int remaining = freq%size;


            if(remaining ==0){
                groupCount += groups;
            }else if( (size-1-remaining) <= groups ){
                /* If remaining is !=0
                   try making it a new group of size-1,
                   borrow 1 element from each of the 'groups'
                   hence the total group becomes groups+1

                   if not then its not possible to make 
                   groups with size-1 nd size 
                
                */

                groupCount +=(groups+1);
            }else{
                return -1;
            }
        }//for

        return groupCount;

    }// calculateGroup



    int minGroupsForValidAssignment(vector<int>& balls) {
        
        unordered_map<int, int> mp;
        for(int ball: balls)
            mp[ball] +=1;


        int minFreq = 1e9;
        for(auto &[num,freq] : mp) 
           minFreq = min(minFreq,freq);


        /*
        
            best case : groups are of size minF , minF+1

            other cases: 1, 1+1
                         2, 2+1
                         3, 3+1
                         4, 4+1
                         5, 5+1
                         ...
                         minF, minF+1
        */

        int totalGroups = 1e9;
        for(int size=1; size<=minFreq; size++){ //try tocreate Group of Size: size+1(primary), size(secondary)

            int groupSize = calculateGroup(mp, size+1);

            if(groupSize != -1)
                totalGroups = min(groupSize, totalGroups);


        }


        return totalGroups == 1e9 ? -1: totalGroups;
    }
};