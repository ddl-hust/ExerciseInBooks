#### 如何处理多源文件目录
目录结构：
    /src 存放　max() 最后编译成库
    build/　外部编译
    main.cpp 主函数

几个关键语法：
`aux_source_directory` :找到目录下所有源文件
`add_library`:链接库
`ADD_SUBDIRECTORY(src)`:添加子目录

实际出现的一些问题:
1. `CMake unable to determine linker language with C++`

2. `main.cpp:(.text+0x46): undefined reference to int max<int>(int const&, int const&)'`
    这个问题的解决：最初将max()模板分为头文件.h，.cpp分开写成了两个文件，出现了在链接过程中不知道语言，于是将函数模板的申明，定义写在一起

#### 参考
https://www.ibm.com/developerworks/cn/linux/l-cn-cmake/index.html

https://stackoverflow.com/questions/11801186/cmake-unable-to-determine-linker-language-with-c