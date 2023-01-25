#include <iostream>
using namespace std;

void print(string name, int n, int &cnt)
{
    if (cnt >= n)
        return;
    cout << name << " ";
    cnt++;
    print(name, n, cnt);
}

int main()
{
    string name;
    int n, cnt = 0;
    cin >> name >> n;
    print(name, n, cnt);
}