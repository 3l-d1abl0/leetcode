/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    
    int agnosticBS(MountainArray &ma, int target, int st, int ed){
        
        
        
        if(st<=ed){
        
            int mid = st + (ed-st)/2;
            
            if(ma.get(mid) == target)
                return mid;
            
            if(ma.get(st)<ma.get(ed)){//asd
                if(target>ma.get(mid))
                    return agnosticBS(ma, target, mid+1, ed);
                else
                    return agnosticBS(ma, target, st, mid-1);
            }else{//desc
                
                if(target>ma.get(mid))
                    return agnosticBS(ma, target, st, mid-1);
                else
                    return agnosticBS(ma, target, mid+1, ed);
            }
            
        }
        
        return -1;
    }
    
    int bitonicPoint(MountainArray &ma){

        int st = 1, ed= ma.length()-2;

        while(st<ed){
            
            int mid = st+(ed-st)/2;

            if(ma.get(mid-1)<ma.get(mid) && ma.get(mid) > ma.get(mid+1))
                return mid;
           
            if(ma.get(mid)>ma.get(mid+1)){//descending slope - mid can be peak
                ed = mid;
            }else{
                st = mid+1;
            }
        }
        
        return st;
    }
    
    int findInMountainArray(int target, MountainArray &ma) {
        
        
        int st =0, ed = ma.length()-1;
        
        int bitonicIdx = bitonicPoint(ma);
        //cout<<bitonicIdx<<endl;

        //If the target is greater than the Peak
        if(target > ma.get(bitonicIdx)) return -1;
        
        int first = agnosticBS(ma, target, st, bitonicIdx-1);//ascending
        //cout<<first<<endl;
        if(first == -1)
            return agnosticBS(ma, target, bitonicIdx, ed);//descending
        
        return first;
    }
};