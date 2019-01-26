#include <iostream>
#include <vector>

using namespace std;


template <class T>
void Sort(vector<T> &s, int left,int mid, int right){
	vector<int> record(s.size(),0);
	int l=left,r=mid+1;
	int i=0;	
	while(l<=mid&&r<=right){
	while(s[l]<s[r])  record[i++]=s[l++];
	while(s[l]>s[r])  record[i++]=s[r++];
}
	while(l<=mid) record[i++]=s[l++];
	while(r<=right) record[i++]=s[r++];
	for(int i=left;i<=right;i++){
	s[i]=record[i-left];
}



}

template <class T>
void merge(vector<T> &s, int left, int right){
	if(left>=right) return;
	int mid=(right-left)/2+left;
	merge(s,left,mid);
	merge(s,mid+1,right);
	Sort(s,left,mid,right);


}



int main(){
	vector<int> a;
	a.push_back(7);
	a.push_back(5);
	a.push_back(8);
	merge(a,0,2);
	cout<<a[0]<<a[1]<<a[2]<<endl;


}
