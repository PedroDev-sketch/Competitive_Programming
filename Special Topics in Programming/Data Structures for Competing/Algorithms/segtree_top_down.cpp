#include <bits/stdc++.h>
using namespace std;

// At the expense of some performance, both time and memory wise, this tree gives leeway to any sort of N

template<typename T>
class SegmentTree
{
    int N;
    vector<T> ns;

public:
    SegmentTree(const vector<T>& xs) : N(xs.size()), ns(4*N, 0)
    {
        for(size_t i = 0; i < xs.size(); i++)
            update(i, xs[i]);
    }

    void update(int i, T value)
    {
        update(1, 0, N - 1, i, value);
    }

private:
    void update(int node, int L, int R, int i, T value)
    {
        if(i > R || i < L)
            return;
        
        ns[node] += value;

        if(L==R)
            return;

        update(2*node, L, (L+R)/2, i, value);
        update(2*node + 1, (L+R)/2 + 1, R, i, value);
    }

public:
    T RSQ(int a, int b)
    {
        return RSQ(1, 0, N-1, a, b);
    }

private:
    T RSQ(int node, int L, int R, int a, int b)
    {
        if(a > R || b < L)
            return 0;

        if(a <= L && R <= b)
            return ns[node];

        T x = RSQ(2*node, L, (L + R)/2, a, b);
        T y = RSQ(2*node + 1, (L + R)/2 + 1, R, a, b);

        return x+y;
    }
};