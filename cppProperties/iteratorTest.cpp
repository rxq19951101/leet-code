#include<iostream>
using namespace std;

#include<vector>

int main()
{
vector<int> s;//在这个容器中放入1，2,3,4,5
for(int i=1;i<6;i++) s.push_back(i);
vector<int>::iterator it;
it=s.begin();
for(;it!=s.end();it++)
{
 if(*it<4) {it=s.erase(it); it--;}
  cout<<*it<<endl;
}
 cout<<s[0]<<endl;
return 0;
}

