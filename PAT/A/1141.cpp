//STL
//����id ,������ ѧУ
//��һ������ܹ��ж��ٸ�ѧУ
//���򣬼����Ȩ�������������Ӹߵ�������,���������ͬ�����ն���������С�������� ,�ٰ���ĸ������ 
//��ӡ ���ʣ�ѧУ����Ȩ�ܷ� ���Լ�ÿ��ѧУ�еĶ��� 
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct node{
	string school;
	int num_tees;//��������
	int score;//��Ȩ���� 
}node; 

bool cmp(node a, node b){
	if(a.score == b.score){
		if(a.num_tees == b.num_tees){
			return a.school < b.school;
		}
		return a.num_tees < b.num_tees;
	} 
	return a.score > b.score;
}

int main(){
	int n; // n<=100000
	cin>>n;
	map<string, double> all_score;
	map<string, int> all_tees;
	
	for(int i=0;i<n;i++){
		string id, school;
		double score;
		cin>>id>>score>>school;
		//ת����Сд 
		transform(school.begin(), school.end(), school.begin(), ::tolower);
		if(id[0] == 'B'){
			score = score / 1.5;
		}else if(id[0] == 'T'){
			score = score * 1.5;
		}
		all_tees[school]++;
		all_score[school] += score;
	}
	
	map<string, double>::iterator it1;
	map<string, int>::iterator it2;
	vector<node> v;
	for(it1 = all_score.begin(), it2 = all_tees.begin(); it1!=all_score.end(); it1++, it2++){
		node temp;
		temp.school = it1->first;
		temp.score = int(it1->second);
		temp.num_tees = it2->second; 
		v.push_back(temp);
	}
	sort(v.begin(), v.end(), cmp); 
	printf("%d\n",v.size());
	int rank =1, init_score = v[0].score;
	cout<<rank<<" "<<v[0].school<<" "<<v[0].score<<" "<<v[0].num_tees<<endl;
	for(int i=1;i<v.size();i++){
		if(v[i].score != init_score){
			rank = i+1;
			init_score = v[i].score;
		}
		cout<<rank<<" "<<v[i].school<<" "<<v[i].score<<" "<<v[i].num_tees<<endl;
	}
	return 0;
}
