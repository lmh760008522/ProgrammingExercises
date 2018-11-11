#include<cstdio>
# include<iostream>   
using namespace std; 
# define N 1005

double result[N],t; 
 
int main(){
	int b,l,n,ws[N][2],w,s;
	int i,j;
	while ( scanf("%d %d %d",&b,&l,&n)!=EOF){
		if(b==0 && l==0 && n==0){
			break;
		} 
		l*=60;
		for(i=0;i<n;i++){
			cin>>ws[i][0]>>ws[i][1];  
  
            //先单独走  
            result[i]=l*1.0/ws[i][1]+result[i-1];  
  
            //和前面依次组合  
            w=ws[i][0];  
            s=ws[i][1];  
            for(j=i-1;j>=1&&(w+=ws[j][0])<=b;j--)  
            {  
                if(ws[j][1]<s)  
                {  
                    s=ws[j][1];  
                }  
                t=l*1.0/s+result[j-1];  
                if(result[i]>t)  
                {  
                    result[i]=t;  
                }  
            }  
		}
	}
	return 0;
}
