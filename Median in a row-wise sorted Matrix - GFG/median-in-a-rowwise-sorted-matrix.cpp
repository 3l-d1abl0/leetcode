// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:

    int lessthan(vector<vector<int>> &mat, int num)
{

    int cnt = 0;
    int N = mat.size();
    int M = mat[0].size();

    for (int i = 0; i < N; i++)
    {

        int l = 0, r = M - 1;
        while (l <= r)
        {

            int mid = l + (r - l) / 2;

            if (mat[i][mid] < num)
            {
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }

        // cout << l << " -- " << r << "\n";
        cnt += l;
    }

    return cnt;
}


    int median(vector<vector<int>> &mat, int N, int M){
        // code here       
        
        
    /*int N = mat.size();
    int M = mat[0].size();*/

    int l = 0, r = 1e5;

    int median = (N * M) / 2;

    while (r - l > 1)
    {

        int mid = l + (r - l) / 2;

        int cnt = lessthan(mat, mid);

        if (cnt > median)
            r = mid;
        else
            l = mid;
    }
    //cout << l << " -- " << r << "\n";
    return l;
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends