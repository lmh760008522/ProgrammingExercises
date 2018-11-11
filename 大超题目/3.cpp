#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<iostream>
using namespace std; 

typedef struct node{
	char c;//字符 
	int num;//出现次数 
	struct node *left,*right; 
}node;

/*
typedef struct bianma{
	char c;
	string s;
}bianma;*/

bool cmp(node a,node b){
	if(a.num==b.num){
		return a.c>b.c;
	}
	return a.num<b.num;
}

vector<node> v;
//vector<bianma> ans;
map<char ,string> ans;
void fuzhi(string s,node *root){
	//printf("0 ");
	//printf("%c ",root->c);
	if(root->left ==NULL && root->right==NULL){//是叶子结点 
		printf("make %c ",root->c);
		ans.insert( make_pair(root->c,s));
		//cout<<s<<endl;
		return; 
	}
	printf("1 ");
	if(root->left!=NULL){
		fuzhi(s+'0',root->left);
	}
	printf("2 ");
	if(root->right!=NULL){
		fuzhi(s+'1',root->right);
	}
}

int main(){
	int t;
	scanf("%d\n",&t);
	char s[105];
	
	
	for(int i=0;i<t;i++){
		gets(s);
	//	memset(num,0,sizeof(num));
		set<char> alpha;
		
		for(int i=0;i<strlen(s);i++){
			if( alpha.find(s[i]) == alpha.end() ){//没找到 
				node d;
				d.c=s[i];
				d.num=1;
				d.left=NULL;
				d.right=NULL;
				v.push_back(d);
				alpha.insert(s[i]);
			}else{
				for(int j=0;j<v.size();j++){
					if(v[j].c==s[i]){
						v[j].num++;
					}
				}
			}
		}
		
		sort(v.begin(),v.end(),cmp);//按照优先级排序 
		
		for(int j=0;j<v.size();j++){
			//printf("%d %d %c\n",j,v[j].num,v[j].c);
			v[j].num=j+1;//复权 
		}
		
		
		printf("复权：\n");
		for(int j=0;j<v.size();j++){
			printf("%d %c\n",v[j].num,v[j].c);
		}
		
		node* root;
		while(v.size()>1){
			node a;
			a.c=v[0].c;
			a.num=v[0].num;
			a.left=a.right=NULL;
			
			node b;
			b.c=v[1].c;
			b.num=v[1].num;
			b.left=b.right=NULL;
			
			node temp;
			temp.c='*';
			temp.num=a.num+b.num;
			temp.left=&a;
			temp.right=&b;
			root=&temp;
			
			v.push_back(temp);
			v.erase(v.begin());
			v.erase(v.begin());
			sort(v.begin(),v.end(),cmp);//按照优先级排序
			
			printf("构建：\n");
			for(int j=0;j<v.size();j++){
				printf("%d %d %c\n",v.size(), v[j].num,v[j].c);
			}
		} 
		
		fuzhi("",root);
		printf("ok\n");
		
		for(map<char,string>::iterator iter = ans.begin(); iter!=ans.end();iter++){
			printf("%c ", iter->first);
			cout<<iter->second<<endl;
		}
		 
	} 
	
	return 0;
}
