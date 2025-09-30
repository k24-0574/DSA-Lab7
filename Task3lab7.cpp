#include <iostream>
using namespace std;

bool isSafe(int **maze, int x, int y, int N){
    if(x>=0 && y>=0 && x<N && y<N && maze[x][y]) return 1;
    return 0;
}

bool solveMaze(int**maze, int N, int Tx, int Ty, int**sol, int x=0, int y=0){
    if(Tx==x && Ty==y && maze[Tx][Ty]){
		sol[x][y]=1;
		return 1;
	}

    if(isSafe(maze, x, y, N)){
        if(sol[x][y] == 1) return 0;
        sol[x][y] = 1;

        if(solveMaze(maze, N, Tx, Ty, sol, x+1, y)) return 1;
        if(solveMaze(maze, N, Tx, Ty, sol, x, y+1)) return 1;
        if(solveMaze(maze, N, Tx, Ty, sol, x, y-1)) return 1;
        if(solveMaze(maze, N, Tx, Ty, sol, x-1, y)) return 1;
        

        sol[x][y]=0;
        return 0;
    }
    return 0;
}

int main(){
    int maze[4][4] ={
        1, 1, 1, 1,
        0, 0, 0, 1,
        1, 1, 0, 1,
        1, 1, 1, 1
    };

    int **sol;
    int **m;
    sol = new int*[4];
    m = new int*[4];

    for(int i=0;i<4;i++){
        sol[i] = new int[4];
        m[i] = new int[4];
        for(int j=0;j<4;j++){ 
            m[i][j] = maze[i][j];
            sol[i][j] = 0;
        }
    }
    if(solveMaze(m, 4, 2, 0, sol)){
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    else cout<<"no path found";
   

    for(int i=0;i<4;i++){
        delete[] m[i];
        delete[] sol[i];
    }
    delete[] sol;
    delete[] m;

    return 0;
}