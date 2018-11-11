#include<stdio.h>
#include<stdlib.h>
typedef struct node{
	int id;
	struct node *next;
}Node;
typedef struct graph{
	//int num;
	Node **a;
}Graph;

int DFS(Graph g,int v,bool *visit,int h){
	Node *w;
	visit[v]=true;
	h++;
	for(w=g.a[v]; w; w=w->next){
		if(!visit[w->id]){
			DFS(g,w->id,visit,h);
		}else{
			return h;
		}
	}
}

int main(){
	int n;
	int i=0;
	double p,r;
	scanf("%d %lf %lf",&n, &p, &r);
	
	Graph g;
	//g.num = n;
	g.a=(Node**)malloc(n*sizeof(Node*));
	for(i=0;i<n;i++){
		g.a[i]=NULL;
	}
	
	i=0;
	while(i<n){
		int k;
		scanf("%d",&k);
		int j=0;
		while(j<k){
			int ni;
			scanf("%d",&ni);
			Node *p = (Node*)malloc(sizeof(Node));
			p->id=ni;
			p->next=g.a[i];
			g.a[i]=p;
			j++;	
		}
		i++;
	}
	
	bool visit[100001]; 
	int h;
	int num=1;
	int min=n;
	for(i=0;i<n;i++){
		visit[i]=false;
	}
	for(i=0;i<n;i++){
		if(!visit[i]){
			h=0;
			h=DFS(g,i,visit,h);
			if(h<min){
				min=h;
				num=1;
			}else if(h == min){
				num++;
			}
		}
	}
	
	printf("%d",num);
	
	for(i=0;i<n;i++){
		if(g.a[i]!=NULL){
			Node *w;
			w=g.a[i]->next;
			while(w){
				g.a[i]=w->next;
				free(w); 
			}
		}
	}
	free(g.a);
	return 0;
} 

