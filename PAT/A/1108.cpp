#include<stdio.h>
#include<string.h>
//���벻�ɹ������������� 
int main(){
	double sum=0;
	int count;
	char c[10];
	scanf("%d",&count);
	for(int i=0;i<count;i++){
		scanf("%s",c);
		printf("%s %d\n",c,i);
		double num=0;//��������
		int cc=1;//����С������ 
		int flag = 0;//��¼�Ƿ���С�� 
		bool h = true;
		for(int j=0;c[j]!='\0';j++){
			if((c[j]>57 || c[j]<48) && c[j]!='.' ){//�������� 
				h = false;
				count--;
			}else if( !flag && c[j]!='.'){//��֮ǰ 
				num = num*10 + c[j];
			}else if(c[j]=='.'){
				flag ++;
				if(flag>1){
				    h = false;
					count--;
				}
				if(strlen(c)-1-j>2){//�������� 
					count--;
					h = false;
				}
			}else if(flag == 1){
				num+=c[j]*0.1*cc;
				cc=cc*0.1; 
			}
		}
		if(h == false){
			printf("ERROR: %s is not a legal number\n",c);
			continue;
		}
		if(num>=-1000 && num<=1000){
			sum+=num;
		}else{ 
			printf("ERROR: %s is not a legal number\n",c);
			count--;
		}
	}
	if(count>0){
		printf("The average of %d numbers is %.2lf",count,sum/count);
	}else{
		printf("The average of 0 numbers is Undefined");
	}
	return 0;
} 
