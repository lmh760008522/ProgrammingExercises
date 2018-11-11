#include<iostream>
#include<cstdlib>
using namespace std;

int find_sps_in_h264(unsigned * character, int N)
{
	int node[2];
	node[0]=0;
	node[1]=0;
	int k=0;
	for(int i=0;i<N-2;i++)
	{
		if(character[i]==0 && character[i+1]==0 && character[i+2]==1)
		{
			node[k++]=i;
		}
	}
	node[0]=node[0]+3;
	for(int i=node[0];i<=node[1]-1;i++) //Ô­£º for(int i=node[0];i<node[1]-1;i++)
	{ 
		/* 
		if(character[i] != 3)
		{
			if(character[i] == 0)
			{
				printf("%x ",character[i]);
				continue;
			}
			printf("%02x ",character[i]);
		}*/
		if(character[i] == 3 && i>=2 && character[i-1] == 0 &&character[i-2] == 3) {
			continue;
		}else if(character[i]==0){
			printf("%x ",character[i]);
		}else{
			printf("%02x ",character[i]);
		}
	}
	printf("%02x",character[node[1]-1]); 
	return 0;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		unsigned *character=new unsigned[n];
		for(int j=0;j<n;j++)
		{
			scanf("%x",&character[j]);
		}
		find_sps_in_h264(character,n);
	}
	return 0;
}

