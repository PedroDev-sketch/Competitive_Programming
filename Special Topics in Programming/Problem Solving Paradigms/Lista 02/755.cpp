#include <bits/stdc++.h>
using namespace std;
#define int long long

int counter= 0;

void backtrack(string snum, const int& num)
{
    if(!snum.empty())
        if(stoll(snum) > num) return;

    if(snum.find("3") != string::npos && snum.find("5") != string::npos && snum.find("7") != string::npos) counter++;

    backtrack(snum+"3", num);
    backtrack(snum+"5", num);
    backtrack(snum+"7", num);
}

signed main()
{
    int num;
    cin >> num;

    backtrack("", num);

    cout << counter << '\n';
}