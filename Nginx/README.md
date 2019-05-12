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

**关于epoll:https://blog.csdn.net/hansionz/article/details/86517574**

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

#### 4.HTTP 

```c
客户端--->(request)服务器
服务器--->(response)客户端
```
* Request:包括请求行、请求头部、空行、请求数据
* Response:包括状态行、响应头部、空行、响应正文
* 使用`curl -v 域名`可以看到以上信息

**关于HTTP:https://blog.csdn.net/hansionz/article/details/86137260**

#### 5.Nginx日志类型

* error.log:Nginx服务处理HTTP请求错误的状态以及Nginx本身运行出错的状态
* access.log:记录Nginx每次HTTP请求访问的状态
* Nginx基于log_format实现这些日志

#### 6.Nginx变量

* HTTP请求变量: arg_PARAMETR、http_HEADER(请求)、sent_http_HEADER(响应)
* 内置变量:nginx.org官网中有所有变量中的详细说明 remote_addr代表客户端的地址
* 自定义变量:程序员可以自己定义变量

#### 7.Nginx模块学习

1.Nginx官方模块

* nginx -V 可以查看配置参数
-----------| ----------------
编译选项     |     作用
---------| -------------
--with-http_stub_status_module | Nginx的客户端状态
-------- | ------------------------
--with-http_random_index_module | 目录中选择一个随机主页
---------- | ----------
--with-http_sub_module | HTTP内容替换
------- | --------------
http_access_module | 用于IP的访问控制模块

2.第三方模块

## Nginx常见的中间间架构

### 三.静态资源WEB服务
```c
客户---->(REQ:html、jpeg)-- Nginx ----->静态资源存储
```
* 静态资源:服务器直接保存的资源，可以直接返回给客户(HTML、CSS、GIF、TXT等)
* 动态资源:服务器需要客户端的请求参数进行动态计算得到结果返回给客户端

Nginx作为静态WEB服务器的CDN(内容分发网络)场景:传输时延的最小化

场景:假设北京的用户需要请求一份新疆的静态资源,但是由于优化时延，特别
     在北京、湖南、山东等多个地方存有该资源的多份备份，当北京的用户去
     请求时DNS系统根据条件(距离、时间等)从最近的服务器获取资源。
Ngnix静态资源WEB服务配置语法:
```c
Syntax: sendfile on | off
Default: sendfile off
Context:http,server,location,if inlocation
// sendfile:不存在内核到用户的两次拷贝，直接在内核中进行，读取速度快
// with-file-aio:异步文件读取

// 配置项: tcp_nopush 提高网络传输效率(sendfile开启情况),把多个包一起进行发送提高效率
Syntax:tcp_nopush on | push
Default: tcp_nopush off
Context:http,server,location

// 配置项: tcp_nodelay keep_alive连接下，提高网络传输的实时性
Syntax:tcp_nodelay on | push
Default: tcp_nodelay on
Context:http,server,location

// 配置项:压缩传输,减少传输时间,提高带宽利用率，提高传输效率
Syntax:gzip on | push
Default: gzip off
Context:http,server,location, if in location
浏览器(解压)《---------》Nginx(压缩)

// 配置项:压缩比率
Syntax:gzip_comp_level level
Default: gzip_comp_level 1
Context:http,server,location

// 扩展Nginx压缩模块
http_gzip_static_module:预读gzip功能
http_gunzip_module:应用支持gunzip的压缩方式

//配置项:添加Cache-Control、Expires

Syntax:expires [modified] time
       expires epoch | max | off
Default: expires off
Context:http,server,location, if in location
```

### 四.代理服务

### 五.负载均衡调度器SLB

### 六.动态缓存
