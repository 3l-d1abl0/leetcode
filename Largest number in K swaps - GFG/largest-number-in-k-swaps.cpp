// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    
    void calcMaxNumAfterSwap(int idx, string number, int k, string &maxString, int N)
    {

        if (k == 0)
            return;

        char charMax = number[idx];

        // Find the largest character to swap
        for (int i = idx + 1; i < N; i++)
        {
            if (number[i] > charMax)
            {
                charMax = number[i];
            }
        }

        if (charMax != number[idx])
            k--;

        for (int i = N - 1; i >= idx; i--)
        {

            if (charMax == number[i])
            {
                swap(number[idx], number[i]);

                if (number.compare(maxString) > 0)
                {
                    maxString = number;
                    // cout << "Maxx" << maxString << endl;
                }

                calcMaxNumAfterSwap(idx + 1, number, k , maxString, N);
                swap(number[idx], number[i]);
            }
        }
    }

    // Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
        // code here.

        int size = str.length();
        string maxString = str;
        calcMaxNumAfterSwap(0, str, k, maxString, size);

        return maxString;
    }
    
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends