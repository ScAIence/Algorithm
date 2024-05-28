#include<iostream>
#include<string>

using namespace std;

int main()
{
    string in;
    getline(cin, in);
    for (int i = 0; i < in.length(); i++)
    {
        if ('A' <= in[i] && in[i] <= 'Z') 
        {
            in[i] += 32;
        }
        else
        {
            in[i] -= 32;
        }

    }
    cout << in;
}