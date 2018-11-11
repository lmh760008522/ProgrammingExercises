//不知道哪错了，思路复杂，没有看清题就写自以为的思路 
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<int> k1,k2,k3;
vector<double> a1,a2,a3;
int main(){
	int n1,n2;
	cin>>n1;
	k1.resize(n1);
	a1.resize(n1);
	for(int i=0;i<n1;i++){
		cin>>k1[i]>>a1[i];
	}
	cin>>n2;
	k2.resize(n2);
	a2.resize(n2);
	for(int i=0;i<n2;i++){
		cin>>k2[i]>>a2[i];
	}
	
	k3.resize(n1+n2);
	a3.resize(n1+n2);
	int count =0;
	int i,j;
	for(i=0,j=0; i<n1,j<n2; ){
		if( k1[i] == k2[j]){
			k3[count] = k1[i];
			a3[count] = a2[j]+a1[i];
			i++;j++;count++;
		}else if(k1[i] < k2[j]){
			k3[count] = k2[j];
			a3[count] = a2[j];
			j++;count++;
		}else if(k1[i] > k2[j]){
			k3[count] = k1[i];
			a3[count] = a1[i];
			i++;count++;
		}
	}
	if(i!=n1){
		for(int k=i;k<n1;k++){
			k3[count] = k1[k];
			a3[count] = a1[k];
			count ++;
		}
	}
	if(j!=n2){
		for(int k=j;k<n2;k++){
			k3[count] = k1[k];
			a3[count] = a1[k];
			count ++;
		}
	}
	if(count == 0){
		cout<<"0";
		return 0; 
	}
	cout<<count<<" ";
	for(int i=0;i<count;i++){
		printf("%d %.1f",k3[i],a3[i]);
		if(i!=count-1){
			cout<<" "; 
		}
	}
	return 0;
} 

/*
#include <iostream>
using namespace std;
int main() {
    float c[1001] = {0};
    int m, n, t;
    float num;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d%f", &t, &num);
        c[t] += num;
    }
    int cnt = 0;
    for (int i = 0; i < 1001; i++) {
        if (c[i] != 0) cnt++;
    }
    printf("%d", cnt);
    for (int i = 1000; i >= 0; i--) {
        if (c[i] != 0.0)
            printf(" %d %.1f", i, c[i]);
    }
    return 0;
}
*/
