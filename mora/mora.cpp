#include <bits/stdc++.h>
using namespace std;

int main(){
	srand(time(0));
	cout << "剪刀0 石頭1 布2\n";
	while(1){
		int people; cin >> people;
		if(people>2 || people<0){
			cout << "cin error\n";
			continue;
		}
		int computer=rand()%3;
		cout <<  computer;
		if(computer==people){
			cout << " 平手\n";
		}
		else if(computer>people){
			if(computer==2 && people==0) cout <<" win!\n";
			else cout << " lose!\n";
		}
		else{
			if(people==2 && computer==0) cout << " lose!\n";
			else cout << " win!\n";
		}
	}
	return 0;
}
