gcc/g++ 链接库的编译与链接
https://blog.csdn.net/surgewong/article/details/39236707

static_lib
dynamic_lib
在widows平台下，静态链接库是.lib文件，动态库文件是.dll文件。
在linux平台下，静态链接库是.a文件，动态链接库是.so文件

gcc/g++的编译参数，这里只介绍 -L 、-l、-include、-I、-shared、-fPIC

      -L ：表示要链接的库所在的目录。-L.  表示要链接的库在当前目录， -L/usr/lib 表示要连接的库在/usr/lib下。目录在/usr/lib时，系统会自动搜索这个目录，可以不用指明。

     -l (L的小写)：表示需要链接库的名称，注意不是库文件名称，比如库文件为 libtest.so，那么库名称为test

     -include ：包含头文件，这个很少用，因为一般情况下在源码中，都有指定头文件。

      -I (i 的大写)：指定头文件的所在的目录，可以使用相对路径。

     -shared ：指定生成动态链接库

     -fPIC：  表示编译为位置独立的代码，不用此选项的话编译后的代码是位置相关的所以动态载入时事通过代码拷贝的方式来满足不同进程的需要，而不能达到真正代码共享的目的。


export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:.