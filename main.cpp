#include <iostream> //
#include<stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<termios.h>
using namespace std;
// 布局管理器
#include "Layout_controller/Window_controller.h"

#include "Installer/RPI.cpp" // 恢复包安装程序
#include "Installer/Online.cpp" // 在线安装程序


int main() {
  int finish = 0;
  int hsjs;
  int choice = 1;
  char key;

  hideCursor(); // 隐藏光标

  while (finish == 0) {
    system("clear"); // 清屏

    // 输出菜单
    // text(<x坐标可以使用百分比>,<y坐标可以使用百分比>,<布局方式：o代表百分比自动居中、y代表y坐标使用绝对坐标X坐标使用百分比>,<需要显示的文本>);
    text(50, 1, 'y', "+欢迎使用我的世界手机端开服工具+");
    Select_Control(25, 3, 'y', co(choice, 1), "在线安装");
      Select_Control(25, 4, 'y', co(choice, 2), "下载安装");
      Select_Control(75, 3, 'y', co(choice, 3), "本地安装");
      Select_Control(75, 4, 'y', co(choice, 4), "安装命令行版本");
      Select_Control(20, 7, 'y', co(choice, 5), "取消");
      Select_Control(80, 7, 'y', co(choice, 6), "关于");
      text(50, 90, 'o', "提示：通过w,s按键进行选择");

      // 等待用户输入
      key = getUserInput();

      // 根据用户输入进行相应操作
      switch (key) {
        case 'w':
        if (choice > 1) {
          choice--;
        }
        break;
        case 's':
        if (choice < 6) {
          choice++;
        }
        break;
        case '\n': // 回车键
        system("clear"); // 清屏

        // 执行选中的操作
        switch (choice) {
          case 1:
          // cout << "哎呀我靠，这个功能居然还在开发中...\n";
          Online();
          break;
          case 2:
          RPI();
          break;
          case 3:
          cout << "哎呀我靠，这个功能居然还在开发中...\n";
          break;
          case 4:
          cout << "哎呀我靠，这个功能居然还在开发中...\n";
          break;
          case 5:
          cout << "很高兴认识你，下次再见吧。\n";
          break;
          case 6:
          text(1, 50, 'x', "开源地址：https://github.com/xian-ren/Android-MC-server\n");
          text(1, 1, 's', "布局管理器版本：0.0.1");
          text(1, 2, 's', "安装器版本：0.1.2");
          text(1, 3, 's', "作者寿命：又是无数个夜晚; int 寿命 = ?; ");
          break;
        }

        text(50, 90, 'o', "按任意键继续...");
        cin.ignore(); // 等待用户按下回车键
        finish = 1;
        break;
      }
    }

    showCursor(); // 显示光标
    return 0;



    return 0;
  }
