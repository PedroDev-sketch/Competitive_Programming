#include <stdio.h>

void solve(int array[], int n, int mid, int nump)
{
    if(!n) return;
    if(mid>=0 && mid < nump) array[mid] = n;

    solve(array, n-1, mid/2, nump);
    solve(array, n-1, (nump+mid)/2, nump);
}

void recursive_char_print(int source, int num)
{
    if(source == num) return;
    
    printf("-");

    recursive_char_print(source+1, num);
}

void recursive_string_print(int array[], int source, int nump)
{
    if(source == nump) return;

    printf(".");
    recursive_char_print(0, array[source]);
    printf("\n");
    
    recursive_string_print(array, source+1, nump);
}

int main()
{
    int n;
    scanf("%d", &n);

    int nump = 1 << n;
    nump -= 1;

    int array[nump];
    int mid = nump/2;

    solve(array, n, mid, nump);
    recursive_string_print(array, 0, nump);

    return 0;
}