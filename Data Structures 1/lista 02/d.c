#include <stdio.h>
#include <string.h>

int mark_x(char str[], int source, size_t size, int numofx)
{
    if(source == size)
    {
        return numofx;
    }

    if(str[source] == 'x')
    {
        return mark_x(str, source+1, size, numofx+1);
    }
    else return mark_x(str, source+1, size, numofx);
}

char* remove_x(char str[], char newstr[], int addchar, int source, size_t size)
{
    if(source == size)
    {
        newstr[addchar] = '\0';
        return newstr;
    }

    if(str[source] == 'x')
    {
        return remove_x(str, newstr, addchar, source+1, size);
    }
    else
    {
        newstr[addchar] = str[source];
        return remove_x(str, newstr, addchar+1, source+1, size);
    } 
}

void recursive_print(int num)
{
    if(num>0) printf("x");
    else return;

    recursive_print(num-1);
}

int main()
{
    char str[101];
    scanf("%s", str);

    size_t size = strlen(str);

    char newstr[101];
    remove_x(str, newstr, 0, 0, size);
    
    int numofx = mark_x(str, 0, size, 0);
    
    printf("%s", newstr);
    recursive_print(numofx);

    return 0;
}