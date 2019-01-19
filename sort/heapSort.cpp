/* 堆排序思路，先建堆，分大顶堆和小顶堆，少犯愚蠢的错误，小于一般小于size，不是size-1.然后在将尾元素再置顶。建堆，堆排序，然后排除堆顶堆尾置换，继续堆排序，知道最后的限定size小于等于一为止。时间复杂度，建堆是logn，然后置换排序是n，所以时间复杂度为O(nlogn)属于不稳定排序。*/



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
	if(left>=num) return;
	int right=n*2+2;
	T max=s[n];
	int index=0;
	if(left<num&&right<num&&s[left]<s[right])
	{
		index=right;
		max=s[right];
	}
	else if(left<num) {index=left; max=s[left];}
	if(s[n]<max){
	cout<<index<<endl;
	swap(s[n],s[index]);
	maxHeap(s, index, num);
}

}
template <typename T>
vector<T> lastheap(vector<T> &s){
	buildMaxHeap(s);
	int n=s.size()-1;
	vector<T> record;
	for(int i=0;i<s.size();i++){
	swap(s[0],s[n]);
	record.push_back(s[n]);
	n--;
	cout<<n<<endl;
	maxHeap(s, 0, n+1);
}
	return record;
}


int main(){
	int n=2;
	vector<int> s;
	s.push_back(7);
	s.push_back(3);
	s.push_back(9);
	s=lastheap(s);
	cout<< s[0]<< s[1]<< s[2];
	
	return 0;
}
