#include<stdio.h>
#include<set>
#include<string>
#include<iostream>
using namespace std;

int main(){
	int n;
	while( scanf("%d", &n) != EOF){
		if( n == 0){
			break;
		}
		set<string> win, lose;
		win.clear();
		lose.clear();
		
		for(int i=0; i<n; i++){
			string w,l;
			cin>>w>>l;
			
			set<string>::iterator iter;
			iter = lose.find(w);
			if(iter == lose.end()){//找不到 
				win.insert(w);
				lose.insert(l);	
			}else{
				lose.erase(w);
				lose.insert(l);
			}
			
			//set<string>::iterator iter;
			iter = win.find(l);
			if(iter == win.end()){//找不到 
				lose.insert(l);	
			}else{
				win.erase(l);
				lose.insert(l);
			}
		}
		//printf("%d", win.size());
		//set<string>::iterator it;
		//for(it=win.begin();it!=win.end();it++) 
    	//	cout<<*it<<endl; 
		if(win.size() == 1){
			printf("YES\n");
		}else{
			printf("NO");
		}
	}
	return 0;
}

/*
优化： 只有唯一1个人没有输时，才产生冠军。
 
#include <iostream>
#include <string>
#include <set>
 
using namespace std;
 
int main()
{
    int n;
    set<string> all, lose;
    string Winner, loser;
 
 
    while(cin >> n && n != 0) {
        all.clear();
        lose.clear();
 
        while(n--) {
            cin >> Winner >> loser;
 
            all.insert(Winner);
            all.insert(loser);
 
            lose.insert(loser);
        }
 
        // 只有一人没有输，才有冠军
        if(all.size() - lose.size() == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
 
    return 0;
}
*/ 
