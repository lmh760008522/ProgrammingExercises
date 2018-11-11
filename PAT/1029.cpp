#include<stdio.h>
int main(){
	char source[80],des[80],v[80];//Î´¸³Öµ£¬ÔòÎª0 
	int i=0,j=0,k=0;
	scanf("%s\n%s",source,des);
	for(i=0;source[i]!='\0'&&des[j]!='\0';i++){
		printf("%d:%c %c\n",i,source[i],des[j]);
		if(source[i]!=des[j]){
			for(k=0;v[k]!=0;k++){
				if(v[k]>='a'&&v[k]<='z'){
					if(v[k]==source[i]||((v[k]-32)==source[i])){
						break;
					}
				}else{
					if((v[k]==source[i])||((v[k]+32)==source[i])){
						break;
					}	
				}
			}
			if(v[k]==0){
				v[k]=source[i];
				printf("%c\n",v[k]);
			}
		}else{
			j++;
		}
	}
	if(source[i]!='\0'){
		for(k=0;v[k]!=0;k++){
			if(v[k]>='a'&&v[k]<='z'){
				if(v[k]==source[i]||((v[k]-32)==source[i])){
					break;
				}
			}else{
				if((v[k]==source[i])||((v[k]+32)==source[i])){
					break;
				}	
			}
		}
			if(v[k]==0){
				v[k]=source[i];
				printf("%c\n",v[k]);
			}
	}
	for(i=2;i<=k;i++){
		if(v[i]>=97){
			v[i]-=32;
		}
		printf("%c",v[i]);
	}
	return 0;
}
