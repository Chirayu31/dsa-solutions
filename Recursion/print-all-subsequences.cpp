#include <iostream>
#include <vector>
using namespace std;

void printSubseq(vector<int> arr, int idx, vector<int> &ds, int n)
{
    if (idx >= n)
    {
        for (auto it : ds)
            cout << it << " ";
        cout << endl;
        return;
    }

    ds.push_back(arr[idx]);
    printSubseq(arr, idx + 1, ds, n);
    ds.pop_back();
    printSubseq(arr, idx + 1, ds, n);
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ds;
    printSubseq(arr, 0, ds, n);
}