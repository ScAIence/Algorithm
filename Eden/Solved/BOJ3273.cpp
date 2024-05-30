#include <iostream>
#include <algorithm>

using namespace std;

int n;
int x;
int arr[100003];

int main()
{
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cin >> x;

    sort(arr, arr+n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (binary_search(arr, arr+n, x-arr[i]))
            ans++;
    }

    cout << ans/2;
}