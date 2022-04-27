#include<bits/stdc++.h>
#include <time.h>
using namespace std;

int arr[100][100];
int output[100][100];
int N;
int mines;
int Plus[8][2]={ {1,1},{1,0},{1,-1},{0,1},{0,-1},{-1,1},{-1,0},{-1,-1} };
int open=0;

void print(bool lose=false){
	for(int i=1; i<=N; i++) cout <<  setw(3) << i;
	cout << endl;
	for(int i=1; i<=N; i++) cout <<"---";
	cout << "-+" << endl;
	for(int i=1; i<=N; i++) {
		for(int j=1; j<=N; j++) {
			if (lose == true && arr[i][j] == -1 )
					cout << setw(3) << "X";
			else if (output[i][j] == -2) 
				cout << setw(3) << "*";
			else 
				cout << setw(3) << arr[i][j]; 
		}
		cout <<" | " << i << endl;
	}
}
int main(){
	cout << "input the size you want. ";
	cin >> N;
	cout << "input how many mines you want? ";
	cin >> mines;
	srand(time(0));
	int done=0;
	for(int i=0; i<=N+1; i++)
		for(int j=0; j<=N+1; j++) 
		arr[i][j]=0; // 0 is nothing
	int x,y;
	while(done != mines){
		x=rand() % N + 1 ;
		y=rand() % N + 1;
		if(arr[x][y]!=-1){
			arr[x][y]=-1;	// -1 is mines
			done++;
			for(int i=0; i<8; i++){
				if(arr[x+Plus[i][0]][y+Plus[i][1]] != -1) arr[x+Plus[i][0]][y+Plus[i][1]]++;
			}
		}
	}
	for(int i=0; i<=N+1; i++){
		for(int j=0; j<=N+1; j++){
			output[i][j]=-2; // don't need to print;
		}
	}
	for(int i=0; i<=N+1; i++){
		arr[0][i]=-1;
		arr[N+1][i]=-1;
		arr[i][0]=-1;
		arr[i][N+1]=-1;
	}
	print();
	while(open<N*N-mines){
		int x,y;
		cin >> x >> y;
		output[x][y]=1;
		open++;
		if(arr[x][y]==-1){ 
			print(true);
			cout << "You lose! " << endl;
			return 0;
		}
		else if(arr[x][y]!=0){
			print();
		}
		else{
			queue< pair<int,int> > qp;
			qp.push({x,y});
			while(qp.size()){
				int xx=qp.front().first, yy=qp.front().second;
				qp.pop();
				for(int i=0; i<8; i++){
					if(arr[xx+Plus[i][0]][yy+Plus[i][1]]!=-1 && output[xx+Plus[i][0]][yy+Plus[i][1]]==-2){
						//cout <<xx+Plus[i][0] << yy+Plus[i][1] <<endl;
						open++;
						output[xx+Plus[i][0]][yy+Plus[i][1]]=1;
						if(arr[xx+Plus[i][0]][yy+Plus[i][1]]==0)
							qp.push({xx+Plus[i][0],yy+Plus[i][1]});
					}
				}
			}
			print();
		}
		cout << open <<' ' << N*N-mines << endl;
	}
	cout << "YOU WIN!!!!!!" << endl;
	return 0;
}