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
		cout<<"请输入你需要转换的数的进制>>>";
		cin >> x;
		cout<<"请输入你需要转换的数>>>";
		cin >> a;
		cout<<"请输入你希望转换的进制>>>";
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
		cout<<"最终输出是：";
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
		error("你的输入有误或积分不足！");
	}
	
	return m;
}
