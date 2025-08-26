# LDPC

## code.h

### code类

成员变量
|名称|作用|
|:-:|:-:|
|_code|用于存放序列值|
|_length|序列长度|
|_length_information|信息位长度|
|_rate|码率|

函数

|名称|作用|
|:-:|:-:|
|Code()|默认构造函数|
|Code(int,int)|传入序列长度与信息位的构造函数|
|Code(vector)|传入序列的构造函数|
|showInformation()|逐个打印成员变量|
|operator=(Code)|等号重载，将一个Code赋值给另一个Code|
|operatpr=(vector)|等号重载，将序列值赋给Code|
|code()|取出成员变量_code的函数|
|operator+(vector)|序列值相加|
|operator+(Code)|序列的序列值相加|

---

## channel.h

### channel类

无成员变量，是其他信道的父类

函数
|名称|作用|
|:-:|:-:|
|BPSK(vector)|对输入序列进行BPSK调制（1->-1）|
|hardDecision(vector)|对输入信号进行硬判决|
|transfer(vector)|将输入信号经过信道，纯虚函数|

### AWGN类

加性高斯白噪声信道

成员变量
|名称|作用|
|:-:|:-:|
|_sigma|标准差|

函数
|名称|作用|
|:-:|:-:|
|AWGN()|默认初始构造函数|
|AWGN(double)|初始化sigma的构造函数|
|operator=(AWGN)|默认赋值函数|
|normalRandomGenerate(sigma)|传入方差，生成高斯分布随机数|
|showInformation()|打印成员变量|
|transfer(vector)|传入序列，输出经过信道后序列(只添加噪声，判决和调制根据需求调用前面函数即可)|

---

## H.h

校验矩阵类

成员变量

|名称|作用|
|:-:|:-:|
|_number_of_row|行数|
|_number_of_col|列数|
|_rou|行重量向量|
|_gamma|列重量向量|
|_H|校验矩阵|
|_H_row|行校验矩阵|
|_H_col|列校验矩阵|

函数
|名称|作用|
|:-:|:-:|
|H()|默认构造函数|
|H(int,int)|给出行列数的构造函数|
|H(int,int,vector,vector)|给出行列以及行列重量的构造函数|
|readFile(ifstream)|从文件流中读取校验矩阵|
|showInformation()|打印成员变量|
|readColAndRow(ifstream)|读取文件中行列数据，用于组成readFile函数(私有)|
|readGammaAndRou(ifstream)|读取文件中行列重数据，用于组成readFile函数(私有)|
|readHcol(ifstream)|读取文件中列矩阵，用于组成readFile函数(私有)|
|readHrow(ifstream)|读取文件中行矩阵，用于组成readFile函数(私有)|
