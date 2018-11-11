#include<stdio.h>
#include<time.h>
//线性规划 
//思路有问题 
int main(){
	int N,D;//种类数，需求量
	int kc[1000],sj[1000],zy[1000];//库存，售价 ,最优 
	int i=0,min;
	scanf("%d %d",&N,&D);
	srand(time(NULL));
	while(i<N){
		cin>>kc[i];
	}
	i=0;
	while(i<N){
		cin>>sj[i];
	}
	
	i=0;
	while(i<N){
		zy[i]=rand()%(kc[i]);
	}
	return 0;
} 

/*
#include<stdio.h>  
#include<algorithm>  
using namespace std;  
 struct N{  
        double num;  
        double total;  
        double price;  
        }data[1100];  
          
bool cmp(N a,N b){  
     return a.price>b.price;  
     }  
int main(){  
    int n,m;  
    scanf("%d%d",&n,&m);  
      
    for(int i=0;i<n;i++)  
     scanf("%lf",&data[i].num);  
       
    for(int i=0;i<n;i++)  
    scanf("%lf",&data[i].total);  
    for(int i=0;i<n;i++)  
      data[i].price=data[i].total/data[i].num;   
    sort(data,data+n,cmp);  
    double x=0;  
    int j=0;  
    while(m>0&&j<n){  
       if(m>data[j].num){  
            m-=data[j].num;  
            x+=data[j].total;                 
                  }  
       else{  
            
            x+=data[j].price*m;  
              m-=data[j].num;  
            }  
          j++;   
                 
               }  
     
     printf("%.2lf\n",x);    
      
    return 0;  
    }  
*/
