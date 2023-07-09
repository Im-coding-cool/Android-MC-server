# 安卓我的世界(Minecraft)一键开服工具
## 这是什么
这是一个使用Termux一键安装我的世界服务器的工具。

## 工具特性
他可以帮助你在手机中运行 Minecraft 服务端，并且使用了 [MCSM](https://github.com/MCSManager/MCSManager/tree/master) 服务器面板进行管理。

除了MCSM面板以外还提供了一些其他管理方式，如C++控制台管理等。

## 运行要求
工具仅支持安卓Termux软件上运行，其他终端程序暂不支持。如需使用其他终端程序建议尝试手动安装。

安卓版本需在`Android 7.0`以上。
建议运行内存大小不小于3G。

## 安装
### Android Termux
**使用命令一键安装**

```bash
curl -s curl -s https://raw.githubusercontent.com/xian-ren/Android-MC-server/main/install.sh -o install.sh && chmod +x install.sh && ./install.sh
```

**手动安装**
> 如遇到工具无法自动安装或配置时可以尝试手动安装。

```bash
# 安装 wget
pkg install wget
# 安装proot
pkg install proot

# 下载发行版Linux
wegt https://******
```

## 开发环境搭建
- 工具 <br/>
*Termux*<br/>
电脑(可选)<br/>
手(可选)<br/>
脑子(可选)<br/>

**Termux配置**<br/>
- C++开发环境
```bash
# 安装C语言编译器
pkg install gcc
# 安装git
pkg install git
```
- 下载源代码
```bash
git http://xxxxx.com
cd xxxx
```
- 编译项目
```bash
g++ main.cpp -o Installer
```


## 源代码协议
GNU General Public License v3.0


