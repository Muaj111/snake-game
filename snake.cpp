#include <bits/stdc++.h>
#include<conio.h>
#include <cstdlib>
using namespace std;
typedef long long ll;
bool gameOver;
const int w = 20;
const int h = 20;
int x, y, fx, fy, score;
enum eDirection
{
    Stop = 0,
    Left,
    Right,
    Up,
    Down
};
eDirection dir;

void setUp()
{
    gameOver = false;
    dir = Stop;
    x = w / 2;
    y = h / 2;
    fx = rand() % w;
    fy = rand() % h;
    score = 0;
}
void draw()
{
    system("cls");
    for (int i = 0; i < w + 1; i++)
    {
        cout << "# ";
    }
    cout << endl;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w*2; j++)
        {
            if (j == 0)
                cout << "#";
            if(i==y && j==x)
                cout<<"O";
            else if(i==fy && j==fx)
                cout<<"X";
            else
                cout << " ";
            if (j == w*2-2 )
                cout << "#";
        }
        cout << endl;
    }
    for (int i = 0; i < w + 1; i++)
    {
        cout << "# ";
    }
    cout << endl;
}
void input()
{
    if(_kbhit()){
        switch (_getch())
        {
        case 'a':
            dir =Left;
            break;
        case 'd':
            dir =Right;
            break;
        case 'w':
            dir =Up;
            break;
        case 's':
            dir =Down;
            break;
        case 'x':
            gameOver=true;
            break;
        
        
        }
    }
}
void logic()
{

switch (dir)
{
case Left:
    /* code */
    x--;
    break;
case Right:
    /* code */
    x++;
    break;
case Up:
    /* code */
    y--;
    break;
case Down:
    /* code */
    y++;
    break;

default:
    break;
}
if(x>w*2|| x<-1 ||y>h+2||y<-1)
gameOver=true;
if(x==fx && y==fy){
    score +=10;
     fx = rand() % w;
    fy = rand() % h;
}






}

int main()
{
    
        setUp();
        while (!gameOver)
        {
            draw();
            input();
            logic();
            _sleep(10);
        }
    
}