#include<iostream>  
#include<string>  
using namespace std;
 
struct Node
{
    double weight;  
    string ch;  
    string code; 
    int lchild, rchild, parent;
};

void Select(Node huffTree[], int *a, int *b, int n)//��Ȩֵ��С������a��b  
{
    int i;
    double weight = 0; //����С����
    for (i = 0; i <n; i++)
    {
        if (huffTree[i].parent != -1)     //�жϽڵ��Ƿ��Ѿ�ѡ��
            continue;
        else
        {
            if (weight == 0)
            {
                weight = huffTree[i].weight;
                *a = i;
            }
            else
            {
                if (huffTree[i].weight < weight)
                {
                    weight = huffTree[i].weight;
                    *a = i;
                }
            }
        }
    }
    weight = 0; //�ҵڶ�С����
    for (i = 0; i < n; i++)
    {
        if (huffTree[i].parent != -1 || (i == *a))//�ų���ѡ������
            continue;
        else
        {
            if (weight == 0)
            {
                weight = huffTree[i].weight;
                *b = i;
            }
            else
            {
                if (huffTree[i].weight  < weight)
                {
                    weight = huffTree[i].weight;
                    *b = i;
                }
            }
        }
    }
    int temp;
    if (huffTree[*a].lchild < huffTree[*b].lchild)  //С���������
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}

void Huff_Tree(Node huffTree[], int w[], string ch[], int n)
{
    for (int i = 0; i < 2 * n - 1; i++) //��ʼ����
    {
        huffTree[i].parent = -1;    
        huffTree[i].lchild = -1;    
        huffTree[i].rchild = -1;  
        huffTree[i].code = "";
    }
    for (int i = 0; i < n; i++)       
    {
        huffTree[i].weight = w[i];  
        huffTree[i].ch = ch[i];     
    }
    for (int k = n; k < 2 * n - 1; k++)
    {
        int i1 = 0;
        int i2 = 0;
        Select(huffTree, &i1, &i2, k); //��i1��i2�ڵ�ϳɽڵ�k
        huffTree[i1].parent = k;   
        huffTree[i2].parent = k;
        huffTree[k].weight = huffTree[i1].weight + huffTree[i2].weight;
        huffTree[k].lchild = i1;
        huffTree[k].rchild = i2;
    }
}
 
void Huff_Code(Node huffTree[], int n)
{
    int i, j, k;
    string s = "";
    for (i = 0; i < n; i++)  
    {
        s = "";         
        j = i;                
        while (huffTree[j].parent != -1) //��Ҷ�������ҵ����ڵ�
        {
            k = huffTree[j].parent;
            if (j == huffTree[k].lchild) //����Ǹ������ӣ����Ϊ0
            {
                s = s + "0";
            }
            else               
            {
                s = s + "1";
            }
            j = huffTree[j].parent; 
        }
        cout << "�ַ� " << huffTree[i].ch << " �ı��룺";
        for (int l = s.size() - 1; l >= 0; l--)    
        {
            cout << s[l];
            huffTree[i].code += s[l]; //�������
        }
        cout << endl;
    }
}

string Huff_Decode(Node huffTree[], int n,string s)
{
    cout << "�����Ϊ��";
    string temp = "",str="";//����������ַ���
    for (int i = 0; i < s.size(); i++)
    {
        temp = temp + s[i];
        for (int j = 0; j < n; j++)
        {    
            if (temp == huffTree[j].code)
            {
                str=str+ huffTree[j].ch;
                temp = "";
                break;
            }    
            else if (i == s.size()-1&&j==n-1&&temp!="")//ȫ��������û��
            {
                str= "�������";
            }
        }
    }
    return str;
}

int main()
{
    //�������
    const int n=5;
    Node huffTree[2 * n];
    string str[] = { "A", "B", "C", "D", "E"};
    int w[] = { 30, 30, 5, 20, 15 };
    Huff_Tree(huffTree, w, str, n);
    Huff_Code(huffTree, n);
    //�������
    string s;
    cout << "������룺";
    cin >> s;
    cout << Huff_Decode(huffTree, n, s)<< endl;;
    system("pause");
    return 0;
}
