/*
����������� 
1�����ƹ�ʽ��
�������һ����ͬ�����һ����ͬ�������� 
��i��j����0��MaxLen(i,j)==0;
��s1��s2�����һ���ַ���ͬʱ��MaxLen(i,j)=MaxLen(i-1,j-1)+1;
��s1��s2�����һ���ַ���ͬʱ��MaxLen(i,j) = Max(MaxLen(i,j-1),MaxLen(i-1,j) ); 
2��֤�� 
S1[i-1]!= s2[j-1]ʱ��MaxLen(S1,S2)�����MaxLen(S1,S2j-1)
��MaxLen(S1i-1,S2)����֮���κ�һ��С��Ҳ��������߶���
��1�������κ�һ��С��MaxLen(S1,S2)�ַ������ں�����
��2��Ҳ��������߶��󣺷�֤������������߶����ǻ�ó�S1[i-1]== s2[j-1]�Ľ��ۣ�������ͻ 
3������
ֱ��д���ƹ�ʽ�ͺ��� 
*/
/*
����һ���������
for(j=1;j<=length2;j++)��©�˵Ⱥţ����Զ�ûִ�е����������Խ������ 
*/
#include <iostream>
#include <cstring> 
using namespace std;
char sz1[1000];//�ַ�����1 
char sz2[1000];//�ַ�����2 
int maxLen[1000][1000];
//MaxLen(i,j)��ʾs1�����i���ַ��γɵ��Ӵ���
//��s2��ߵ�j���ַ��γɵ��Ӵ�������������еĳ���(i,j��0��ʼ�㣩 
int main(){
    //freopen("in.txt","r",stdin); 
    while(cin>>sz1>>sz2){
        int length1=strlen(sz1);//���ַ�����1�ĳ��� 
        int length2=strlen(sz2);//���ַ�����2�ĳ���
        cout<<length1<<" "<<length2<<endl;
        int nTmp;
        int i,j;
        //��ʼ���߽���� 
        for(i=0;i<=length1;i++)
            maxLen[i][0]=0;
        for(j=0;j<=length2;j++)
            maxLen[0][j]=0; 
        //��̬�滮��������������  
        for(i=1;i<=length1;i++){
            for(j=1;j<=length2;j++){
                if(sz1[i-1]==sz2[j-1]){//�ַ������0��ʼ�����ݵ� 
                    //��s1��s2�����һ���ַ���ͬʱ��MaxLen(i,j)=MaxLen(i-1,j-1)+1; 
                    maxLen[i][j]=maxLen[i-1][j-1]+1;
                }    
                else{
                    //��s1��s2�����һ���ַ���ͬʱ��MaxLen(i,j) = Max(MaxLen(i,j-1),MaxLen(i-1,j) );  
                     maxLen[i][j]=max(maxLen[i][j-1],maxLen[i-1][j]);
                }
            } 
                        
        }
        /*
        for(i=1;i<=length1;i++){
            for(j=1;j<=length2;j++){
                cout<<maxLen[i][j]<<" ";
            }
            cout<<endl;
        }
        */ 
        //cout<<length1<<" "<<length2<<endl;
        cout<<maxLen[length1][length2]<<endl;
    }
    return 0;
}
