#include <iostream>
using namespace std;

bool can_balance(int a, int b) {
    if(a == 0)
    {
        if(b == 0) return true;
        else if(b == 1) return false;
        else if(b == 2) return true;
        else if(b == 3) return false;
        else if(b == 4) return true;
        else if(b == 5) return false;
        else if(b == 6) return true;
        else if(b == 7) return false;
        else if(b == 8) return true;
        else if(b == 9) return false;
    }
    else if(a == 1)
    {
        return false;
    }
    else if(a == 2)
    {
        if(b == 0) return true;
        else if(b == 1) return true;
        else if(b == 2) return true;
        else if(b == 3) return true;
        else if(b == 4) return true;
        else if(b == 5) return true;
        else if(b == 6) return true;
        else if(b == 7) return true;
        else if(b == 8) return true;
        else if(b == 9) return true;
    }
    else if(a == 3)
    {
        return false;
    }
    else if(a == 4)
    {
        if(b == 0) return true;
        else if(b == 1) return true;
        else if(b == 2) return true;
        else if(b == 3) return true;
        else if(b == 4) return true;
        else if(b == 5) return true;
        else if(b == 6) return true;
        else if(b == 7) return true;
        else if(b == 8) return true;
        else if(b == 9) return true;
    }
    else if(a == 5)
    {
        return false;
    }
    else if(a == 6)
    {
        if(b == 0) return true;
        else if(b == 1) return true;
        else if(b == 2) return true;
        else if(b == 3) return true;
        else if(b == 4) return true;
        else if(b == 5) return true;
        else if(b == 6) return true;
        else if(b == 7) return true;
        else if(b == 8) return true;
        else if(b == 9) return true;
    }
    else if(a == 7)
    {
        return false;
    }
    else if(a == 8)
    {
        if(b == 0) return true;
        else if(b == 1) return true;
        else if(b == 2) return true;
        else if(b == 3) return true;
        else if(b == 4) return true;
        else if(b == 5) return true;
        else if(b == 6) return true;
        else if(b == 7) return true;
        else if(b == 8) return true;
        else if(b == 9) return true;
    }
    else if(a == 9)
    {
        return false;
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int a, b;
        cin >> a >> b;
        
        if (can_balance(a, b)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}
