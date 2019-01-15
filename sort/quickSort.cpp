/*快排的思路，一个左一个右，然后找一个中间值，比这个中间值大的放右边，比这个中间值小的放右边*/
/*
还是完全没有搞清边缘情况，得到最后的排布后，是0--l-1和l+1--right区间的子类排序，必须要清楚呀，一不小心，递归就永远进行下去了，变成了段错误*/
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
void quickSort(vector<int> &input, int left, int right);
/*
void quickSort(vector<int> &input, int left, int right)
{
   if(left>=right) return;
   int l=left, r=right-1, cp=right;
   while(l<r)
	{ 
	  while(l<r&&input[l]<=input[cp]) l++;
	  while(l<r&&input[r]>=input[cp]) r--;
	  if(l<r){
	  int temp=input[l];
	  input[l]=input[r];
	  input[r]=temp;
	}
	}
	int temp=input[cp];
	input[cp]=input[l];
	input[l]=temp;
	quickSort(input, left, l-1);
	quickSort(input, l+1, right);
	
}
*/
int main(){
	vector<int> s;
	s.push_back(3);
	s.push_back(7);
	s.push_back(1);
	s.push_back(5);
	quickSort(s,0,3);
	for(auto& i : s) cout<<i<<endl;
	//vector<int>::iterator it;
	//for(it=s.begin();it!=s.end();it++) cout<<*it<<endl;
	return 0;

}


/*另外一个方法，前后指针法，思路就是两个先指定一个key值，然后两个指针同时从起点开始，当碰到大于key值的数时，一个指针继续前进，另外一个指针不动，如果此时碰到一个小于key值的数，交换，然后前面的指针交换后向后移一格。*/
/*
void quickSort(vector<int> &input, int left, int right){
	if(left>=right) return;
	int &key= input[right];
	int pre=left,next=left;
	while(next<right){
	while(next<right&&input[pre]<=key){ cout<<pre; next++; pre++;}

	while(next<right&&input[next]>key) {next++;  cout<<next;}
 	int temp=input[pre];
	input[pre]=input[next];
	input[next]=temp;
	if(pre<next) pre++;
 }
	int temp=input[pre];
	input[pre]=input[right];
	input[right]=temp;
	quickSort(input, left, pre-1);
	quickSort(input, pre+1, right);

}
*/
/*写这个代码的时候，发生了段错误，只是因为pre++没有写对，没有考虑特殊情况，其实也考虑了，只是没考虑过来，就产生了递归无限的循环。所以递归的时候，所有一切的边缘情况都得想到，如果想不到，就会出现段错误。*/



/*然后是非递归版的快排，一切的递归无非就是入栈出栈，按着这个思想写非递归就很容易*/
//非递归思路，第一先将第一次给的数据直接放入堆栈中，当然判断一下更好。然后出堆栈顶部第一组条件，进行处理。处理完判断得到的第二组数据，看是否满足条件再次入堆栈（在递归中也就是判断是否继续递归的条件），如果满足，入堆栈，循环，再次处理数据，如果不满足，则直接跳过，处理堆栈中的下一组数据。直至堆栈中没有数据，则代表所有满足条件的数据处理完毕，可以出结果了。
//需要注意的是 进栈出栈的顺序不能错，严格执行先进后出的顺序。
void quickSort(vector<int> &input, int left, int right){
	
	stack<int> s;

	s.push(right);
	s.push(left);
	while(!s.empty()){
	int l=s.top();
	s.pop();
	int r=s.top();	
	s.pop();
	int pl=l, pr=r;
	while(l<r) {
	int &key= input[pr];
	while(l<r&&input[l]<=key) l++;
	while(l<r&&input[r]>=key) r--;
	swap(input[l],input[r]);
}
	swap(input[l],input[pr]);
	if(l-1>pl) {s.push(l-1); s.push(pl);}
	if(l+1<pr) {s.push(pr); s.push(l+1);}
}	
	

}
