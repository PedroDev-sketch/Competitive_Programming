#include <stdio.h>

int main()
{
    int ia, ib, fa, fb;
    scanf("%d %d %d %d", &ia, &ib, &fa, &fb);

    int count = 0;

    while(ia != fa || ib != fb)
    {
        if(ia != fa && ib == fb) {
            count++;
            ia = !ia;
        }

        if(ib != fb) {
            count++;
            ia = !ia;
            ib = !ib;
        }
    }

    printf("%d\n", count);
    return 0;
}
