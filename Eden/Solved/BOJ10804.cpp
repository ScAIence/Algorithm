#include <iostream>
#include <algorithm>

using namespace std;

int card[23];

int main()
{
    for (int i = 1; i < 21; i++)
    {
        card[i] = i;
    }

    for (int _ = 0; _ < 10; _++)
    {
        int a, b;
        cin >> a >> b;

        for (int i = 0; i <= (b-a)/2; i++)
        {
            swap(card[a+i], card[b-i]);
        }
    }

    for (int i = 1; i <= 20; i++)
    {
        cout << card[i] << ' ';
    }
}