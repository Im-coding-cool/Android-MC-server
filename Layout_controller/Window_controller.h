#include <iostream>
#include<stdio.h>
#include<sys/types.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<termios.h>
using namespace std;

#include "Basic_controller.h"

// 文本控件
// text(50,50,'o',"选项1"); [将选项1显示在屏幕中间50%,50%]
// text(50,2,'y',"选项2"); [将选项2显示在50%,第二行]
void text(int x, int y, string s, char of, string texta) {
  //int xx, dpi;
  switch (of) {
    case 'o':
    setCursorPosition(dp(x, size().ws_col) - (sp(texta) / 2), dp(y, size().ws_row));
    texta = s + texta + "\x1B[0m";
    cout << texta;

    break;
    case 'f':
    setCursorPosition(dp(x, size().ws_col), dp(y, size().ws_row));
    texta = s + texta + "\x1B[0m";
    cout << texta;

    break;
    case 's':
    setCursorPosition(x, y);
    texta = s + texta + "\x1B[0m";
    cout << texta;

    break;
    case 'x':
    setCursorPosition(x, dp(y, size().ws_row));
    texta = s + texta + "\x1B[0m";
    cout << texta;

    break;
    case 'y':
    setCursorPosition(dp(x, size().ws_col) - (sp(texta) / 2), y);
    texta = s + texta + "\x1B[0m";
    cout << texta;

    break;


  }

  //return 0;
}


// 选择控件Select Control
// Select_Control(75,5,'y',co(choice,1),"选项6");
//和text控件用法基本相同，但是多了一个是否选中的选项
//选中参数为一，没有选中参数为二
void Select_Control(int x, int y, char of, int display, string texta) {
  string result_a;
  string result_b;
  switch (display) {
    case 1:
    result_a = "\x1B[45m";
    result_b = "\x1B[0m";
    text(x, y, result_a, of, texta);
    break;
    case 0:
    text(x, y, "\x1B[43m", of, texta);
    break;
  }
  //return result;
}

void Window_Color_Adjustment() {
  cout << "\033[44m\033[2J";
  // system("clear");
  // cout << "\x1B[47m";
  // 设置整体背景颜色
  /*for (int i = 1; i <= size().ws_row; i++){
    for (int a = 1; a <= size().ws_col; a++){
      text(a,i,"\x1B[47m",'s'," ");
    }
  }
  string te = "";
  for (int i = 1; i <= size().ws_row * size().ws_col; i++){
    te = te + " ";
  }
  text(1,1,"\x1B[47m",'s',te);
  */

  // 顶部左右两个框
  text(1, 1, "\x1B[30m\x1B[47m", 's', "┌");
  text(size().ws_col, 1, "\x1B[30m\x1B[47m", 's', "┐");
  // 底部两个框
  text(1, size().ws_row, "\x1B[30m\x1B[47m", 's', "└");
  text(size().ws_col, size().ws_row, "\x1B[30m\x1B[47m", 's', "┘");

  // 顶部横线
  for (int a = 2; a <= size().ws_col -1; a++) {
    text(a, 1, "\x1B[30m\x1B[47m", 's', "─");
  }
  // 底部横线
  for (int a = 2; a <= size().ws_col -1; a++) {
    text(a, size().ws_row, "\x1B[30m\x1B[47m", 's', "─");
  }

  // 左边竖线
  for (int i = 2; i <= size().ws_row -1; i++) {
    text(1, i, "\x1B[30m\x1B[47m", 's', "│");
  }

  // 右边竖线
  for (int i = 2; i <= size().ws_row -1; i++) {
    text(size().ws_col, i, "\x1B[30m\x1B[47m", 's', "│");
  }


  // cout << "\x1B[0m";
}