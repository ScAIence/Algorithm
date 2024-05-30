#include <iostream>

using namespace std;

int n;
int phone1;
int phone2;

int main()
{
    cin >> n;

    int tmp;
    for (int i = 0; i < n; i++)
    {
        cin >> tmp;

        phone1 += (tmp/30+1)*10;
        phone2 += (tmp/60+1)*15;
    }

    // cout << phone1 << ' ' << phone2 << '\n';

    if (phone1 < phone2)
    {
        cout << "Y " << phone1;
    }
    else if (phone1 > phone2)
    {
        cout << "M " << phone2;
    }
    else
    {
        cout << "Y M " << phone1;
    }

}