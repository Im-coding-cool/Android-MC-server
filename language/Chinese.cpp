/*
#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cctype>
using namespace std;
*/


//报错语言包
void Wrong_node(int cuo,int position){
	system("clear");
	cout << "\x1B[31m";
	cout << "什么？安装失败了。\n"
			"错误码：" << cuo << "\n"
			"错误位置编号：" << position << "\n"
			"您可以将该错误码提交到维护人员手中以寻求帮助。\n"
			"维护人员QQ：1703214369" << endl;
	cout << "\x1B[0m";
}


//菜单语言包
void menu(){
	cout << "1.在线安装\n"
		"  优点：跟随官方保持最新版本\n"
		"  缺点：安装速度慢、有几率安装失败\n\n"
		"2.下载恢复包并安装\n"
		"  优点：安装速度快、易安装、出错率小\n"
		"  缺点：版本更新不及时、恢复包会覆盖当前Termux Linux系统\n\n"
		"提示：如果你什么都不懂建议选择第二项。\n"
		"      如果你有解决bug的能力建议选择第一项\n"
		"请选择您的安装方式：";
}

//提示
void prompt(int a){
	if (a == 1){
		cout << "哎呀，走神了~\n" "这个选项似乎还在开发中..." << endl;
	}else if(a == 2){
		cout << "您似乎输入了一个非法选项。\n请重启程序后再试。" << endl;
	}else if(a == 3){
		
	}else if(a == 4){
		
	}else if(a == 5){
		
	}else if(a == 6){
		
	}else{
		cout << "警告：语言包配置错误..." << endl;
	}

	
}


//安装提示
void Installation_Tips(int a){
	if (a == 1){
	  cout << "\x1B[32m";
		cout << "正在更新软件包" << endl;
		cout << "\x1B[0m";
	}else if(a == 2){
	  cout << "\x1B[32m";
		cout << "正在安装所需软件(wget)" << endl;
		cout << "\x1B[0m";
	}else if(a == 3){
	  cout << "\x1B[32m";
		cout << "正在下载恢复包..." << endl;
		cout << "\x1B[0m";
	}else if(a == 4){
	  cout << "\x1B[32m";
		cout << "正在解压并且安装" << endl;
		cout << "\x1B[0m";
	}else if(a == 5){
	  cout << "\x1B[32m";
		cout << "正在为您安装..." << endl;
		cout << "\x1B[0m";
	}else if(a == 6){
	  cout << "\x1B[32m";
		cout << "系统安装成功，请重启软件(划掉软件后台重新打开)" << endl;
		cout << "\x1B[0m";
	}else if(a == 7){
	  cout << "\x1B[32m";
		cout << "正在安装ubuntu" << endl;
		cout << "\x1B[0m";
	}else if(a == 8){
		cout << "\x1B[32m正在安装MCSM管理面板\x1B[0m" << endl;
	}else if(a == 9){
	  cout << "\x1B[32m";
		cout << "正在做启动前的准备工作" << endl;
		cout << "\x1B[0m";
	}else{
	  cout << "\x1B[31m";
		cout << "警告：语言包配置错误..." << endl;
		cout << "\x1B[0m";
	}
}






