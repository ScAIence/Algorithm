#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int long_time;
    cin >> long_time;
    long_time/=4;

    while(long_time--)
        cout << "long ";
    cout << "int";
}