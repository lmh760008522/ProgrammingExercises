#include<cstdio>
#include<cstring>

typedef struct node{
	char val;
	struct node *l, *r;
}node;
node *root;

void insert(char val){
	if(root->val=='0'){
		root->val=val;
		return;
	}
	node *p=root ,*q=NULL;
	while(p!=NULL){
		q=p;
		if(val  > p->val){
			p=p->r;
		}else if(val < p->val){
			p=p->l;
		}else{
			return;
		}
	}
	node *temp;
	temp->val=val;
	temp->r=temp->l=NULL;
	if(val < q->val){
		q->l = temp;
	}else if(val > q->val){
		q->r = temp;
	}
	return;
}

void pre(node *root){
	printf("%c",root->val);
	if(root->l!=NULL){
		pre(root->l);
	}
	if(root->r!=NULL){
		pre(root->r);
	}
	return;
}

int main(){
	char s[26];
	char tree[100];
	root->l==root->r==NULL;
	root->val='0';
	int len = 0;
	while(true){
		gets(s);
		if(s=="$"){
			break;
		}else{
			if(s=="*"){
				for(int i=len-1;i>=0;i--){
					insert(tree[i]);
				}
				pre(root);
				len = 0;
				root->l==root->r==NULL;
				root->val='0';
			}else{
				strncpy(tree+len,s,strlen(s));
				len+=strlen(s);
			}
		}
	}
}
