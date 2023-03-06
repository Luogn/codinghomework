#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int row, collumn, bomb_num;
int x, y; // toa do cac diem nhap tu ban phim cua nguoi choi

int**screen_board(); // Ham khoi tao bang man hinh game
void generate_bomb(int**arr); // Ham tao bom o cac vi tri ngau nhien trong bang tro choi
int bomb_cnt(int** arr); // Ham dem so luong bom xung quanh vi tri nguoi choi chon
void get_position(int**arr); // ham kiem tra va hien thi bang sau khi nguoi choi nhap vi tri

int main(){
	srand(time(NULL));
	cout << "Please enter the size of screen you want to play: \n"; 
	cin >> row >> collumn;
	cout << "Please enter the number of bomb you want to deal with: \n";
	cin >> bomb_num;
	cout << "Here is the board you gonna play with: \n";
	cout << endl;
	int**play_screen=screen_board();
	for(int i=0;i<row;i++){
		for(int j=0;j<collumn;j++){
			cout << play_screen[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;
	generate_bomb(play_screen);
	bool game_continue=true;
	int x1=-1000, y1=-1000;
	int count_bomb=0;
	int picked_position=collumn*row;
	do{
		cout << "Enter the position you doubt that has bomb: \n";
		cin >> x >> y;
		if(x<0 || y< 0 || x>row || y>collumn) {
			cout << "Invalid position, please re-enter a valid position of x from 0 to" << row-1 
									<< "a valid position of y from 0 to" << collumn-1 << "\n";
			continue;
		}
		if(x==x1 && y==y1) {
			cout << "You have chosen this position previously, please enter a different position! \n";
		}
		else {
			get_position(play_screen);
			if(play_screen[x][y]==-1) {
				cout << "YOU DIE" << endl;
				game_continue=false;
			}
			else {
				picked_position--;
				if(picked_position==bomb_num) {
					cout << "YOU WIN \n";
					break;
				}
			}
		}
		x1=x;
		y1=y;
	}
	while(game_continue);
	
	return 0;
}

int**screen_board(){
	int **board=new int*[row];
	for(int i=0;i<row;i++) board[i]=new int[collumn];
	for(int i=0;i<row;i++){
		for(int j=0;j<collumn;j++){
			board[i][j]=0;
		}
	}
	return board;
}
void generate_bomb(int** arr){
	int count = 0;
	while(count < bomb_num){
		int a= rand()%row;
		int b= rand()%collumn;
		if(arr[a][b]!=-1){
			arr[a][b]=-1;
			count++;
		}
	}
}
int bomb_cnt(int**arr){
	int near_bomb = 0;
	// ra soat cac o quanh vi tri da chon xem co bom hay khong
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if(i==0 && j==0) continue;
			if(x+i >=0 && x+i<row && y+j>=0 && y+j<collumn){
				if(arr[x+i][y+j]==-1) near_bomb++; // danh dau cac vi tri co bom la -1
			}
		}
	}
	return near_bomb;
}
void get_position(int**arr){
	if(x< row && y< collumn){
		for(int i=0;i<row;i++){
			for(int j=0;j<collumn;j++){
				if(i==x && j==y){
					if(arr[i][j]!=-1){
						arr[i][j]=bomb_cnt(arr);
						cout << arr[i][j] << ' ';
					}
					else cout << "* ";
				}
				else {
					if(arr[i][j]==-1) cout <<0<< ' ';
					else cout << arr[i][j] <<' ';
				}
			}	
		cout << endl;
		}
	}
}

