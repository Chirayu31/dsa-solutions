#include <bits/stdc++.h>
using namespace std;

void printSub(int idx, vector<int> arr, vector<int> &ds, int n, int k, int currSum)
{
    if (idx >= n)
    {
        if (currSum == k)
        {
            for (auto it : ds)
            {
                cout << it << " ";
            }
            cout << endl;
        }
        return;
    }

    currSum += arr[idx];
    ds.push_back(arr[idx]);
    printSub(idx + 1, arr, ds, n, k, currSum);
    currSum -= arr[idx];
    ds.pop_back();
    printSub(idx + 1, arr, ds, n, k, currSum);
}

int main()
{
    int n, k, idx = 0;
    cin >> n >> k;
    vector<int> arr(n, 0), ds;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int currSum = 0;
    printSub(idx, arr, ds, n, k, currSum);
}