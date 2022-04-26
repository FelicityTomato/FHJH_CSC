#include <iostream>
using namespace std;
int N;
int MP[100][100];

void printout() {
	cout << "\n     "; 
	for(int i=0; i<N; i++) cout <<i << "   "; cout << "\n";
	cout << "   ";
	for(int i=0; i<N; i++) cout << "+---"; cout << "+\n";
	
	for(int i=0; i<N; i++) {
		cout << i << "  |";
		for(int j=0; j<N; j++) {
			if (MP[i][j] == -1)
				cout << " " << "x" << " |";
			else if (MP[i][j] == 1)
				cout << " " << "o" << " |";
			else
				cout << " " << " " << " |";
		}
		cout << "\n   ";
		for(int i=0; i<N; i++) cout << "+---"; cout << "+\n";
	}
	
}
int checkWin() {
	for(int i=0; i<N; i++){
		int a=MP[i][0];
		for(int j=0; j<N; j++){
			if(a==0 || MP[i][j]!=a) break;
			else if(j==N-1) return a;
		}
	}
	for(int i=0; i<N; i++){
		int a=MP[0][i];
		for(int j=0; j<N; j++){
			if(a==0 || MP[j][i]!=a) break;
			else if(j==N-1) return a;
		}
	}
	int a=MP[0][0];	
	for(int i=0; i<N; i++){
		if(a==0 || MP[i][i]!=a) break;
		else if(i==N-1) return a;
	}
	a=MP[N-1][0];
	for(int i=0; i<N; i++){
		if(a==0 || MP[N-1-i][i]!=a) break;
		else if(i==N-1) return a;
	}
	return 0;
}

int main() {
	cout << "input size(2~100)" << endl;
	cin >> N;
	int win= 0;
	for(int i=0; i<N; i++) 
		for(int j=0; j<N; j++)
			MP[i][j] = 0; 
	int cnt =N*N, x, y;
	printout();
	while(cnt > 0) {
		if (cnt & 1) { 
			cout << " 'o' turn: "; 
			cin >> x >> y; 
			if ( x >=0 && x<N && y >= 0 && y < N &&  MP[x][y] == 0 ) MP[x][y] = 1;
			else continue; 
		} else {
			cout << " 'x' turn: " ;
			cin >> x >> y; 
			if ( x >=0 && x<N && y >= 0 && y < N &&  MP[x][y] == 0 ) MP[x][y] = -1;
			else continue; 
		}
		printout();
		cnt--;

		win  = checkWin();
		//cout << win <<'\n';
		if (win == 1) {
			cout << "'O' Win\n";
			return 0;
		}
		else if (win == -1){
			cout << "'X' Win!\n";
			return 0;
		} 
	}
	if (win == 0 )  cout << "Tie!\n"; 
	return 0;
}


