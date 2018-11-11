#include <cstdio>

int MAX_(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(){
    int s1, s2, s3, s4, s5, s6;
    while(scanf("%d%d%d%d%d%d", &s1, &s2, &s3, &s4, &s5, &s6) && s1+s2+s3+s4+s5+s6){
        int packets = 0;
        packets += s6; // 6*6�Ĳ�Ʒһ��װһ��
        
        packets += s5; // 5*5�Ĳ�Ʒһ��װһ��
        s1 = MAX_(0, s1-11*s5); // ʣ��ռ���1*1�Ĳ�Ʒ��������
        
        packets += s4; // 4*4�Ĳ�Ʒһ��װһ��
        if(s2<5*s4) s1 = MAX_(0, s1-(5*s4-s2)); // ����2*2�Ĳ�Ʒ����֮����Ȼ�п�϶������1*1���� 
        s2 = MAX_(0, s2-5*s4); // ������2*2�Ĳ�Ʒ���� 
        
        packets += (s3+3)/4; // 3*3�Ĳ�Ʒ�ĸ�һ��
        s3 %= 4;            // ����3*3�����Ӳ����ĵı�������������2*2�������1*1��� 
        if(s3==1){
            if(s2<5) s1 = MAX_(0, s1-(27-4*s2));
            else     s1 = MAX_(0, s1-7);
            s2 = MAX_(0, s2-5);
        } 
        else if(s3==2){
            if(s2<3) s1 = MAX_(0, s1-(18-4*s2));
            else     s1 = MAX_(0, s1-6);
            s2 = MAX_(0, s2-3);
        }
        else if(s3==3){
            if(s2<1) s1 = MAX_(0, s1-(9-4*s2));
            else     s1 = MAX_(0, s1-5);
            s2 = MAX_(0, s2-1);    
        }
        
        packets += (s2+8)/9; // 2*2�Ĳ�Ʒ�Ÿ�һ��
        s2 %= 9;             // ����2*2�����Ӳ��Ǿŵı�����������1*1���
        if(s2) s1 = MAX_(0, s1-(36-4*s2)); 
        
        packets += (s1+35)/36; // 1*1�Ĳ�Ʒ��ʮ����һ��
        
        printf("%d\n", packets); 
    } 
    
    return 0;
}
