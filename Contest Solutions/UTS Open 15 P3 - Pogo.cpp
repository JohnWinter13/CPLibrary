#include <iostream>
#include <map>
#define MOD 1000000007
typedef long long ll;

std::map<int, ll> F;
ll M2(int N)
{
    if (N <= 0)
        return 0;
    if (N == 1)
        return 1;
    if (F.find(N) != F.end())
        return F[N];
    return F[N] = (M2(N - 1) + M2(N - 3)) % MOD;
}

std::map<int, ll> a, b, c1, c2, d;
ll A(int N); ll B(int N); ll C1(int N); ll C2(int N); ll D(int N);

ll A(int N)
{
    if (N < 0)
        return 0;
    if (N == 1)
        return 1;
    if (a.find(N) != a.end())
        return a[N];
    return a[N] = ((A(N - 1) + B(N - 2)) % MOD + C1(N - 3)) % MOD;
}

ll B(int N)
{
    if (N <= 0)
        return 0;
    if (b.find(N) != b.end())
        return b[N];
    return b[N] = ((A(N - 2) + C2(N - 3)) % MOD + (D(N - 1) + D(N - 3) % MOD)) % MOD;
}

ll C1(int N)
{
    if (N <= 0)
        return 0;
    if (c1.find(N) != c1.end())
        return c1[N];
    return c1[N] = (A(N - 2) + C2(N)) % MOD;
}

ll C2(int N)
{
    if (N <= 0)
        return 0;
    if (c2.find(N) != c2.end())
        return c2[N];
    return c2[N] = ((A(N - 1) + A(N - 2)) % MOD + (C2(N - 3) + D(N - 1)) % MOD + D(N - 3)) % MOD;
}

ll D(int N)
{
    if (N <= 0)
        return 0;
    if (d.find(N) != d.end())
        return d[N];
    return d[N] = (A(N) + B(N - 1)) % MOD;
}

int main()
{
    int N, M;
    std::cin >> N >> M;
    if (M == 1)
        std::cout << 1 << "\n";
    else if (M == 2)
        std::cout << M2(N) << "\n";
    else
        std::cout << A(N) << "\n";

    return 0;
}
