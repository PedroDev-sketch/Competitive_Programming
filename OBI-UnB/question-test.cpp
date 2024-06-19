#include <bits\stdc++.h>
using namespace std;

int main()
{
    string nameInquiry { "Enter your full name: " }, name {};
    cout << nameInquiry;
    getline(cin >> ws, name);

    string ageInquiry { "Enter your age: " };
    int age;
    cout << ageInquiry;
    cin >> age;

    string ans { "Your age + length of name is: " };
    cout << ans << age + name.length();

    return 0;
}