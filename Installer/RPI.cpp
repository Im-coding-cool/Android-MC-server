/*#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cctype>
using namespace std;
*/
//中文语言包
#include "../language/Chinese.cpp"
//英文语言包
//#include "language/English.cpp"

void RPI()
{
	int an;						// 该变量用于判断命令是否执行成功
	system("clear");
	Installation_Tips(1);
	an = system
		("sed -i 's@^\\(deb.*stable main\\)$@#\\1\\ndeb https://mirrors.tuna.tsinghua.edu.cn/termux/termux-packages-24 stable main@' $PREFIX/etc/apt/sources.list && apt update -y && apt upgrade -y -o Dpkg::Options::=\"--force-confold\" > /dev/null 2>&1");
	if (an == 0)
	{
		Installation_Tips(2);
		an = system("pkg install wget -y> /dev/null 2>&1");
		if (an == 0)
		{
			Installation_Tips(3);
			an = system("wget https://termux.pek3b.qingstor.com/Recovery_package/mcsm/mcsm.tar.gz");
			if (an == 0)
			{
				Installation_Tips(4);
				an = system("tar -zxvf mcsm.tar.gz -C /data/data/com.termux/ --strip-components=3 --transform='s/files/files/' -p");
				if (an == 0){
					Installation_Tips(6);
				}else{
					// 解压失败报错
					Wrong_node(an, 4);
				}
			}
			else
			{
				// 下载失败报错
				Wrong_node(an, 3);
			}
		}
		else
		{
			// 软件安装失败报错
			Wrong_node(an, 2);
		}
	}
	else
	{
		// 软件包更新失败报错
		Wrong_node(an, 1);
	}

}