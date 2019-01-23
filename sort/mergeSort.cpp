/* 归并排序， 先分开再排序， 分开时间logn，排序时间n ，总时间复杂度O(nlogn)*/
#include <iostream>
#include <vector>

using namespace std;

template <typename T> 
void sort(vector<T> &s, int left, int mid, int right){
	vector<T> a(right-left+1,0);
	int i=left,j=mid+1;
	int st=0;
	while(i<=mid&&j<=right){
	if(s[i]<=s[j]) a[st++]=s[i++];
	else a[st++]=s[j++];
}
	while(i<=mid) a[st++]=s[i++];
	while(j<=right) a[st++]=s[j++];
	for(int v=0; v<right-left+1; v++){
	s[v+left]=a[v];
}
}


template <typename T> 
void mergeSort(vector<T> &s, int left, int right){
	if(right<=left) return;
	int mid=(right-left)/2+left;
	mergeSort(s,left,mid);
	mergeSort(s,mid+1,right);
	sort( s, left, mid, right);
}


int main(){

	vector<int> s;
	s.push_back(3);
	s.push_back(5);
	s.push_back(4);
	mergeSort(s,0,2);
	cout<<s[0]<<s[1]<<s[2];
	return 0;

}
