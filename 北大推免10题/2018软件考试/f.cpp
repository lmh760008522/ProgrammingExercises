//M���ˣ�һ��ʼÿ���յ�n�����ƣ�ÿ�������������ΪN*M��û��һ����ȫ��ͬ
//˭�������Ӯ�ñ��ֱ���
//N��֮��˭��������ʤ
//����Ӯ�õ�������� 
//m,n  ����������
//n����
//���� 
//0��0����
#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int m , n , Case = 0 ;
    int a[1005];
    while(cin>>m>>n,m||n){
        Case++;
        for(int i = 0 ; i < n ; i++){
            cin>>a[i];
        }
        sort(a,a+n);      //��С�������� 
        int win = 0 , lose = 0 ;
        int max = n*m ;   //�洢���������� 
        for(int i = n - 1 ; win+lose != n ; i-- ){ //win+lose==n ��ʾ���ϵ����Ѿ����� 
            if(max==a[i]){
                win++;    //����������==����������ʱ,��Ӯһ�� 
                max--;       //Ӯ��,����������ֵֻҪ��һ���� 
            } 
            else{         //����,����һ�Ρ� 
                lose++;   //��¼��Ĵ��� 
                max-=2;   //����,����������ֵ����
            } 
        }
        cout<<"Case "<<Case<<": "<<win<<endl;
    }
    return 0;
}
