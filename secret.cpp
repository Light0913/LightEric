#include<iostream>
#include"include_file.h"
using namespace std;
//�����ݾ��ܣ�����
//�������� 
//{ 
string make_password(string p){//������� ���������ܷ���
	string r="";
	for(int i=0;i<p.size();i++){
		r+=p[i]-23;
	}
	return r;
}
string de_password(string p){//������� ���������ܷ��� 
	string r="";
	for(int i=0;i<p.size();i++){
		r+=p[i]+23;
	}
	return r;
}
//}
