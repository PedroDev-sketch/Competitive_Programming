# Competitive Programming Notebook

## 1. Geometry Code Library

### Base Template & Primitives
This is the foundation for the geometry algorithms, utilizing `std::complex` to make 2D point operations much simpler.

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using vvll = vector<vll>;
using pll = pair<ll, ll>;
using vpll = vector<pll>;

#define eb emplace_back
#define rep(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define per(i, a, b) for (ll i = (ll)(a); i >= (ll)(b); i--)
#define all(xs) xs.begin(), xs.end()
#define fio cin.tie(0)->ios::sync_with_stdio(0)
#define mp make_pair
#define ff first
#define ss second

// Sign function
ll sgn(ll x) {
    return (x > 0) - (x < 0);
}

// Cross product of vectors `a` and `b` starting from origin
ll cross_product(complex<ll> a, complex<ll> b) {
    return (conj(a) * b).imag();
}

// Cross product of vectors (p - p1) and (p - p2)
ll cross_product(complex<ll> p, complex<ll> p1, complex<ll> p2) {
    return (conj(p - p1) * (p - p2)).imag();
}

// Dot product of vectors (p - p1) and (p - p2)
ll dot_product(complex<ll> p, complex<ll> p1, complex<ll> p2) {
    return (conj(p - p1) * (p - p2)).real();
}
```

### Point Location Test
Determines if a point `p3` is to the left, right, or touching the directed line from `p1` to `p2`.

```cpp
string point_location(complex<ll> p1, complex<ll> p2, complex<ll> p3) {
    ll cp = cross_product(p3, p1, p2);
    if(cp > 0) return "LEFT";
    if(cp < 0) return "RIGHT";
    return "TOUCH";
}
```

### Line Segment Intersection
Checks if two line segments (`p1`-`p2` and `p3`-`p4`) intersect.

```cpp
bool on_segment(complex<ll> p, complex<ll> p1, complex<ll> p2) {
    if(cross_product(p, p1, p2))
        return false;
    bool c1 = p.imag() >= min(p1.imag(), p2.imag()) && p.imag() <= max(p1.imag(), p2.imag());
    bool c2 = p.real() >= min(p1.real(), p2.real()) && p.real() <= max(p1.real(), p2.real());
    return c1 && c2;
}

