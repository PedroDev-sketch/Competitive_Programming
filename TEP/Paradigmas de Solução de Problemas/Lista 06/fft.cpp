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