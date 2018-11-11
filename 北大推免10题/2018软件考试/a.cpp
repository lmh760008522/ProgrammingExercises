#include<cstdio>
int gcd(int x,int y)//ÅÐ¶Ï¹«Ô¼Êý 
{
	int t;
	while (y) t=x, x=y, y=t%y;
	return x;
}
int main(){
	int n;
	int a[605];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\n");
	int ans=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if( (a[i] > a[j] ? gcd(a[i],a[j]) : gcd(a[j],a[i])) ==1  ){
				ans++;
				printf("%d %d ans:%d\n",a[i],a[j],ans);
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
