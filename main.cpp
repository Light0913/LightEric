#include<bits/stdc++.h>
#include<direct.h>
#include<windows.h>
/*
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<cstdio>
*/
using namespace std;

char username[20]="";
char password[30]="";
bool admin=0;

//储存用户数据./users/data/{用户名username}.dat
//{
struct userdata{
	bool is_admin;
}userdata;
//}
//储存程序信息./data.dat
//{ 
struct maindata{
	bool creat_agreement;//协议 
}maindata;
//}

int main();

void color(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void info(string a){//颜色表：{0黑色}{1蓝色}{2绿色}{3亮蓝色}{4红色}{5紫色}{6黄色}{7白色}{8灰色}{9淡蓝色}
	color(10,0);//{10亮绿色}{11亮浅绿色}{12亮红色}{13亮紫色}{14亮黄色}{15亮白色（编辑器初始颜色）}
	cout<<"[信息]"<<a<<endl;
	color(15,0);
}
void info(string c,string a){
	color(10,0);
	cout<<"[信息]"<<c<<"    "<<a<<endl;
	color(15,0);
}
void info(string c,string a,bool is_admin){
	if(is_admin){
		color(13,0);
		cout<<"[信息]"<<c<<"    "<<a<<endl;
		color(15,0);
	}
}
void error(string a){
	color(12,0);
	cout<<"[错误]"<<a<<endl;
	color(15,0);
}
void warn(string a){
	color(14,0);
	cout<<"[注意]"<<a<<endl;
	color(15,0);
} 
//此内容绝密！！！
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
void command(string c){
	if(c[0]=='/'){
		if(admin){
			
		}
		
		if(c=="/exit"){
			main();
		}
		else if(c=="/help"){
			info("普通用户指令列表");
			info("/exit","退出（重置 用户{登录/注册} 界面）");
			info("/help","显示所有指令");
			
			color(14,0);
			cout<<"管理员指令列表（包括上面的部分）"<<endl;
			color(15,0);
		}
		else{
			error("未知的指令，输入/help查看详情");
		}
		system("pause");
	}
}
void r(){//注册 
	c2:
	char username[20]="";
	int c=0;
	cout<<"==========================================================\n请输入用户名（输入/exit退出）>>>";
	cin>>username;
	command((string)username);
	//为用户名制作存储路径（检测） 
	//{ 
	char *n11="./users/passwords/";
	char *n22=username;
	char temp11[29];
	strcpy(temp11,n11);
	strcat(temp11,n22);
	char *n33=temp11;
	char *n44=".txt";
	char temp22[33];
	strcpy(temp22,n33);
	strcat(temp22,n44);
	//}最终结果保存在temp22中
	ifstream cf;
	cf.open(temp22);
	if(not(cf.is_open())){
		cf.close();
		if(strlen(username)<=20){
			//检测用户名是否含有不合适的字符
			//{
			for(int i=0;i<strlen(username);i++){ 
				//64个字符 
				if(username[i]=='a'||username[i]=='b'||username[i]=='c'||username[i]=='d'||username[i]=='e'||username[i]=='f'||username[i]=='g'||username[i]=='h'||username[i]=='i'||username[i]=='j'||username[i]=='k'||username[i]=='l'||username[i]=='m'||username[i]=='n'||username[i]=='o'||username[i]=='p'||username[i]=='q'||username[i]=='r'||username[i]=='s'||username[i]=='t'||username[i]=='u'||username[i]=='v'||username[i]=='w'||username[i]=='x'||username[i]=='y'||username[i]=='z'||username[i]=='A'||username[i]=='B'||username[i]=='C'||username[i]=='D'||username[i]=='E'||username[i]=='F'||username[i]=='G'||username[i]=='H'||username[i]=='I'||username[i]=='G'||username[i]=='K'||username[i]=='L'||username[i]=='M'||username[i]=='N'||username[i]=='O'||username[i]=='P'||username[i]=='Q'||username[i]=='R'||username[i]=='S'||username[i]=='T'||username[i]=='U'||username[i]=='V'||username[i]=='W'||username[i]=='X'||username[i]=='Y'||username[i]=='Z'||username[i]=='#'||username[i]=='*'||username[i]=='_'||username[i]=='0'||username[i]=='1'||username[i]=='2'||username[i]=='3'||username[i]=='4'||username[i]=='5'||username[i]=='6'||username[i]=='7'||username[i]=='8'||username[i]=='9'){
					c++;
				}
			}
			//}
			if(c==strlen(username)){
				if(username[0]!='1'&&username[0]!='2'&&username[0]!='3'&&username[0]!='4'&&username[0]!='5'&&username[0]!='6'&&username[0]!='7'&&username[0]!='8'&&username[0]!='9'&&username[0]!='0'){
					if(strlen(username)>3){
						//为输入的用户名制作数据存储路径
						//{
						c3:
						int c2=0;
						char password[30]="";
						cout<<"请输入密  码（输入/exit退出）>>>";
						cin>>password;
						command((string)password);
						if(strlen(password)<=30){
							//检测密码是否含有不合适的字符
							//{
							for(int i=0;i<strlen(password);i++){ 
								//64个字符 
								if(password[i]=='a'||password[i]=='b'||password[i]=='c'||password[i]=='d'||password[i]=='e'||password[i]=='f'||password[i]=='g'||password[i]=='h'||password[i]=='i'||password[i]=='j'||password[i]=='k'||password[i]=='l'||password[i]=='m'||password[i]=='n'||password[i]=='o'||password[i]=='p'||password[i]=='q'||password[i]=='r'||password[i]=='s'||password[i]=='t'||password[i]=='u'||password[i]=='v'||password[i]=='w'||password[i]=='x'||password[i]=='y'||password[i]=='z'||password[i]=='A'||password[i]=='B'||password[i]=='C'||password[i]=='D'||password[i]=='E'||password[i]=='F'||password[i]=='G'||password[i]=='H'||password[i]=='I'||password[i]=='G'||password[i]=='K'||password[i]=='L'||password[i]=='M'||password[i]=='N'||password[i]=='O'||password[i]=='P'||password[i]=='Q'||password[i]=='R'||password[i]=='S'||password[i]=='T'||password[i]=='U'||password[i]=='V'||password[i]=='W'||password[i]=='X'||password[i]=='Y'||password[i]=='Z'||password[i]=='#'||password[i]=='*'||password[i]=='_'||password[i]=='0'||password[i]=='1'||password[i]=='2'||password[i]=='3'||password[i]=='4'||password[i]=='5'||password[i]=='6'||password[i]=='7'||password[i]=='8'||password[i]=='9'){
									c2++;
								}
							}
							//}
							if(c2==strlen(password)){
								if(strlen(password)>=5){
									char repassword[30]="";
									cout<<"请确认密  码（输入/exit退出）>>>"; 
									cin>>repassword;
									command((string)repassword);
									if((string)repassword==(string)password){
										//为用户名制作存储路径
										//{ 
										char *n1="./users/passwords/";
										char *n2=username;
										char temp1[29];
										strcpy(temp1,n1);
										strcat(temp1,n2);
										char *n3=temp1;
										char *n4=".txt";
										char temp2[33];
										strcpy(temp2,n3);
										strcat(temp2,n4);
										//}最终结果保存在temp2中
										
										//制作用户信息 
										//{ 
										char *n111="./users/data/";
										char *n222=username;
										char temp111[29];
										strcpy(temp111,n111);
										strcat(temp111,n222);
										char *n333=temp111;
										char *n444=".dat";
										char temp222[33];
										strcpy(temp222,n333);
										strcat(temp222,n444);
										//}
										 
										ofstream f;
										f.open(temp222,ios::binary);
										if(f.is_open()){
											f.write((const char*)&userdata,sizeof(userdata));
											f.close();
										}										
										//储存注册数据 
										//{
										ofstream f1;
										f1.open(temp2);
										if(f1.is_open()){
											f1<<make_password(password)<<endl;
											f1.close();
											system("cls"); 
											info("注册成功！");
											color(10,0);
											cout<<"[信息]你的用户名为——>"<<username<<endl<<"[信息]你的密  码为——>"<<password<<endl;
											color(15,0);
											warn("请记住你的用户名和密码，账号一旦丢失，请自己解决！");
											system("pause");//暂停 
											
										}
										f.close();
										//}
										
									}
									else{
										error("两次输入的密码不一致！");
										goto c3;
									}
								}
								else{
									error("密码不能小于五个字符！");
									goto c3;
								}
							}
							else{
								error("密码存在不合适的字符！");
								info("所有合适的字符为（64个字符）：");
								info("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789_#*");
								goto c3;
							}
						}
						else{
							error("密码不能超过30个字符");
							goto c3; 
						}
					}
					else{
						error("用户名不能少于3个字符");
						goto c2;
					}
				}
				else{
					error("用户名不能以数字开头！");
					goto c2;
				}
			}
			else{
				error("用户名存在不合适的字符！");
				info("所有合适的字符为（64个字符）：");
				info("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789_#*");
				goto c2;
			}
		}
		else{
			cout<<"[错误]用户名不能超过20个字符！"<<endl;
			goto c2;
		}
	}
	else{
		cf.close();
		error("用户名已存在！");
		goto c2;
	}
}
void l(){//登录 
	c1:
	char username[20]="";
	char password[30]="";
	cout<<"==========================================================\n请输入用户名（输入/exit退出）>>>";
	cin>>username;
	command((string)username);
	cout<<"请输入密  码（输入/exit退出）>>>";
	cin>>password;
	command((string)password);
	//为用户名制作存储路径（检测） 
	//{ 
	char *n11="./users/passwords/";
	char *n22=username;
	char temp11[29];
	strcpy(temp11,n11);
	strcat(temp11,n22);
	char *n33=temp11;
	char *n44=".txt";
	char temp22[33];
	strcpy(temp22,n33);
	strcat(temp22,n44);
	//}最终结果保存在temp22中

	ifstream f1;
	f1.open(temp22);
	if(f1.is_open()){
		string p;
		getline(f1,p);//从f1中获取数据（密码）
		if(password==de_password(p)){//检测密码是否正确
			//制作用户信息 
			//{ 
			char *n111="./users/data/";
			char *n222=username;
			char temp111[29];
			strcpy(temp111,n111);
			strcat(temp111,n222);
			char *n333=temp111;
			char *n444=".dat";
			char temp222[33];
			strcpy(temp222,n333);
			strcat(temp222,n444);
			//}
			
			//储存用户数据
			//{
			struct userdata{
				bool is_admin;
			}userdata;
			//} 
			ifstream f;
			f.open(temp222,ios::binary);
			if(f.is_open()){
				f.read((char*)&userdata,sizeof(userdata));
				f.close();
				admin=userdata.is_admin;
			}
			
			system("cls");
			info("登陆成功！");
			f1.close();
			cout<<"欢迎回来"<<username<<endl;
			system("pause");//暂停
		}
		else{
			goto e;
			f1.close();
		}
	}
	else{
		e:
		error("用户名不存在或密码错误！");
		goto c1;
		f1.close();
	}
}
void creatfile(string path){//获创建文件夹 
	mkdir(path.c_str());
}
string creat_agreement;
void start(){
	ifstream fa("./set_admin.txt");
	if(fa.is_open()){
		string fadmin;
		getline(fa,fadmin);
		if(fadmin=="bool admin=1;"||fadmin=="bool admin=true;"||fadmin=="bool damin=True;"||fadmin=="bool admin = 1;"||fadmin=="bool admin = true;"||fadmin=="bool damin = True;"){
			admin=1;
			fa.close();
			remove("./set_admin.txt");
		}
	}
	
	system("cls");
	color(15,0);
	system("title LightEric莱特    [v1.1.0]    版权归Light_LE所有");
	
	ifstream f("./data.dat",ios::binary);//检测文件是否存在 
	if(not(f.is_open())){
		f.close();
		c:
		system("cls");
		string creat_agreement;
		warn("运行此程序需要在当前LightEric.exe目录下创建存档文件，请将它移动到合适的位置，然后选择是否同意");
		info("是否同意该程序在当前目录下创建存档文件（同意请输入1，不同意请输入0）");
		cout<<">>>"; 
		cin>>creat_agreement;
		if(creat_agreement=="1"){
			//写入数据
			//{
			maindata={1};
			ofstream f("./data.dat",ios::binary);
			if(f.is_open()){
				f.write((const char*)&maindata,sizeof(maindata));
				f.close();
				main();
			}
			//} 
		}
		else if(creat_agreement=="0"){
		//空 
		}
		else{
		error("输入错误，请重新输入！");
		system("pause");
		goto c;
		}
	}
	else{
		//开始
	 
		//创建初始文件夹 
		//{
		creatfile("./users"); 
		creatfile("./users/passwords");
		creatfile("./users/data");
		//}
		f.read((char*)&maindata,sizeof(maindata));
		if(maindata.creat_agreement){
			f.close();
			c1:
			system("cls");
			color(15,0);
			string choice;
			cout<<"                          选择"<<endl;
			cout<<"                   {1}登录"<<endl;
			cout<<"                   {2}注册"<<endl;
			cout<<"备注：我们会对你输入的密码进行加密，请放心输入"<<endl; 
			cout<<"__________________________________________________________"<<endl;
			cout<<"请输入你的选择{1或2}或指令（输入/help查看详情）>>>";
			cin>>choice;
			if(choice=="1"){ 
				l();
			}
			else if(choice=="2"){
				r();
			}
			else if(choice[0]=='/'){
				command(choice);
				goto c1;
			}
			else{
				error("输入错误，请重新输入！");
				system("pause"); 
				goto c1;
			}
		}
		else{
			f.close();
			goto c;
		}
	}
}
void run(){
	
}
int main() {
	start();
	run();
	return 0;
}
