#include<cstdio>

	int x1,y1,
	    x2,y2,
	    x0,y0;
	int ner;
	
bool judgeh(int a,int b){//ÊÇ·ñ×²»÷ºÚÇò 
	if(a==x2 && b==y2){
		return true;
	}
	return false;
}

bool judged(int a,int b){//ÊÇ·ñ½ø¶´ 
	if((a==0 && b==0) || (a==0 && b==8) || (a==0 && b==16) || (a==5 && b==0) || (a==5 && b==8) || (a==5 && b==16)){
		return true;
	}
	return false;
}

bool judgeb(int a,int b){//ÊÇ·ñ×²»÷±ß¿ò 
	if( (a==0&&b!=0) || (a==16) || b==0 || b==5){
		return true;
	}
	return false;
}

int main(){
	scanf("%d %d\n",&x1,&y1);//°× 
	scanf("%d %d\n",&x2,&y2);//ºÚ 
	scanf("%d %d\n",&x0,&y0);//·½Ïò 
	scanf("%d",&ner);
	int x=x1,y=y1;
	bool flag=false;
	bool hb=false;//ÅÐ¶Ï°×ÇòºÚÇò 
	while(ner>0){
		x+=x0,y+=y0;
		ner--;
		if(judgeh(x,y)){
			hb=true;
			continue;
		}else if(judged(x,y)){
			flag=true;
		}else if(judgeb(x,y)){
			if( x == 0 || x==5){
				y0=-y0;
			}else if(y==5 || y==0){
				x0=-x0;
			}
		}
	}
	if(flag==false){
		printf("0\n");
	}else{
		if( hb ){
			printf("1\n");
		}else{
			printf("-1\n");
		}
	}
	
	return 0;
}
