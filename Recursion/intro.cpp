#include <iostream>
using namespace std;

void f(int &cnt)
{
    if (cnt == 18516)
        return;
    cnt++;
    cout << cnt << " ";
    f(cnt);
}

int main()
{
    int cnt = 0;
    f(cnt);
}