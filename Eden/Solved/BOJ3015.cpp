#include <iostream>
#include <stack>

using namespace std;

int n;
int conti[500003];
long long ans = 0;
stack<pair<int, int>> s;

void execute(int x, int i)
{
    if (s.empty())
    {
        s.push({i,x});
    }
    else if (x < s.top().second)
    {
        ans++;
        conti[i]++;
        s.push({i,x});
    }
    else if (x > s.top().second)
    {
        ans++;
        s.pop();
        execute(x, i);
    }
    else if (x == s.top().second)
    {
        conti[i] = conti[s.top().first] + 1;
        ans += conti[i];
        s.push({i,x});
    }
}

int main()
{
    cin >> n;
    int x;


    for (int i = 0; i < n; i++)
    {
        cin >> x;

        execute(x,i);

    }

    cout << ans;
}
