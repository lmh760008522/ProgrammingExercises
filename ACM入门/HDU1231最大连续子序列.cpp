//˼·���� 
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d", &n) != EOF){
		if(n == 0){
			break;
		}
		int l = -1, r = -1, sum = 0;
		int max = -1, l_max = -1, r_max = -1;//��ֻ��һ��0ʱ�����ֵΪ0������Maxһ��ʼҪ����һ��С��0���� 
		bool flag = false, lianxu = false;
		for(int i = 0; i < n; i++ ){
			int x;
			scanf("%d", &x);
			if(x<0){
				if(lianxu == false){
					if(sum > max){
						max = sum;
						l_max = l;
						r_max = r;	
					}
					lianxu = true;
					l = r = x; 
					sum = 0;
					flag = false;
				}else{
					r = x;
				}
				
				continue;
			}else{//����x=0 �������������Ŀ��û˵
				lianxu = false; 
				sum += x;
				r = x;
				if(flag == false){
					flag = true;
					l = x;
				}	
			}
		}
		if(l_max == -1 && r_max == -1){
			printf("%d %d %d\n", 0, l, r);
		}
		printf("%d %d %d\n", sum, l_max, r_max); 
	}
	return 0;
}

/* 
#include <iostream>
 
using namespace std;
 
int main()
{
    // max, maxstart, maxendΪһ�飬���Ѿ���õ�����Ӷκ�
    // sum, sumstart, jΪһ�飬�ǵ�ǰ���ڽ��м��������Ӷκ�
    // ��ǰ���Ӷβ��ٵ�������ʱ�������¿���һ���µ��Ӷ�
    int n, now, max, maxstart, maxend, sum, sumstart, first;
    while(cin >> n && n) {
        // һ��Ԫ��ʱ��������Ŀǰ������Ӷκͣ�����Ӷκ͵���ʼ����ֹ�ֱ���maxstart��end
        cin >> now;
        max = maxstart = maxend = first = now;
        sum = sumstart = now;
 
        for(int j=2; j<=n; j++) {
            cin >> now;
 
            if(sum < 0)
                sum = sumstart = now;
            else
                sum += now;
 
            // ��ǰ���ڽ��м��������Ӷκͳ���֮ǰ������Ӷκͣ�����������Ӷκ�
            if(sum > max)
                max = sum, maxstart = sumstart, maxend = now;
        }
 
        if(max < 0)
            cout << "0 " << first << " " << now << endl;
        else
            cout << max << " " << maxstart << " " << maxend << endl;
    }
 
    return 0;
}

*/ 
