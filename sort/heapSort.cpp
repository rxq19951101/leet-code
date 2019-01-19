#include <iostream>
#include <vector>

using namespace std;
template <typename T>
void maxHeap(vector<T> &s, int n, int num);
template <typename T>
void buildMaxHeap(vector<T> &s){
	int m=s.size();
	int mid=(m-2)/2;
	for(int i=mid; i>=0; i--){
	maxHeap(s, i, m);
}
}

template <typename T>
void maxHeap(vector<T> &s, int n, int num){
	int left=n*2+1;
	int right=n*2+2;
	T max=s[n];
	int index=0;
	if(left<num-1&&right<num-1&&s[left]<s[right])
	{
		index=right;
		max=s[right];
	}
	else {index=left; max=s[left];}
	if(s[n]<max){
	swap(s[n],s[index]);
	maxHeap(s, index, num);
}

}
template <typename T>
void lastheap(vector<T> &s){
	
	buildMaxHeap(s);
	int n=s.size()-1;
	vector<T> record;
	for(int i=0;i++;i<s.size()-1){
	swap(s[0],s[n]);
	record.push_back(s[n]);
	n--;
	maxHeap(s, 0, n+1);
}
}


int main(){
	int n=2;
	vector<int> s;
	s.push_back(3);
	s.push_back(7);
	s.push_back(9);
	lastheap(s);
	cout<< s[0];
	
	return 0;
}
