#include <iostream>
using namespace std;

void print(int &i, int n)
{
    if (i >= n)
        return;
    cout << ++i << " ";
    print(i, n);
}

void printRev(int &i, int n)
{
    if (i <= 0)
        return;
    cout << i-- << " ";
    printRev(i, n);
}

int main()
{
    int cnt, n;

    cin >> n;
    cnt = n;
    printRev(cnt, n);
}