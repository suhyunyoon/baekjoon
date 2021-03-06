#include<iostream>
using namespace std; 

int totalNum(int);

int main(){
	int N;
	cin>>N;
	totalNum(N);
	return 0;
}

int totalNum(int N){
	unsigned int cnt[10] = {0,};
	int pows = 1000000000, upper, digit;
	while(N / pows == 0)
		pows /= 10;
	
	digit = N / pows;
	for(int i=1; i<digit; i++)
		cnt[i] += pows;
	cnt[digit] += N % pows + 1;
	pows /= 10;
	for(; pows > 0; pows /= 10){
		upper = N / (pows * 10);
		digit = (N / pows) % 10;
		cnt[0] += pows * (upper-1);
		for(int i=1; i<10; i++)
			cnt[i] += pows * upper;
		for(int i=0; i<digit; i++)
			cnt[i] += pows;
		cnt[digit] += N % pows + 1;
	}
	for(int i=0; i<10; i++){
		cout<<cnt[i]<<' ';
	}
	cout<<endl;
	return 0;
}
