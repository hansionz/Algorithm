## Nginx学习笔记

### 一.学习环境

* 系统版本:
    Centos7.0 , X64
* 前期安装:
    yum -y install autoconf pcre pcre-devel automake
    yum -y install wget httpd-tools 
* 一次初始化:
    mkdir app download logs work backup

### 二.Nginx

#### 1.Nginx是什么？
    Nginx是一个开源且高性能、可靠的HTTP中间件、代理服务。

#### 2.为什么选择Nginx?
    
* IO多路复用epoll(IO多路复用:多个描述符的IO操作都能在一个线程内并发交替地顺序完成,复用是指复用同一个线程来同时监听多个fd就绪.多线程多路复用:一个线程epoll，fd就绪后，创建新线程处理请求)
* Nginx是一个轻量级的WEB服务,功能模块少,代码模块化
* CPU亲和:多个worker进程分别绑定在不同的CPU上(CPU亲和:是一种把CPU核心和Nginx工作进程绑定方式,把每个worker进程固定在一个CPU上执行来减少切换CPU的cache miss,获得更好的性能)
* sendfile,0拷贝,文件只通过内核空间传递给Socket
**注:关于epoll(https://blog.csdn.net/hansionz/article/details/86517574)**

#### 3.安装Nginx与基本参数使用

##### a.版本说明
* Mainline version 开发版本
* Stable version 稳定版本
* Legacy 历史版本

##### b.Nginx安装

* 在目录/etc/yum.repos.d中添加一个文件nginx.repo,文件内容如下:
```c
[nginx-stable]
name=nginx stable repo
baseurl=http://nginx.org/packages/centos/$releasever/$basearch/
gpgcheck=1
enabled=1
gpgkey=https://nginx.org/keys/nginx_signing.key
```
* sudo yum install nginx 
* nginx -v 显示版本既安装成功

##### c.基本参数使用

* 安装目录
    - rpm -ql nginx(列出详细安装文件)
    - logrotate.d 
    - modules
    - 等等

* 编译参数
    - nginx -V(列出编译参数)
    - --prefix=/etc/nginx ... :安装目录或路径
    - 带temp的编译参数: Nginx保留的临时性文件
    - --user=nginx --group=nginx : 设定Nginx进程启动的用户和用户组
    - 等等

* Nginx基本配置语法
    - cd /etc/nginx
    - cat nginx.conf(配置文件)
    - cat /etc/nginx/conf.d/*.conf(子配置文件)


