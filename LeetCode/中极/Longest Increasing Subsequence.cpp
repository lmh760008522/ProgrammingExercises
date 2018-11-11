#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
int main(){
	int a[8]={10, 9, 2, 5, 3, 7, 101, 18};
	int n=8;
	int dp[100];
	//memset(dp,1,sizeof(dp));
	for(int i=0;i<n;i++){
		dp[i]=1;
	}
	int res=0;
	for(int i=0;i<8;i++){
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				dp[i]=max(dp[i], dp[j]+1);
			}
		}
		res=max(res,dp[i]);
	}
	printf("%d",res);
	
	
	//������������һ���Ż�ʱ�临�Ӷȵ�O(nlgn)�Ľⷨ�������õ��˶��ֲ��ҷ������Բ��ܼӿ�����ʱ���ۡ�
	//˼·�ǣ������Ƚ���һ������ends������Ԫ�طŽ�ȥ��Ȼ��Ƚ�֮���Ԫ�أ��������������Ԫ�ر�ends�����е���Ԫ��С�Ļ���
	//�滻��Ԫ��Ϊ����Ԫ�أ��������������Ԫ�ر�ends�����е�ĩβԪ�ػ���Ļ���������Ԫ����ӵ�ends����ĩβ(ע�ⲻ����ԭĩβԪ��)��
	//�������������Ԫ�ر�ends������Ԫ�ش󣬱�βԪ��Сʱ����ʱ�ö��ֲ��ҷ��ҵ���һ����С�ڴ���Ԫ�ص�λ�ã�
	//���ǵ�λ�õ�ԭ�������֣��Դ�����ֱ������������nums���飬��ʱends����ĳ��Ⱦ�������Ҫ���LIS�ĳ��ȣ�
	//�ر�ע�����ends�����ֵ���ܲ���һ����ʵ��LIS����������������numsΪ{4, 2�� 4�� 5�� 3�� 7}��
	//��ô������ends����Ϊ{2�� 3�� 5�� 7}�����Է���������һ��ԭ�����LIS��ֻ�ǳ�����ȶ��ѣ�ǧ��Ҫע����㡣�μ��������£�
	
	int end[8];
	end[0]=a[0];
	int ends=0;
	for(int i=0;i<n;i++){
		if(a[i]<end[0]){
			end[0]=a[i];
		}else if(a[i]>end[ends]){
			ends++;
			end[ends]=a[i];
		}else{
			int left=0,right=ends;
			while(left<=right){
				int mid=(left+right)/2;
				if(end[mid]<a[i]){
					left=mid+1;
				}else{
					right=mid;
				}
			}
			end[right]=a[i];
		}
	}
	printf(" -- %d",ends);
	return 0;
}
