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
void text(int x, int y, char of, string texta) {
  //int xx, dpi;
  switch (of) {
    case 'o':
    setCursorPosition(dp(x, size().ws_col) - (sp(texta) / 2), dp(y, size().ws_row));
    cout << texta;

    break;
    case 'f':
    setCursorPosition(dp(x, size().ws_col), dp(y, size().ws_row));
    cout << texta;

    break;
    case 's':
    setCursorPosition(x, y);
    cout << texta;

    break;
    case 'x':
    setCursorPosition(x, dp(y, size().ws_row));
    cout << texta;

    break;
    case 'y':
    setCursorPosition(dp(x, size().ws_col) - (sp(texta) / 2), y);
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
    result_a = "[";
    result_b = "]";
    text(x, y, of, result_a + texta + result_b);
    break;
    case 0:
    text(x, y, of, " " + texta + " ");
    break;
  }
  //return result;
}

