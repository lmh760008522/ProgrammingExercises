#include<iostream>
#include<map>
using namespace std;
map<int, long long > kehu;
int main(){
	int q;
	while(1){
		cin>>q;
		switch(q){
			case 0: return 0;
			case 1:{
				int id;
				long long p;
				cin>>id>>p;
				kehu[id]=p;
				break;
			}
			case 2:{
				int max=0,maxi=0;
				map<int, long long > ::iterator iter=kehu.begin();
				if(kehu.size()==0){
					cout<<"0"<<endl;
					break;
				}
				for( ; iter!=kehu.end();iter++){
					if(iter->second > max){
						maxi=iter->first;
						max=iter->second;
					}
				}
				cout<<maxi<<endl;
				kehu.erase(maxi);
				break;
			}
			case 3:{
				int min=99999999,mini=99999999;
				map<int, long long > ::iterator iter=kehu.begin();
				if(kehu.size()==0){
					cout<<"0"<<endl;
					break;
				}
				for( ; iter!=kehu.end();iter++){
					if(iter->second < min){
						mini=iter->first;
						min=iter->second;
					}
				}
				cout<<mini<<endl;
				kehu.erase(mini);
				break;
			}
			default: break;
		}
	}
	return 0;
}
