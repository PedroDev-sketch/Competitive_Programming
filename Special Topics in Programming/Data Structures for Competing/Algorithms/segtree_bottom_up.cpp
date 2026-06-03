#include <bits/stdc++.h>
using namespace std;

#define all(xs) xs.begin(), xs.end()

//This tree will only work if N is a power of 2

template<typename T>
class SegmentTree
{
    int N;
    vector<T> ns;

public:
    SegmentTree(const vector<T>& xs) : N(xs.size()), ns(2*N, 0)
    {
        copy(all(xs), ns.begin() + N);

        for(int i = N - 1; i > 0; i--)
            ns[i] = ns[2*i] + ns[2*i + 1];
    }

    T RSQ(int i, int j)
    {
        int a = i + N, b = j + N;
        T s = 0;

        while(a <= b)
        {
            if(a & 1)
                s += ns[a++];
            if(!(b&1))
                s += ns[b--];
            
            a /= 2;
            b /= 2;
        }

        return s;
    }

    void update(int i, T value)
    {
        int a = i + N;

        ns[a] += value;

        while(a >>= 1)
        {
            ns[a] = ns[2*a] + ns[2*a + 1];
        }
    }
};