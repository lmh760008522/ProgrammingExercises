#include<stdio.h>
#include<string.h>

//边界问题，万一都不符合，所已要赋值，但是出现格式错误，因此需要特判count
int main(){
    int n,count=0,min_y=1813,max_y=2015,min_m=0,max_m=13,min_d=0,max_d=31,year,month,day;
    char name[6],max[6]={},min[6]={},baocun[11];//注意：所有都是6，name[5],baocun[10]会发生错误，因为字符串最后有一个结束标识符
    scanf("%d",&n);
    //printf("%d",n);

    while(n>0){


        scanf("%s%s",name,baocun);//scanf("%s %s",name,baocun);不对，，，空格也被录入
        //puts(min);
        //puts(max);
        //printf(" %d \n",n);
        //puts(name);
        //puts(baocun);

        year=(baocun[0]-48)*1000+(baocun[1]-48)*100+(baocun[2]-48)*10+(baocun[3]-48);
        month=(baocun[5]-48)*10+baocun[6]-48;
        day=(baocun[8]-48)*10+baocun[9]-48;

    //printf("%d %d %d",year,month,day);
        //puts(min);
        if(((year>1814)&&(year<2014))||(year==1814&&month>9)||(year==1814&&month==9&&day>=6)||(year==2014&&month<9)||(year==2014&&month==9&&day<=6)){
            count++;
            if(max_y>year){
                strcpy(max,name);
                max_y=year;
                max_m=month;
                max_d=day;
            }else if(max_y==year){
                if(max_m>month){
                    strcpy(max,name);
                    max_m=month;
                    max_d=day;
                }else if(max_m==month){
                    if(max_d>day){
                        strcpy(max,name);
                        max_d=day;
                    }
                }
            }

             if(min_y<year){
                strcpy(min,name);
                min_y=year;
                min_m=month;
                min_d=day;
                //printf("stypy ok!\n");
            }else if(min_y==year){
                if(min_m<month){
                    strcpy(min,name);
                    min_m=month;
                    min_d=day;
                }else if(min_m==month){
                    if(min_d<day){
                        strcpy(min,name);
                        min_d=day;
                    }
                }
            }

        }
        //printf("max:%d %d %d",max_y,max_m,max_d);
       //puts(max);
        //printf("min:%d %d %d",min_y,min_m,min_d);
        //puts(min);
        n--;
    }
    //printf(" %d ",n)

    if(count!=0){
        printf("%d ",count);
        printf("%s %s",max,min);
    }else{
        printf("0\n");
    }


    return 0;
}
