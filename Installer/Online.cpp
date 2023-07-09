/*#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cctype>
using namespace std;
*/
#include <fstream>
#include <sstream>
#include <vector>

//中文语言包
//#include "../language/Chinese.cpp"
//英文语言包
//#include "language/English.cpp"

string sh = "ln -s /opt/node-v20.4.0-linux-arm64/bin/node /bin/ \n"
"ln -s /opt/node-v20.4.0-linux-arm64/bin/npm /bin/ \n"
"cd /opt/mcsmanager/ \n"
"./install-dependency.sh\n"
"rm -f /etc/profile.d/a.sh\n"
"echo \"mcsm\" >> /etc/profile.d/mcsm.sh\n"
"apt update -y\n"
"apt install openjdk-*-jdk -y\n"
"echo \"一切准备就绪您可以愉快的开服啦\"\n"
"mcsm";


string mcsm = "#!/bin/bash\n\necho \"请问是否继续启动？ (y/n)\"\nread choice\n\nif [[ \"$choice\" == \"y\" ]]; then\n    echo \"我们正在为您启动。\"\n    cd /opt/mcsmanager/ && ./start-daemon.sh & ./start-web.sh &\nelif [[ \"$choice\" == \"n\" ]]; then\n    echo \"您现在处于开发者模式。\"\n    \nelse\n    echo \"Invalid choice. Please select either 'y' or 'n'.\"\nfi\n";



int File_Write(string sh, string lu) {
  ofstream file(lu); //创建文件
  if (file.is_open()) {
    // 检查文件是否成功打开
    file << sh << endl; // 向文件写入数据
    file.close(); // 关闭文件
    cout << "\x1B[32m脚本写入成功...\x1B[0m" << endl;
    cout << "\x1B[32m正在写入\x1B[0m" << endl;
  } else {
    cout << "\x1B[31m愣着干嘛？脚本写入失败了，还不赶紧去github通知作者修bug。(dog)\x1B[0m" << endl;
  }
  return 0;
}




void Online() {
  int an; // 该变量用于判断命令是否执行成功
  system("clear");
  Installation_Tips(1); // 更新软件包
  an = system
  ("sed -i 's@^\\(deb.*stable main\\)$@#\\1\\ndeb https://mirrors.tuna.tsinghua.edu.cn/termux/termux-packages-24 stable main@' $PREFIX/etc/apt/sources.list && apt update -y && apt upgrade -y -o Dpkg::Options::=\"--force-confold\" > /dev/null 2>&1");
  if (an == 0) {
    Installation_Tips(2); // 安装软件
    an = system("pkg install wget proot-distro -y > /dev/null 2>&1");
    if (an == 0) {
      Installation_Tips(7); // 安装系统
      an = system("proot-distro install ubuntu > /dev/null 2>&1");
      if (an == 0) {
        Installation_Tips(8); // 安装MCSM
        an = system("wget https://nodejs.org/dist/v20.4.0/node-v20.4.0-linux-arm64.tar.xz && "
          "tar -xf node-v20.4.0-linux-arm64.tar.xz -C $PREFIX/var/lib/proot-distro/installed-rootfs/ubuntu/opt/ && "
          "wget https://github.com/MCSManager/MCSManager/releases/latest/download/mcsmanager_linux_release.tar.gz && "
          "mkdir $PREFIX/var/lib/proot-distro/installed-rootfs/ubuntu/opt/mcsmanager/ && tar -zxf mcsmanager_linux_release.tar.gz -C $PREFIX/var/lib/proot-distro/installed-rootfs/ubuntu/opt/mcsmanager/");
        if (an == 0) {
          Installation_Tips(9); // 进入容器操作
          File_Write(sh, "/data/data/com.termux/files/usr/var/lib/proot-distro/installed-rootfs/ubuntu/etc/profile.d/a.sh");
          an = system("echo \"\n\nproot-distro login ubuntu\" > $PREFIX/etc/termux-login.sh");
          //an = system("echo \"\n\necho \"请问是否继续启动？ (y/n)\"\nread choice\n\nif [[ \"$choice\" == \"y\" ]]; then\n    echo \"我们正在为您启动。\"\n    cd /opt/mcsmanager/ && ./start-daemon.sh & start-web.sh &\nelif [[ \"$choice\" == \"n\" ]]; then\n    echo \"您现在处于开发者模式。\"\n    \nelse\n    echo \"Invalid choice. Please select either 'y' or 'n'.\"\nfi\n\" > $PREFIX/var/lib/proot-distro/installed-rootfs/ubuntu/bin/mcsm && chmod +x $PREFIX/var/lib/proot-distro/installed-rootfs/ubuntu/bin/mcsm");
          File_Write(mcsm,"/data/data/com.termux/files/usr/var/lib/proot-distro/installed-rootfs/ubuntu/bin/mcsm");
          an = system("chmod +x $PREFIX/var/lib/proot-distro/installed-rootfs/ubuntu/bin/mcsm");
          an = system("echo \"\n\nexport NODEJS_HOME=/opt/node-v20.4.0-linux-arm64\nexport PATH=\\$NODEJS_HOME/bin:\\$PATH\" >> $PREFIX/var/lib/proot-distro/installed-rootfs/ubuntu/etc/profile");
          if (an == 0) {
            an = system("proot-distro login ubuntu");
          }else {
            // 环境变量写入错误
            Wrong_node(an, 5);
          }
        }else {
          // MCSM下载失败报错
          Wrong_node(an, 4);
        }
      }
      else
      {
        // 系统安装失败报错
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