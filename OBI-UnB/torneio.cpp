#include <bits/stdc++.h>
using namespace std;

int main()
{
    char res;
    int count = 0;
    for(int i = 0; i < 6; i++){cin >> res;if(res == 'V') count++;}
    if(count > 4) cout << 1;
    else if(count > 2) cout << 2;
    else if(count > 0) cout << 3;
    else cout << -1;
    return 0;
}