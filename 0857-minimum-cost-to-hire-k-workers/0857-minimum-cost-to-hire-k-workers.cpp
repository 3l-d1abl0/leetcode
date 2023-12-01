

class Solution {
public:
    
    double method1(vector<int>& quality, vector<int>& wage, int k) {
        
        
        /*
            TC: O(N) * ( O(N) + O(NlogK) )
            
                O(N^2) + O(N^2 logK)
        */
        
        int N = quality.size();
        double minSum  = 1e9;
        
        for (int idx = 0; idx<N; idx++){
            
            double ratio =  (double)wage[idx] / quality[idx];
            
            vector<double> offer;
            priority_queue<double> mxHeap;
            double totalSum = 0.0;
            int ctr = 0;
            for(int i=0; i<N; i++){
                
                double expectedWage = quality[i] * ratio;
                
                if(expectedWage >= wage[i]){
                    ctr++;
                    offer.push_back(expectedWage);
                
                    if(mxHeap.size() < k){
                        mxHeap.push(expectedWage);
                        totalSum +=expectedWage;
                    }else{
                        
                        if(expectedWage < mxHeap.top() ){
                            
                            totalSum -= mxHeap.top();
                            mxHeap.pop();
                            mxHeap.push(expectedWage);
                            totalSum +=expectedWage;
                        }
                    }
                
                }//if
            }
            
            
            /*Cannot process this scheme with 'idx' as base since less than k worker will be able to get paid
            */
            if(ctr <k)
                continue;    
            else{
                //check if its the min total wage
                minSum  = min(totalSum, minSum);
            }//else
            
            
        }//for idx
        
        
        return minSum;
        
    }
    
    
    struct CompareFn{
            bool operator()( double &a, double &b){
                return a<b; //smallest first
            }
    };

    struct Workers{
      
        int wage;
        int quality;
        
        Workers(int w, int q){
            wage = w;
            quality =q;
        }
    };
    
    double method2(vector<int>& quality, vector<int>& wage, int k){
        
        int N = quality.size();
        
        vector<Workers> sortedRatio;
        for(int i=0; i<N; i++) sortedRatio.push_back(Workers(wage[i], quality[i]));
        
        
        //sort(sortedRatio.begin(), sortedRatio.end(), CompareFn);
        sort(sortedRatio.begin(), sortedRatio.end(), []( Workers &a, Workers &b){
            return ((double)a.wage/a.quality) < (double)b.wage/b.quality ;
        });
        
        
        /*cout<<"N= "<<N<<endl;
        for(int i=0; i<N; i++){
            cout<<sortedRatio[i].wage<<" "<<sortedRatio[i].quality<<endl;
        }
        
        cout<<endl;*/
        
        int runningSum =0;
        priority_queue<double> mxHeap;
        double ans = 1e9;
        for(Workers ele: sortedRatio){
            
            double ratio = (double)ele.wage/ele.quality;
            
            runningSum += ele.quality;
            mxHeap.push(ele.quality);
            
            if(mxHeap.size() >k){
                runningSum -= mxHeap.top();
                mxHeap.pop();
            }
            
            
            //cout<<runningSum<<" * "<<ratio<<" = "<<runningSum * ratio<<endl;
            if(mxHeap.size()  == k){
                ans = min(ans, runningSum * ratio);
                //cout<<"ans ="<<ans<<endl;
            }
        }//for
        
        
        
        return ans;
        
    }
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        
        //Method1
        //return method1(quality, wage, k);
        
        //method2
        return method2(quality, wage, k);
        
    }
};