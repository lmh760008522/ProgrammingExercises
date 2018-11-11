#include<cstdio>
int main(){
	int num[6]={5,7,7,8,8,10};
	int tar=5;
	int l=0,r=5,mid=-1;
	int x,y;
	int ll,rr,mm;
	while(l<=r){
		mid=(l+r)/2;
		if(num[mid] < tar){
			l=mid+1;
		}else if(num[mid]>tar){
			r=mid;
		}else{
			x=mid;
			y=mid;
			ll=l;rr=r;mm=mid;
			break;
		}
	}
	//printf("%d ",mid);
	
	if(mid!=0 && num[mid-1]==tar){//урвС 
		r=mid;
		l=ll;
		while(true){
			mid=(l+r)/2;
			if(mid==0 && num[mid]==tar){
				x=mid;
				break;
			}
			if(num[mid]==tar || num[mid-1] !=tar){
				x=mid;
				break;
			}
			if(num[mid]<tar){
				l=mid+1;
			}else{
				r=mid;
			}
		}
	}
//	printf("%d %d %d %d ",x,y,num[mid+1]==tar,num[mid+1]);
	
	if(mid!=5 && num[mm+1]==tar){//урср 
		l=mm;
		r=rr;
		while(true){
			mid=(l+r)/2;
			if(mid==6 && num[mid]==tar){
				x=mid;
				break;
			}
			if(num[mid]==tar || num[mid+1] !=tar){
				y=mid;
				break;
			}
			if(num[mid]<tar){
				l=mid+1;
			}else{
				r=mid;
			}
		}
	}
	printf("%d %d",x,y);
	return 0;
} 
