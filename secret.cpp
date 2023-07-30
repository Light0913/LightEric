#include<bits/stdc++.h>
#include"include_file.h"
using namespace std;
//此内容绝密！！！
//加密密码 
//{ 
string make_password(string p){//密码加密 （凯撒加密法）
	string r="";
	for(int i=0;i<p.size();i++){
		r+=p[i]-23;
	}
	return r;
}
string de_password(string p){//密码解密 （凯撒解密法） 
	string r="";
	for(int i=0;i<p.size();i++){
		r+=p[i]+23;
	}
	return r;
}
//}

//加密用户的金钱信息 
//{
unsigned long long make_money(unsigned long long m){
	return pow(m,2)+23;
}
unsigned long long de_money(unsigned long long m){
	return sqrt(m-23);
}
//}
