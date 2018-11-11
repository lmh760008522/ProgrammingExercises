#include<cstdio>
#include<cstring>
int main(){
	char a[21],b[21];
	gets(a);
	gets(b);
	bool falg=true;
	int i,j;
	for(i=0,j=0;i<strlen(a); i++){
		if(a[i]=='?'){
			j++;
			continue;
		}else if(a[i]=='*'){
			while(a[i+1]=='*'  || a[i+1]=='?'){
				i++;
			}
			while(a[i+1]!=b[j]){
				j++;
			}
			continue;
		}else{
			if(a[i]!=b[j]){
				falg=false;
				break;
			}
		}
		j++;
	}
	if(falg && i==strlen(a) && j==strlen(b)){
		printf("matched\n");
	}else{
		printf("not matched\n");
	}
	return 0;
}
