/*
最长公共子序列 
1、递推公式：
（分最后一个相同和最后一个不同来分析） 
当i或j等于0，MaxLen(i,j)==0;
当s1和s2的最后一个字符相同时，MaxLen(i,j)=MaxLen(i-1,j-1)+1;
当s1和s2的最后一个字符不同时，MaxLen(i,j) = Max(MaxLen(i,j-1),MaxLen(i-1,j) ); 
2、证明 
S1[i-1]!= s2[j-1]时，MaxLen(S1,S2)不会比MaxLen(S1,S2j-1)
和MaxLen(S1i-1,S2)两者之中任何一个小，也不会比两者都大。
（1）不比任何一个小：MaxLen(S1,S2)字符串长于后两者
（2）也不会比两者都大：反证法，假设比两者都大，那会得出S1[i-1]== s2[j-1]的结论，与假设冲突 
3、代码
直接写递推公式就好了 
*/
/*
错误一：结果不对
for(j=1;j<=length2;j++)，漏了等号，所以都没执行到这来，所以结果不对 
*/
#include <iostream>
#include <cstring> 
using namespace std;
char sz1[1000];//字符数组1 
char sz2[1000];//字符数组2 
int maxLen[1000][1000];
//MaxLen(i,j)表示s1的左边i个字符形成的子串，
//与s2左边的j个字符形成的子串的最长公共子序列的长度(i,j从0开始算） 
int main(){
    //freopen("in.txt","r",stdin); 
    while(cin>>sz1>>sz2){
        int length1=strlen(sz1);//求字符数组1的长度 
        int length2=strlen(sz2);//求字符数组2的长度
        cout<<length1<<" "<<length2<<endl;
        int nTmp;
        int i,j;
        //初始化边界情况 
        for(i=0;i<=length1;i++)
            maxLen[i][0]=0;
        for(j=0;j<=length2;j++)
            maxLen[0][j]=0; 
        //动态规划求解最长公共子序列  
        for(i=1;i<=length1;i++){
            for(j=1;j<=length2;j++){
                if(sz1[i-1]==sz2[j-1]){//字符数组从0开始存数据的 
                    //当s1和s2的最后一个字符相同时，MaxLen(i,j)=MaxLen(i-1,j-1)+1; 
                    maxLen[i][j]=maxLen[i-1][j-1]+1;
                }    
                else{
                    //当s1和s2的最后一个字符不同时，MaxLen(i,j) = Max(MaxLen(i,j-1),MaxLen(i-1,j) );  
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
