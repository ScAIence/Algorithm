#include <iostream>

using namespace std;

int main() {
    long long ans = 0;

    for (int i = 0; i < 3; i++)
    {
        long long x;
        cin >> x;
        ans += x;
    }

    cout << ans;
}