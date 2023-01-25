#include <iostream>
using namespace std;

void parameterizedSum(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return;
    }
    parameterizedSum(i - 1, sum + i);
}

int functionalSum(int n)
{
    if (n == 0)
        return 0;
    return n + functionalSum(n - 1);
}

int main()
{
    // parameterizedSum(5, 0);
    cout << functionalSum(5);
}