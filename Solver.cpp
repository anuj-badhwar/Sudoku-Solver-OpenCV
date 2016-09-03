#include<iostream>
using namespace std;

int grid[9][9] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

bool isUnassigned(int &row,int &col)
{
       for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] == 0)
             return true;
        }
    return 0;
}

/*bool isValid(int row,int col,int n){

for(int i=0;i<9;i++)
    {
        if(n==grid[row][i])
            return 0;
    }

for(int i=0;i<9;i++)
    {
        if(n==grid[i][col])
            return 0;
    }

//int i=(row/3)*3;
//int j=(col/3)*3;

int i= row - row%3;
int j = col - col%3;

int rowEnd = i+3;
int colEnd = j+3;

for(;i<rowEnd;i++)
{
    for(;j<colEnd;j++)
        {
            if(grid[i][j]==n)
            return 0;
        }
}

return true;
}*/


bool isValid(int x, int y, int value) {
    for (int i = 0; i < 9;i++) {
        if (grid[x][i] == value || grid[i][y] == value) {
            return false;
        }
    }

    int gsx = (x/3)*3, gsy = (y/3)*3;
    for(int i = gsx; i < gsx+3; i++) {
        for (int j = gsy; j < gsy+3; j++) {
            if (grid[i][j] == value) {
                return false;
            }
        }
    }
    return true;
}

bool Solve(){

int row,col;

if(!isUnassigned(row,col))
    return true;


for(int x=1;x<=9;x++)
{
    if(isValid(row,col,x))
    {
            grid[row][col] = x;

            if (Solve())
                return true;

            grid[row][col] = 0;
    }
}

return false;
}

void printGrid()
{
    for (int row = 0; row < 9; row++)
    {
       for (int col = 0; col < 9; col++)
             cout<<grid[row][col]<<"  ";
        cout<<"\n";
    }
}

int main(){

    printGrid();
    cout<<endl<<endl;

    if(Solve())
    printGrid();

    else cout<<"Error!\n";
return 0;
}
