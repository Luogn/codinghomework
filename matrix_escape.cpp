#include<iostream>
#include<cstring>

using namespace std;

int m, n;
int matrix[100][100];
bool check_visited[100][100];
int x_direction[] = {-1, 0, 1, 0}; // l?n lu?t các hu?ng trái, lên, ph?i, xu?ng
int y_direction[] = {0, 1, 0, -1};
bool checked = false;

void find_way(int x, int y){
    check_visited[x][y]=true;
    if(x==m-1 && y==n-1){
        checked=true;
        matrix[x][y]=2;
        return;
    }
    for(int i=0;i<4;i++){
        int new_x=x+x_direction[i];
        int new_y=y+y_direction[i];
        if(new_x>=0 && new_x<m && new_y>=0 && new_y<n && matrix[new_x][new_y]==0 && !check_visited[new_x][new_y]){
            find_way(new_x, new_y);
            if(checked){
                matrix[x][y]=2;
                return;
            }
        }
    }
}

int main(){
    cin >> m >> n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    
    memset(check_visited, 0, sizeof(check_visited));
    find_way(0, 0);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
