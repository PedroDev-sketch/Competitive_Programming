#include <stdio.h>
#include <string.h>

int main()
{
    char a[21], b[21];
    scanf("%s %s", a, b);
    int num = 0;
    if(strcmp(a, "norte") == 0)
    {
        if(strcmp(b, "sul") == 0) num = 1;
        else if(strcmp(b, "leste") == 0 || strcmp(b, "oeste") == 0) num = 2;
    }
    else if(strcmp(a, "sul") == 0)
    {
        if(strcmp(b, "norte") == 0) num = 1;
        else if(strcmp(b, "leste") == 0 || strcmp(b, "oeste") == 0) num = 2;
    }
    else if(strcmp(a, "leste") == 0)
    {
        if(strcmp(b, "oeste") == 0) num = 1;
        else if(strcmp(b, "norte") == 0 || strcmp(b, "sul") == 0) num = 2;
    }
    else if(strcmp(a, "oeste") == 0)
    {
        if(strcmp(b, "leste") == 0) num = 1;
        else if(strcmp(b, "norte") == 0 || strcmp(b, "sul") == 0) num = 2;
    }

    if(num == 1) printf("180\n");
    else if(num == 2) printf("90\n");
    else printf("0\n");

    return 0;
}