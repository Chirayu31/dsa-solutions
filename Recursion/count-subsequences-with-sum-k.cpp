#include <iostream>
#include <vector>
using namespace std;

int printSub(int idx, vector<int> arr, vector<int> &ds, int n, int k, int currSum)
{
    if (idx >= n)
    {
        if (currSum == k)
        {
            return 1;
        }
        return 0;
    }

    currSum += arr[idx];
    ds.push_back(arr[idx]);
    int l = printSub(idx + 1, arr, ds, n, k, currSum);

    currSum -= arr[idx];
    ds.pop_back();
    int r = printSub(idx + 1, arr, ds, n, k, currSum);

    return l + r;
}

int main()
{
    int n, k, idx = 0;
    cin >> n >> k;
    vector<int> arr(n, 0), ds;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int currSum = 0;
    cout << printSub(idx, arr, ds, n, k, currSum);
}