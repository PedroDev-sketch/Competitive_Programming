#include <bits/stdc++.h>
using namespace std;

const double PI { acos(-1.0) };

void fft(vector<complex<double>>& xs, bool invert = false)
{
    int N = (int) xs.size();

    if(N == 1) return;

    vector<complex<double>> es(N/2), os(N/2);

    for(int i = 0; i < N/2; i++) es[i] = xs[2*i];
    for(int i = 0; i < N/2; i++) os[i] = xs[2*i + 1];

    fft(es, invert);
    fft(os, invert);

    auto signal = (invert ? 1 : -1);
    auto theta = 2 * signal * PI/N;

    complex<double> S { 1 }, S1 { cos(theta), sin(theta) };

    for(int i = 0; i < N/2; i++)
    {
        xs[i] = (es[i] + S * os[i]);
        xs[i] /= (invert ? 2 : 1);

        xs[i + N/2] = (es[i] - S * os[i]);
        xs[i + N/2] /= (invert ? 2 : 1);

        S *= S1;
    }
}

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
    vector<complex<double>> fa(a.begin(), a.end()), fb(b.begin(), b.end());

    int n = 1;
    while(n < a.size() + b.size())
    {
        n <<= 1;
    }

    fa.resize(n);
    fb.resize(n);

    fft(fa, false);
    fft(fb, false);

    for(int i = 0; i < n; i++)
    {
        fa[i] *= fb[i];
    }
    fft(fa, true);

    vector<int> result(n);
    for(int i = 0; i < n; i++)
    {
        result[i] = round(fa[i].real());
    }

    int carry = 0;
    for(int i = 0; i < n; i++)
    {
        result[i] += carry;
        carry = result[i]/10;
        result[i] %= 10;
    }

    return result;
}

signed main()
{
    cin.tie(0) -> ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
    {    
        string sa, sb;
        cin >> sa >> sb;

        reverse(sa.begin(), sa.end());
        reverse(sb.begin(), sb.end());

        vector<int> a(sa.size()), b(sb.size());
        
        for(size_t i = 0; i < sa.size(); i++)
            a[i] = sa[i]-'0';

        for(size_t i = 0; i < sb.size(); i++)
            b[i] = sb[i]-'0';

        vector<int> result = multiply(a, b);

        string ans = "";

        auto it1 = result.end() - 1;
        while(*it1 == 0 && it1 != result.begin())
        {
            result.erase(it1);
            it1--;
        }

        for(auto it = result.rbegin(); it != result.rend(); it++)
        {
            ans += (*it + '0');
        }

        cout << ans << '\n';
    }

    return 0;
}