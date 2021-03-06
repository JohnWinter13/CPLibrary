#include <iostream>
#include <map>
#include <unordered_set>
typedef long long ll;
using namespace std;
const int MAX = 1000;
int f[MAX] = { 0 };

ll fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1 || n == 2)
        return (f[n] = 1);

    if (f[n])
        return f[n];

    int k = (n & 1) ? (n + 1) / 2 : n / 2;

    f[n] = (n & 1) ? (fib(k) * fib(k) + fib(k - 1) * fib(k - 1))
                   : (2 * fib(k - 1) + fib(k)) * fib(k);

    return f[n];
}

int main()
{
    int n;
    std::cin >> n;
    unordered_set<ll> nums;
    for (int i = 1; i <= 1001; i++)
        nums.insert(fib(i));
    for (int i = 1; i <= n; i++) {
        if (nums.find(i) != nums.end())
            std::cout << "O";
        else
            std::cout << "o";
    }
    return 0;
}
