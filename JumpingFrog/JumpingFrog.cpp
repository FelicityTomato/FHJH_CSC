#include<bits/stdc++.h>
using namespace std;

int white, black, space, n;
int arr[20];
void uninput(){
	cout <<"輸入不符合規定，請重新輸入" << '\n';
}

void output(){
	//cout << "剩餘步數：" << lim << '\n';
	for(int i=0; i<n; i++) cout << i << ' ';
	cout << '\n';
	for(int i=0; i<n; i++){
		if(arr[i]==0) cout << "_ ";
		else if(arr[i]==1) cout << "o ";
		else cout << "x ";
	}
	cout << '\n';
}

bool check(){
	int i=0;
	for(;i<black; i++) if(arr[i]!=2) return 0;
	for(;i<black+space; i++) if(arr[i]!=0) return 0;
	return 1;
}

int main(){
	cout << "請輸入白棋數 空格數 黑棋數\n";
	cin >> white >> space >> black;
	n=white+space+black;
	int i=0;
	for(;i<white; i++) arr[i]=1;
	for(;i<white+space; i++) arr[i]=0;
	for(;i<white+space+black; i++) arr[i]=2;
	output();
	while(1){
		cin >> i;
		if(arr[i]==0 || i<0 || i>=n){
			uninput();
			continue;
		}
		else if(arr[i]==1){
			if(i+1==n){
				uninput();
				continue;
			}
			else if(arr[i+1]==0){
				arr[i]=0;
				arr[i+1]=1;
			}
			else if(i+2==n || arr[i+2]!=0){
				uninput();
				continue;
			}
			else{
				arr[i]=0;
				arr[i+2]=1;
			}
		}
		else{
			if(i-1==-1){
				uninput();
				continue;
			}
			else if(arr[i-1]==0){
				arr[i]=0;
				arr[i-1]=2;
			}
			else if(i-2==-1 || arr[i-2]!=0){
				uninput();
				continue;
			}
			else{
				arr[i]=0;
				arr[i-2]=2;
			}
		}
		output();
		if(check()){
			cout << "YOU WIN!!!\n";
			return 0;
		}
	}
	return 0;
} 