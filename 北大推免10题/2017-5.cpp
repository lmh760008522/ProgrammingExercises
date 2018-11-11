#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;


double char_2_int(char ch){
    return ch - 'A' + 1;
}

double target;
char upper[15];
int main(){

    while(scanf("%lf%s", &target, upper)&&(target != 0 || strcmp(upper,"END") != 0)){
        sort(upper,upper+strlen(upper));
        int sum;
        int falg = 0;
        string str;
        for(int i = 0; upper[i]; i++){
            for(int j = 0; upper[j]; j++){
                for(int k = 0; upper[k];k++){
                    for(int l = 0; upper[l]; l++){
                        for(int m = 0; upper[m]; m++){
                            if(i != j && i != k && i != l && i != m && j != k &&
                               j != l && j != m && k != l && k != m && l != m){
                                    sum = char_2_int(upper[i]) - char_2_int(upper[j]) *
                                    char_2_int(upper[j]) + char_2_int(upper[k]) *char_2_int(upper[k]) *
                                    char_2_int(upper[k]) - char_2_int(upper[l]) *char_2_int(upper[l]) *
                                    char_2_int(upper[l]) *char_2_int(upper[l]) + char_2_int(upper[m]) *
                                    char_2_int(upper[m]) *char_2_int(upper[m]) *char_2_int(upper[m]) *
                                    char_2_int(upper[m]);
                                    if(sum == target){
                                        falg = 1;
                                        str = "";
                                        str = str + upper[i]+upper[j]+upper[k]+upper[l]+upper[m];
                                        //printf("%c%c%c%c%c%c\n",upper[i],upper[j],upper[k],upper[l],upper[m]);
                                        break;
                                    }
                               }
                        }
                    }
                }
            }
        }
        if(falg == 1)  {
            printf("%s\n", str.c_str());
        }
        else printf("no solution\n");
    }
    return 0;
}
