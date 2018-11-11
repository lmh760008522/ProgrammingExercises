#include<cstdio>
#include<queue>
#include<vector>
using namespace std;
//²»»á×ö
 
//queue q;
vector<char> v;
void shengcheng(int n,int x,int y){
	if(n==0 && x==y==n/2 ){
		for(int i=0;i<v.size();i++){
			printf("%c",v[i]);
		}
		return ;
	}
	if(x<n/2 && y<n/2){
		v.push_back('(');
		shengcheng(n-1,x+1,y);
		if(x>y){
			v.pop_back();
			v.push_back(')');
			shengcheng(n-2,x,y+1);
		}
		v.pop_back();
	}else if(x>=n/2 && y<n/2){
		v.push_back(')');
		shengcheng(n-1,x,y+1);
	}
	return;
}

int main(){
	int n;
	scanf("%d",&n);
	shengcheng(2*n,0,0);
	return 0;
} 

/*
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParenthesisDFS(n, n, "", res);
        return res;
    }
    void generateParenthesisDFS(int left, int right, string out, vector<string> &res) {
        if (left > right) return;
        if (left == 0 && right == 0) res.push_back(out);
        else {
            if (left > 0) generateParenthesisDFS(left - 1, right, out + '(', res);
            if (right > 0) generateParenthesisDFS(left, right - 1, out + ')', res);
        }
    }
};
*/ 
