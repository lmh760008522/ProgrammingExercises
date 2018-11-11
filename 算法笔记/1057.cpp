#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;

stack<int> st;
int table[100010];
int block[316];

void pop(){
	int x=st.top();
	st.pop();
	block[x/316]--;
	table[x]--;
}

void push(int x){
	st.push(x);
	table[x]++;
	block[x/316]++;
}

void pick(int k){
	int sum=0;
	int idx=0;
	while(sum+block[idx]<k){
		sum+=block[idx];
		idx++;
	}
	int num=idx*316;
	while(sum+table[num]<k){
		sum+=table[num++];
	}
	printf("%d\n",num);
}

int main(){
	int n;
	scanf("%d\n",&n);
	for(int i=0;i<n;i++){
		char s[20];
		scanf("%s",s);
		if(strcmp(s,"Pop")==0){
			if(st.empty() == true){
				printf("%INVALIED\n");
			}else{
				pop();
			}
		}else if(strcmp(s,"Push")==0){
			int x;
			scanf("%d",&x);
			push(x);
		}else{
			if(st.empty()==true){
				printf("%INVALIED\n");
			}else{
				int k=st.size();
				if(k%2==1){
					k=(k+1)/2;
				}else{
					k=k/2;
				}
				pick(k);
			}
		}
	}
	return 0;
} 
