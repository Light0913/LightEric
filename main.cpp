#include<bits/stdc++.h>
#include<direct.h>
#include<windows.h>
#include"include_file.h"
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
bool admin=0;//�Ƿ�Ϊ����Ա 
bool command_ran=0;//�����Ƿ�ɹ����� ��ran��run�Ĺ�ȥʽ�� 
unsigned long long money=100;

//�����û�����./users/data/{�û���username}.dat
//{
struct userdata{
	bool is_admin;
	unsigned long long money; 
	
}userdata;
//}
//���������Ϣ./data.dat
//{ 
struct maindata{
	bool creat_agreement;//Э�� 
}maindata;
//}

int main();

void color(int ForgC, int BackC) {
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}
void info(string a){//��ɫ��{0��ɫ}{1��ɫ}{2��ɫ}{3����ɫ}{4��ɫ}{5��ɫ}{6��ɫ}{7��ɫ}{8��ɫ}{9����ɫ}
	color(10,0);//{10����ɫ}{11��ǳ��ɫ}{12����ɫ}{13����ɫ}{14����ɫ}{15����ɫ���༭����ʼ��ɫ��}
	cout<<"[��Ϣ]"<<a<<endl;
	color(15,0);
}
void info(string c,string a){
	color(10,0);
	cout<<"[��Ϣ]"<<c<<"    "<<a<<endl;
	color(15,0);
}
void info(string c,string a,bool is_admin){
	if(is_admin){
		color(14,0);
		cout<<"[��Ϣ]"<<c<<"    "<<a<<endl;
		color(15,0);
	}
}
void error(string a){
	color(12,0);
	cout<<"[����]"<<a<<endl;
	color(15,0);
}
void warn(string a){
	color(14,0);
	cout<<"[ע��]"<<a<<endl;
	color(15,0);
} 
void command(string c){
	if(c[0]=='/'){
		if(admin){
			if(c=="/userdata"){
				command_ran=1;
				info("��ʽ��/userdata <�û���>");
			}
		}
		
		if(c=="/exit"){
			command_ran=1;
			main();
		}
		else if(c=="/help"){
			command_ran=1;
			info("��ͨ�û�ָ���б�");
			info("/exit","�˳������� �û�{��¼/ע��} ���棩");
			info("/help","��ʾ����ָ��");
			
			color(14,0);
			cout<<"[��Ϣ]����Աָ���б���������Ĳ��֣�"<<endl;
			color(15,0);
			info("/userdata","�鿴�û�����",1);
		}
		else{
			command_ran=1;
			error("δ֪��ָ�����/help�鿴����");
		}
		system("pause");
	}
}
void r(){//ע�� 
	c2:
	char username[20]="";
	int c=0;
	cout<<"==========================================================\n�������û���������/exit�˳���>>>";
	cin>>username;
	command((string)username);
	if(not(command_ran)){
		//Ϊ�û��������洢·������⣩ 
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
		//}���ս��������temp22��
		ifstream cf;
		cf.open(temp22);
		if(not(cf.is_open())){
			cf.close();
			if(strlen(username)<=20){
				//����û����Ƿ��в����ʵ��ַ�
				//{
				for(int i=0;i<strlen(username);i++){ 
					//64���ַ� 
					if(username[i]=='a'||username[i]=='b'||username[i]=='c'||username[i]=='d'||username[i]=='e'||username[i]=='f'||username[i]=='g'||username[i]=='h'||username[i]=='i'||username[i]=='j'||username[i]=='k'||username[i]=='l'||username[i]=='m'||username[i]=='n'||username[i]=='o'||username[i]=='p'||username[i]=='q'||username[i]=='r'||username[i]=='s'||username[i]=='t'||username[i]=='u'||username[i]=='v'||username[i]=='w'||username[i]=='x'||username[i]=='y'||username[i]=='z'||username[i]=='A'||username[i]=='B'||username[i]=='C'||username[i]=='D'||username[i]=='E'||username[i]=='F'||username[i]=='G'||username[i]=='H'||username[i]=='I'||username[i]=='G'||username[i]=='K'||username[i]=='L'||username[i]=='M'||username[i]=='N'||username[i]=='O'||username[i]=='P'||username[i]=='Q'||username[i]=='R'||username[i]=='S'||username[i]=='T'||username[i]=='U'||username[i]=='V'||username[i]=='W'||username[i]=='X'||username[i]=='Y'||username[i]=='Z'||username[i]=='#'||username[i]=='*'||username[i]=='_'||username[i]=='0'||username[i]=='1'||username[i]=='2'||username[i]=='3'||username[i]=='4'||username[i]=='5'||username[i]=='6'||username[i]=='7'||username[i]=='8'||username[i]=='9'){
						c++;
					}
				}
				//}
				if(c==strlen(username)){
					if(username[0]!='1'&&username[0]!='2'&&username[0]!='3'&&username[0]!='4'&&username[0]!='5'&&username[0]!='6'&&username[0]!='7'&&username[0]!='8'&&username[0]!='9'&&username[0]!='0'){
						if(strlen(username)>3){
							//Ϊ������û����������ݴ洢·��
							//{
							c3:
							int c2=0;
							char password[30]="";
							cout<<"��������  �루����/exit�˳���>>>";
							cin>>password;
							command((string)password);
							if(not(command_ran)){
								if(strlen(password)<=30){
									//��������Ƿ��в����ʵ��ַ�
									//{
									for(int i=0;i<strlen(password);i++){ 
										//64���ַ� 
										if(password[i]=='a'||password[i]=='b'||password[i]=='c'||password[i]=='d'||password[i]=='e'||password[i]=='f'||password[i]=='g'||password[i]=='h'||password[i]=='i'||password[i]=='j'||password[i]=='k'||password[i]=='l'||password[i]=='m'||password[i]=='n'||password[i]=='o'||password[i]=='p'||password[i]=='q'||password[i]=='r'||password[i]=='s'||password[i]=='t'||password[i]=='u'||password[i]=='v'||password[i]=='w'||password[i]=='x'||password[i]=='y'||password[i]=='z'||password[i]=='A'||password[i]=='B'||password[i]=='C'||password[i]=='D'||password[i]=='E'||password[i]=='F'||password[i]=='G'||password[i]=='H'||password[i]=='I'||password[i]=='G'||password[i]=='K'||password[i]=='L'||password[i]=='M'||password[i]=='N'||password[i]=='O'||password[i]=='P'||password[i]=='Q'||password[i]=='R'||password[i]=='S'||password[i]=='T'||password[i]=='U'||password[i]=='V'||password[i]=='W'||password[i]=='X'||password[i]=='Y'||password[i]=='Z'||password[i]=='#'||password[i]=='*'||password[i]=='_'||password[i]=='0'||password[i]=='1'||password[i]=='2'||password[i]=='3'||password[i]=='4'||password[i]=='5'||password[i]=='6'||password[i]=='7'||password[i]=='8'||password[i]=='9'){
											c2++;
										}
									}
									//}
									if(c2==strlen(password)){
										if(strlen(password)>=5){
											char repassword[30]="";
											cout<<"��ȷ����  �루����/exit�˳���>>>"; 
											cin>>repassword;
											command((string)repassword);
											if(not(command_ran)){
												if((string)repassword==(string)password){
													//Ϊ�û��������洢·��
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
													//}���ս��������temp2��
													
													//�����û���Ϣ 
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
													//�������� 
													//{
													userdata={0,make_money(100)};
													//}
													if(f.is_open()){
														f.write((const char*)&userdata,sizeof(userdata));
														f.close();
													}										
													//����ע������ 
													//{
													ofstream f1;
													f1.open(temp2);
													if(f1.is_open()){
														f1<<make_password(password)<<endl;
														f1.close();
														system("cls"); 
														info("ע��ɹ���");
														color(10,0);
														cout<<"[��Ϣ]����û���Ϊ����>"<<username<<endl<<"[��Ϣ]�����  ��Ϊ����>"<<password<<endl;
														color(15,0);
														warn("���ס����û��������룬�˺�һ����ʧ�����Լ������");
														system("pause");//��ͣ 
														
													}
													f.close();
													//}
													
												}
												else{
													error("������������벻һ�£�");
													goto c3;
												}
											}
											else{
												command_ran=0;
												goto c3;
											}
										}
										else{
											error("���벻��С������ַ���");
											goto c3;
										}
									}
									else{
										error("������ڲ����ʵ��ַ���");
										info("���к��ʵ��ַ�Ϊ��64���ַ�����");
										info("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789_#*");
										goto c3;
									}
								}
								else{
									error("���벻�ܳ���30���ַ�");
									goto c3; 
								}
							}
							else{
								command_ran=0;
								goto c3;
							}
						}
						else{
							error("�û�����������3���ַ�");
							goto c2;
						}
					}
					else{
						error("�û������������ֿ�ͷ��");
						goto c2;
					}
				}
				else{
					error("�û������ڲ����ʵ��ַ���");
					info("���к��ʵ��ַ�Ϊ��64���ַ�����");
					info("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ123456789_#*");
					goto c2;
				}
			}
			else{
				cout<<"[����]�û������ܳ���20���ַ���"<<endl;
				goto c2;
			}
		}
		else{
			cf.close();
			error("�û����Ѵ��ڣ�");
			goto c2;
		}
	}
	else{
		command_ran=0;
		goto c2;
	}
}
void l(){//��¼ 
	c1:
	char username[20]="";
	char password[30]="";
	cout<<"==========================================================\n�������û���������/exit�˳���>>>";
	cin>>username;
	command((string)username);
	if(not(command_ran)){
		cout<<"��������  �루����/exit�˳���>>>";
		cin>>password;
		command((string)password);
		if(not(command_ran)){
			//Ϊ�û��������洢·������⣩ 
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
			//}���ս��������temp22��
		
			ifstream f1;
			f1.open(temp22);
			if(f1.is_open()){
				string p;
				getline(f1,p);//��f1�л�ȡ���ݣ����룩
				if(password==de_password(p)){//��������Ƿ���ȷ
					//�����û���Ϣ 
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
					
					//��ȡ�û�����
					//{
					ifstream f;
					f.open(temp222,ios::binary);
					if(f.is_open()){
						f.read((char*)&userdata,sizeof(userdata));
						f.close();
						//����ȡ�����ݴ�������Ӧ�ı����� 
						admin=userdata.is_admin;
						money=de_money(userdata.money);
					}
					//}
					
					system("cls");
					info("��½�ɹ���");
					f1.close();
					cout<<"��ӭ����"<<username<<endl;
					system("pause");//��ͣ
				}
				else{
					goto e;
					f1.close();
				}
			}
			else{
				e:
				error("�û��������ڻ��������");
				goto c1;
				f1.close();
			}
		}
		else{
			command_ran=0;
			goto c1;
		}
	}
	else{
		command_ran=0;
		goto c1;
	}
}
void creatfile(string path){//�񴴽��ļ��� 
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
	system("title LightEric����    [v1.2.0.36]    ��Ȩ��Light_LE����");
	
	ifstream f("./data.dat",ios::binary);//����ļ��Ƿ���� 
	if(not(f.is_open())){
		f.close();
		c:
		system("cls");
		string creat_agreement;
		warn("���д˳�����Ҫ�ڵ�ǰLightEric.exeĿ¼�´����浵�ļ����뽫���ƶ������ʵ�λ�ã�Ȼ��ѡ���Ƿ�ͬ��");
		info("�Ƿ�ͬ��ó����ڵ�ǰĿ¼�´����浵�ļ���ͬ��������1����ͬ��������0��");
		cout<<">>>"; 
		cin>>creat_agreement;
		if(creat_agreement=="1"){
			//д������
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
		//�� 
		}
		else{
		error("����������������룡");
		system("pause");
		goto c;
		}
	}
	else{
		//��ʼ
	 
		//������ʼ�ļ��� 
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
			cout<<"                          ѡ��"<<endl;
			cout<<"                   {1}��¼"<<endl;
			cout<<"                   {2}ע��"<<endl;
			cout<<"��ע�����ǻ���������������м��ܣ����������"<<endl; 
			cout<<"__________________________________________________________"<<endl;
			cout<<"���������ѡ��{1��2}��ָ�����/help�鿴���飩>>>";
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
				error("����������������룡");
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
	string gc;
	
	cout<<"���������ѡ��:"<<endl;
	cin>>gc;
}
int main() {
	start();
	//run();
	return 0;
}
