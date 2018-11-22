//思路不对 
#include<stdio.h>
int main(){
	int n;
	while( scanf("%d", &n) != EOF){
		if(n == 0){
			break;
		}
		int l = -1, r = -1, sum = 0;
		int max = -1, l_max = -1, r_max = -1;//当只有一个0时，最大值为0，所以Max一开始要设置一个小于0的数 
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
			}else{//考虑x=0 的情况，不过题目中没说
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
    // max, maxstart, maxend为一组，是已经求得的最大子段和
    // sum, sumstart, j为一组，是当前正在进行计算的最大子段和
    // 当前的子段不再单调增大时，则重新开启一个新的子段
    int n, now, max, maxstart, maxend, sum, sumstart, first;
    while(cin >> n && n) {
        // 一个元素时，它就是目前的最大子段和；最大子段和的起始和终止分别是maxstart和end
        cin >> now;
        max = maxstart = maxend = first = now;
        sum = sumstart = now;
 
        for(int j=2; j<=n; j++) {
            cin >> now;
 
            if(sum < 0)
                sum = sumstart = now;
            else
                sum += now;
 
            // 当前正在进行计算的最大子段和超过之前的最大子段和，则重置最大子段和
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
