#include<stdio.h>
#include<string.h>
int main(){
	int m;
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		char s[50];
		scanf("%s", s);
		if(strlen(s) <8 || strlen(s) >16){
			printf("NO\n");
			continue;
		}
		int count = 0;
		bool flag = true;
		bool xx = false, dx = false, sz = false, ts = false;
		for(int j=0; j<strlen(s); j++){
			if(s[j] >= 'a' && s[j] <= 'z'){
				if(xx == false){
					printf("xx ");
					xx = true;
					count++;
				}
			}else if(s[j] >= 'A' && s[j] <= 'Z'){
				if(dx == false){
					//printf("dx ");
					dx = true;
					count++;
				}
			}else if(s[j] >= '0' && s[j] <= '9'){
				if(sz == false){
					//printf("sz ");
					sz = true;
					count++;
				}
			}else if(s[j] == '~' || s[j] == '!' || s[j] == '@' || s[j] == '#' || s[j] == '$' || s[j] == '%' || s[j] == '^'){
				if(ts == false){
					//printf("ts ");
					ts = true;
					count++;
				}
			}else{
				flag = false;
			}
		}
		printf("%d\n",count);
		if(count <3){
			flag = false;
		}
		if(flag){
			printf("OK\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
