#include <stdio.h>

int solve(int n)
{
    if(n >= 101) return n - 10;
    else
    {
        int ans = solve(solve(n+11));
        return ans;
    }
}

int main()
{
    int n;
    while(scanf("%d", &n), n != 0)
    {
        int ans = solve(n);
        printf("f91(%d) = %d\n", n, ans);
    }

    return 0;
}