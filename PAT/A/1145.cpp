//21/11/18 19:48   21/11/18 19:58    21/11/18 20:29  21/11/18 20:44
//�Ƚ�һ�Ѳ�ͬ�ģ�distinct������ �Ž�һ����ϣ��
//�ӹ�ϣ�����ҵ������������ �������ƽ��Ѱ��ʱ�䣨���Ƚϵ�������
//��ϣ���壺H(key) = key%T , T = ��ϣ������ֵ
//�����ͻ�ķ���������̽�ⷨ���������������� ����Quadratic probing
//ע�����С���������(prime) ������������ֵ������������ô�ҵ������ֵ�����С������
#include<stdio.h>
#include<math.h>

int hash_table[10005];
int msize, n, m;

bool isprime(int n) {
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main(){
	scanf("%d %d %d", &msize, &n, &m);
	
	while(!isprime(msize)){
		msize++;
	}
	
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		if(hash_table[x % msize] == 0){
			hash_table[x % msize] = x;
		}else{
			bool flag = false;
			for(int k =1; k < msize; k++){
				if( hash_table[(x + k*k) % msize] == 0){
					hash_table[(x + k*k) % msize] = x;
					flag = true;
					break;
				}
			}
			if( flag == false){//δ�ɹ����� 
				printf("%d cannot be inserted.\n", x);
			}
		}
	}
	int sum = 0;
	for(int i=0;i<m;i++){
		int x;
		scanf("%d", &x);
		for(int k = 0; k <= msize; k++){
			sum++;
			if( hash_table[(x + k*k) % msize] == x || hash_table[(x + k*k) % msize] == 0){//�ҵ��˻򲻴��� 
				break;
			}
		}
	}
	printf("%.1f\n", double(sum)/m);
	return 0;
} 

//21/11/18 20:45 ������ȷ 
