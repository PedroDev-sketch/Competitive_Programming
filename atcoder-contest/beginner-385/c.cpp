#include <bits/stdc++.h>
using namespace std;

signed main()
{
  int n, ans=1;
  cin >> n;
  
  vector<int> b(n);
  
  for(auto& p : b)
  {
    cin >> p;
  }
  
  for(int i = 1; i <= n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      int height = 0, dist = 0;
      for(int k = j; k < n; k+=i)
      {
        if(b[k] != height) dist = 0;
        height = b[k];
        dist++;
        ans = max(ans, dist);
      }
    }
  }
  
  cout << ans << '\n';

  return 0;
}