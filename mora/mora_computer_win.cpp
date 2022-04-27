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
		if(people==2) cout << 0;
		else cout << people+1;
		cout << " lose!\n";
	}
	return 0;
}
