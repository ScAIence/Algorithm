#include<iostream>

using namespace std;

class Board
{
    private:
    char** board;
    int direction;
    int generation;

    public:
    Board(int n, int x, int d, int g)
    {
        board = (char**)malloc(sizeof(char*)*n);
        for (int i = 0; i < n; i++)
        {
            board[i] = (char*)malloc(sizeof(char)*n);
        }

        direction = d;
        generation = g;
    }

    void 
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int x,y,d,g;

    cin >> n;



}