#include<stdio.h>
#include<map>
#include<string>
#include<utility>
#include<vector>
/*
    PAT��ʱ������һ��û����ô�ϸ񣬵���������������Ҫ����hash��������
    ���ҿӶ���ʹ��stl�е�map������
    ����˵��map��ʹ����string==�����ң���ɳ�ʱ������������class A,����==
    ��<,���ֽ���������һ�����Ե㳬ʱ��

    map�ڲ���ͨ��ƽ���������ɲ��ҵģ���hash��ͨ��ֱ�ӵ�ַӳ����ɣ��ǳ�������
    �ܽ�: 
    1.string cin cout���Ǻ�ʱ����
    2.map��ʹ��==�����жϣ�string��==��Ϊ����,���һ�����Ե㳬ʱ
    3.vector.size()���ص���unsinged int����,Ҳ����˵֧��2^32��Ԫ��
     */
using namespace std;
int main(){
	vector<pair(string, vector<int>)> a;
	int n,k;
	int id,num;
	scanf("%d %d",&n,&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&id,&num);
		for(int j=0;j<num;j++){
			scanf("%s");
		}
	}
	return 0
}
