#include<bits/stdc++.h>
#include<windows.h>
#include"include_file.h"
using namespace std;
unsigned long long game_run(string g,unsigned long long m){
	c:
	if(g=="1"&&m>=10){
		m-=10;
		using namespace std;
		string a;
		int c[10000], x, y, e, top = 0, sum;
		cout<<"����������Ҫת�������Ľ���>>>";
		cin >> x;
		cout<<"����������Ҫת������>>>";
		cin >> a;
		cout<<"��������ϣ��ת���Ľ���>>>";
		cin >> y;
		for(int i=0;i<a.size();i++){
		    if(a[i]<'A'){
		       e=(a[i]-'0')*pow(x,a.size()-i-1);
		        sum+=e;
		    }
		    else{
		        e=(a[i]-'A'+10)*pow(x,a.size()-i-1);
		        sum+=e;
		    }
		}
		while(sum>0){
		    c[top]=sum%y;
		    top++;
		    sum/=y;
		}
		cout<<"��������ǣ�";
		for (int i = top - 1; i >= 0; i--) {
		    if (c[i] >= 10) {
		        cout << (char)(c[i] + 'A' - 10);
		    } else {
		        cout << c[i];
		    }
		}
		cout<<endl;
	}
	else{
		error("��������������ֲ��㣡");
	}
	
	return m;
}
