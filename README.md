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
curl -s https://raw.githubusercontent.com/xian-ren/Android-MC-server/main/install.sh -o install.sh && chmod +x install.sh && ./install.sh
```

**手动安装**
> 如遇到工具无法自动安装或配置时可以尝试手动安装。

```bash
# 更新软件包
pkg upgrade

# 安装 wget 、proot-distro
pkg install wget proot-distro

# 安装发行版Linux
proot-distro install ubuntu

# 进入ubuntu环境
proot-distro login ubuntu

# 安装java*
apt update
apt install openjdk-*-jdk
```
为了方便操作，我们直接安装MCSM服务器管理面板
```bash
# 下载node.js
wget https://nodejs.org/dist/v20.4.0/node-v20.4.0-linux-arm64.tar.xz
# 解压
tar -xf node-v20.4.0-linux-arm64.tar.xz -C /opt/
# 下载MCSM面板
wget https://github.com/MCSManager/MCSManager/releases/latest/download/mcsmanager_linux_release.tar.gz
# 解压
mkdir /opt/mcsmanager/ && tar -zxf mcsmanager_linux_release.tar.gz -C /opt/mcsmanager/
```
配置环境变量
```bash
vim /etc/profile
```
在最后面添加以下内容
```bash
export NODEJS_HOME=/opt/node-v20.4.0-linux-arm64
export PATH=$NODEJS_HOME/bin:$PATH
```
创建node.js软连接
```bash
ln -s /opt/node-v20.4.0-linux-arm64/bin/node /bin/
ln -s /opt/node-v20.4.0-linux-arm64/bin/npm /bin/
```
配置MCSM初始化
```bash
cd /opt/mcsmanager/
./install-dependency.sh
```
编写启动脚本
```bash
cd /bin
vim mcsm
```
填入以下内容

```bash
#!/bin/bash

echo "请问是否继续启动？ (y/n)"
read choice

if [[ "$choice" == "y" ]]; then
    echo "我们正在为您启动。"
    cd /opt/mcsmanager/ && ./start-daemon.sh & ./start-web.sh &
elif [[ "$choice" == "n" ]]; then
    echo "您现在处于开发者模式。"
    
else
    echo "Invalid choice. Please select either 'y' or 'n'."
fi
```
最后输入`mcsm`即可启动


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
pkg install clang
# 安装git
pkg install git
```
- 克隆仓库
```bash
git clone https://github.com/xian-ren/Android-MC-server.git
cd Android-MC-server
```
- 编译项目
```bash
g++ main.cpp -o main
```
- 运行
  `./main`


## 源代码协议
GNU General Public License v3.0