bool segment_intersection(complex<ll> p1, complex<ll> p2, complex<ll> p3, complex<ll> p4) {
    ll side1 = cross_product(p1, p3, p4), side2 = cross_product(p2, p3, p4);
    ll side3 = cross_product(p3, p1, p2), side4 = cross_product(p4, p1, p2);

    bool check1 = sgn(side1) != sgn(side2) && sgn(side3) != sgn(side4);
    bool check2 = (p1 == p3 || p1 == p4 || p2 == p3 || p2 == p4);
    bool check3 = on_segment(p1, p3, p4) || on_segment(p2, p3, p4) || 
                  on_segment(p3, p1, p2) || on_segment(p4, p1, p2);

    return (check1 || check2 || check3);
}
```

### Polygon Area
Calculates twice the area of a polygon (useful for keeping everything in integers).

```cpp
ll polygon_area_doubled(const vpll& xs) {
    ll n = xs.size();
    ll ans = 0;
    rep(i, 0, n) {
        complex<ll> a{xs[i].ff, xs[i].ss}, b{xs[(i+1)%n].ff, xs[(i+1)%n].ss};
        ans += cross_product(a, b);
    }
    return abs(ans);
}
```

### Point in Polygon
Ray-casting algorithm to determine if a point is inside, outside, or on the boundary of a polygon.

```cpp
// Returns: 0 = OUTSIDE, 1 = INSIDE, 2 = BOUNDARY
ll point_in_polygon(vpll& xs, complex<ll> pt) {
    ll n = xs.size();
    ll ans = 0;
    rep(i, 0, n) {
        ll j = (i + 1) % n;
        complex<ll> a{xs[i].ff, xs[i].ss}, b{xs[j].ff, xs[j].ss};
        
        ll cp = cross_product(pt, a, b); 
        ll dp = dot_product(pt, a, b);   
        
        if(cp == 0 && dp <= 0) return 2; // Boundary check

        if(a.imag() <= pt.imag() && b.imag() > pt.imag()) {
            if(cp > 0) ans = !ans;
        } else if(a.imag() > pt.imag() && b.imag() <= pt.imag()) {
            if(cp < 0) ans = !ans;
        }
    }
    return ans;
}
```

### Polygon Lattice Points (Pick's Theorem)
Finds the number of strict interior and boundary integer points for a lattice polygon.

```cpp
// Returns {interior_points, boundary_points}
pair<ll, ll> polygon_lattice_points(const vpll& xs) {
    ll n = xs.size();
    ll b = 0, area_doubled = 0;
    
    rep(i, 0, n) {
        ll j = (i + 1) % n;
        complex<ll> p1{xs[i].ff, xs[i].ss}, p2{xs[j].ff, xs[j].ss};
        
        b += gcd(abs(p2.imag() - p1.imag()), abs(p2.real() - p1.real()));
        area_doubled += cross_product(p1, p2);
    }    
    
    area_doubled = abs(area_doubled);
    ll a_doubled = area_doubled - b + 2; 
    
    return {a_doubled / 2, b};
}
```

---

## 2. Important Facts

### Complex Numbers for 2D Geometry

Using `std::complex<T>` is a powerful shortcut for 2D point operations:

* Given points $A$ and $B$, the vector $A \to B$ is simply $B - A$.
* **Cross Product (**$A \times B$**):** The 2D cross product of vectors $A$ and $B$ can be extracted using the imaginary part of the conjugate multiplication:
  $$A \times B = \Im(\overline{A} \cdot B)$$
  In code: `(conj(A) * B).imag()`.
* **Dot Product (**$A \cdot B$**):** The dot product can be extracted using the real part:
  $$A \cdot B = \Re(\overline{A} \cdot B)$$
  In code: `(conj(A) * B).real()`.
* **Collinearity & Bounds:** If the cross product of $(P-A)$ and $(P-B)$ is $0$, point $P$ is collinear with segment $AB$. If the dot product of $(P-A)$ and $(P-B)$ is also $\le 0$, then $P$ lies bounded exactly between $A$ and $B$.

### Point Location (Left/Right Turn)

To determine if moving from $P_1 \to P_2 \to P_3$ constitutes a left turn or a right turn:

* Calculate the cross product $C = (P_3 - P_1) \times (P_3 - P_2)$.
* If $C > 0$: The turn is to the **Left** (Counter-Clockwise).
* If $C < 0$: The turn is to the **Right** (Clockwise).
* If $C = 0$: The points are collinear.

### Shoelace Formula (Polygon Area)

The area of a simple polygon with integer coordinates $(x_1, y_1), \dots, (x_n, y_n)$ is given by half the absolute sum of the cross products of adjacent vertices:

$$2 \times \text{Area} = \left\vert \sum_{i=0}^{n-1} (x_i \cdot y_{i+1} - x_{i+1} \cdot y_i) \right\vert$$

*(Note: Wrapping around so $x_n = x_0$)*

### Pick's Theorem & Boundary Points

For any polygon on a grid whose vertices have integer coordinates:

* **Lattice Points on a Segment:** The number of integer points lying strictly on the boundary of a segment between $(x_1, y_1)$ and $(x_2, y_2)$ is:
  $$B_{segment} = \gcd(\vert x_1 - x_2 \vert, \vert y_1 - y_2 \vert)$$
* **Pick's Theorem:** Relates the Area ($A$), Interior lattice points ($I$), and Boundary lattice points ($B$):
  $$A = I + \frac{B}{2} - 1$$
* This can be rearranged to find the interior points purely using integer arithmetic:
  $$I = \frac{2A - B + 2}{2}$$

### Ray Casting (Point in Polygon)

To test if a point $P$ is inside a polygon, cast a horizontal ray extending to the right $(+\infty, y)$.

* Count the number of times the ray intersects the polygon's edges.
* If the count is **odd**, the point is strictly inside.
* If the count is **even**, the point is strictly outside.
* *Edge Case Handling:* Ensure you correctly process vertices touching the ray by checking half-open intervals on edge $y$-coordinates (e.g., $A_y \le P_y < B_y$ or $A_y > P_y \ge B_y$) to avoid double-counting.