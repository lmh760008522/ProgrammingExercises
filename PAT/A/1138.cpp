#include<iostream>
#include<vector>
using namespace std;
vector<int > pre,in,post;
int flag;
void postorder(int prel, int inl, int inr){
	if (inl > inr || flag == true) return;
    int i = inl;
    while (in[i] != pre[prel]) i++;
    postorder(prel+1, inl, i-1);
    postorder(prel+i-inl+1, i+1, inr);
    if (flag == false) {
        printf("%d", in[i]);
        flag = true;
    }
}
int main(){
	int n;
	cin>>n;
	pre.resize(n);
	in.resize(n);
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	postorder(0, 0, n-1);
	return 0;
}
