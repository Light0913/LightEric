#include<bits/stdc++.h>
#include"include_file.h"
using namespace std;
//�����ݾ��ܣ�����
//�������� 
//{ 
string make_password(string p){//������� ���������ܷ���
	string r="";
	for(int i=0;i<p.size();i++){
		r+=p[i]-3;
	}
	return r;
}
string de_password(string p){//������� ���������ܷ��� 
	string r="";
	for(int i=0;i<p.size();i++){
		r+=p[i]+3;
	}
	return r;
}
//}

//�����û��Ľ�Ǯ��Ϣ 
//{
unsigned long long make_money(unsigned long long m){
	return pow(m,2)+23;
}
unsigned long long de_money(unsigned long long m){
	return sqrt(m-23);
}
//}
