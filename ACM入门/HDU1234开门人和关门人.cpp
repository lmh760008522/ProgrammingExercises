#include<stdio.h>
#include<string.h>

int zhuanhuan(char c[8]){
	int sum = 0;
	sum += (c[6]-48)*10 + (c[7]-48);
	sum += ((c[3]-48)*10 + (c[4]-48))*60;
	sum += ((c[0]-48)*10 + (c[1]-48))*3600;
	return sum;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0;i<n;i++){
		int m;
		scanf("%d" ,&m);
		int min = 86405, max = 0;//一天最多86400秒 
		char minid[15] = "", maxid[15] = "";
		for(int j=0;j<m;j++){
			char id[15], come[8], go[8];
			scanf("%s %s %s", id, come, go);
			int min_t = zhuanhuan(come);
			int max_t = zhuanhuan(go);
			printf("%d %d\n",min_t, max_t);
			
			if(min_t < min){
				min = min_t;
				strcpy(minid, id);
			}
			if(max_t > max){
				max = max_t;
				strcpy(maxid, id);
			}
		}
		printf("%s %s\n",minid, maxid);
	}
	return 0;
} 
