#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void BubbleSort(vector<T> &s){

	int m=s.size();
	for(int i=0; i<m-1; i++){
		for(int j=0; j<m-1; j++){
		if(j+1<m&&s[j]>s[j+1])
		{
			int temp = s[j];
			s[j]=s[j+1];
			s[j+1]=temp;
		}

}
}
}



int main(){
	vector<int> a;
	a.push_back(6);
	a.push_back(8);
	a.push_back(3);
	a.push_back(2);
	BubbleSort(a);
	for(auto d:a){
	cout<<d<<endl;	
}	


}
