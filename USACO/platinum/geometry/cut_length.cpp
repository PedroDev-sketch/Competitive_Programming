#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll = double; 
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define per(i, a, b) for (int i = (int)(a); i >= (int)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

const ll MOD = 1e9+7;

int sgn(ll num)
{
    if(num > 1e-9)
        return 1;
    else if(abs(num) <= 1e-9)
        return 0;
    else 
        return -1;
}

complex<ll> cross_product(complex<ll> a, complex<ll> b)
{
    return (conj(a)*b);
}

bool inside(complex<ll> pt, vpll& cd, int n)
{
    bool ans = false;
    
    double px = pt.real(), py = pt.imag();
    double a_real = cd[n-1].ff, a_imag = cd[n-1].ss;
    
    rep(i, 0, n)
    {
        double b_real = cd[i].ff, b_imag = cd[i].ss;
        
        double cp_imag = (px - a_real) * (py - b_imag) - (py - a_imag) * (px - b_real);
        double cp_real = (px - a_real) * (px - b_real) + (py - a_imag) * (py - b_imag);
        
        if(abs(cp_imag) <= 1e-9 && cp_real <= 1e-9) return true;

        ll ret = cp_imag;

        if(a_imag <= py && b_imag > py)
        {
            if(ret > 0)
                ans = !ans;
        }
        else if(a_imag > py && b_imag <= py)
        {
            if(ret < 0)
                ans = !ans;
        }
        
        a_real = b_real;
        a_imag = b_imag;
    }

    return ans;
}

long double get_intersection_length(complex<ll> pt1, complex<ll> pt2, vpll& cd, int n)
{
    double v_x = pt2.real() - pt1.real();
    double v_y = pt2.imag() - pt1.imag();
    double p1_x = pt1.real(), p1_y = pt1.imag();
    
    double len_v_sq = v_x * v_x + v_y * v_y;
    double len_v = sqrt(len_v_sq);
    
    auto get_side = [&](double x, double y) {
        double cross = v_x * (y - p1_y) - v_y * (x - p1_x);
        if (cross > 1e-5) return 1;
        if (cross < -1e-5) return -1;
        return 0;
    };
    
    vector<double> cross_k;
    vector<pair<double, double>> intervals;
    
    double cx = cd[n-1].ff, cy = cd[n-1].ss;
    int sc = get_side(cx, cy);
    
    rep(i, 0, n)
    {
        double dx = cd[i].ff, dy = cd[i].ss;
        int sd = get_side(dx, dy);
        
        if (sc == 0 && sd == 0) {
            double kc = ((cx - p1_x) * v_x + (cy - p1_y) * v_y) / len_v_sq;
            double kd = ((dx - p1_x) * v_x + (dy - p1_y) * v_y) / len_v_sq;
            intervals.eb(min(kc, kd), max(kc, kd));
        } 
        else if ((sc > 0) != (sd > 0)) {
            double den = v_x * (cy - dy) - v_y * (cx - dx);
            if (abs(den) > 1e-9) { 
                double num = v_x * (cy - p1_y) - v_y * (cx - p1_x);
                double s = num / den;
                double px = cx + s * (dx - cx);
                double py = cy + s * (dy - cy);
                double k = ((px - p1_x) * v_x + (py - p1_y) * v_y) / len_v_sq;
                cross_k.eb(k);
            }
        }
        
        cx = dx; cy = dy;
        sc = sd; 
    }
    
    sort(all(cross_k));
    for (size_t i = 0; i + 1 < cross_k.size(); i += 2) {
        intervals.eb(cross_k[i], cross_k[i+1]);
    }
    
    if (intervals.empty()) return 0.0;
    
    sort(all(intervals));
    long double total_k = 0;
    double cur_start = intervals[0].ff;
    double cur_end = intervals[0].ss;
    
    rep(i, 1, intervals.size()) {
        if (intervals[i].ff > cur_end + 1e-9) {
            total_k += cur_end - cur_start;
            cur_start = intervals[i].ff;
            cur_end = intervals[i].ss;
        } else {
            cur_end = max(cur_end, intervals[i].ss);
        }
    }
    total_k += cur_end - cur_start;
    
    return total_k * len_v;
}

void solve()
{
    int n, m; cin >> n >> m;
    vpll cd(n); 
    for (auto& p : cd) cin >> p.ff >> p.ss;
    
    while(m--)
    {
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        complex<ll> pt1{x1, y1}, pt2{x2, y2};

        long double ans = get_intersection_length(pt1, pt2, cd, n);

        cout << fixed << setprecision(20) << ans << '\n';
    }
}

signed main()
{
    fio;
    int t = 1;
    //cin >> t;
    while (t--)
        solve();
}