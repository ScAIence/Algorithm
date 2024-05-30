#include <iostream>
#include <algorithm>

using namespace std;

int nums[10];
int mini = 101;

int main()
{
    int x;
    int cnt = 0;
    for (int i = 0; i < 7; i++)
    {
        cin >> x;
        if (x%2==1)
        {
            mini = min(mini, x);
            nums[cnt] = x;
            cnt++;
        }
    }

    int ans = 0;

    if (cnt == 0)
    {
        cout << -1;
        return 0;
    }

    for (int i = 0; i < cnt; i++)
    {
        ans += nums[i];
    }

    cout << ans << '\n' << mini;
}