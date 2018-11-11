#include<stdio.h>
#include<set>
using namespace std;

int main(){
	int n,m;
	scanf("%d %d", &n, &m);
	set<int> s;
	for(int i= 0;i<n+m;i++){
		int x;
		scanf("%d", &x);
		s.insert(x);
	}
	set<int>::iterator iter;
	for(iter = s.begin(); iter != s.end(); iter++){
		printf("%d ", *iter);
	}
	return 0;
} 
