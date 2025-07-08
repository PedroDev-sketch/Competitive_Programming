#include <stdio.h>

int pa_buffer(int *v, int primeiro, int ultimo, int comp)
{
    if(primeiro >= ultimo) return 1;
    
    if(v[primeiro] + v[ultimo] != comp) return 0;

    pa_buffer(v, primeiro+1, ultimo-1, v[primeiro] + v[ultimo]);
}

int pa_recursiva(int *v, int primeiro, int ultimo)
{
    int ans = pa_buffer(v, primeiro+1, ultimo-1, v[primeiro] + v[ultimo]);
    return ans;
}
