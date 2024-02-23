# C语言

## 初识

 **环境配置**

模拟linux开发环境下，在终端指令执行

- 下载wingw,建议网页跳转，解压就能用；
- notepade  **→**  编码 **→** ansi；
- 支持中文 **→**  设置 **→** 首选项 **→** 新建 **→** 默认语言 **→** 编码选GB2312 ；
- ！不能建文件拖拽到notepad++ 图标**→** 文件配置出问题；
- 先打开notepad++再把文件拖进去再写代码。

## 数据类型

**scanf**

```C
	char str[100];
	while (~scanf("%5s", str, sizeof(str)))
	{
		printf("%s\n", str);
	}
```

**不能含有空格、换行，系统会自动识别**

```C
scanf("%d%c%f",&data1,&data2,&data3);
```

**getchar、putchar、puts、gets_17**

puts:输出字符串     gets:输入字符串     putchar：输出字符     getchar:输入字符

## 字符串

**字符串定义**

```c
//字符定义
char c =  'a'; 
//定义字符串
char c[]={'d', 'g', 'a', 'b'};//这种方式很蠢
//字符串变量
char arr[] = "adflhsaghb";//这个更常用
//字符串常量，不能修改
char *arr = "hello";//类似创建地址然后指向字符串，只能使用
```

**字符串输出**

```c
printf（“%s”,arr);//%s输出字符串
puts(arr);//自带换行
```

**字符串与整型数组的存贮方式不同**

```c
int data[] = {1, 2, 3, 4, 5};//长度为5
char data[] = {'h', 'e', 'l', 'l', '0'};//长度为5，如果优化器没有优化到位，输出没有检测到’/0‘，可能会出现乱码，所以后面可以加上’/0‘
char data[] = "hello";//长度为6，末尾自动加上’/0‘（字符串的结束标志）
```

**sizeof和strlen的区别**

```c
char data[] = "hello";
printf("sizeof:%d/n",sizeof(data));//6
printf("strlen:%d/n",strlen(data));//5
//如果是这样定义
char cdata[128] = "hello";
printf("sizeof:%d/n",sizeof(cdata));//128
printf("strlen:%d/n",strlen(cdata));//5，计算有效字符的大小
//定义指针指向字符串
char *p = “hello”;
printf("sizeof:%d/n",sizeof(p));//8,这个是地址大小，类似计算char *
printf("strlen:%d/n",strlen(p));//5
```

**开辟动态空间**

**malloc**

原型：malloc(int size);//返回一个指针

**realloc**:扩容

realloc(*prt, int size);//size是在原大小下，新增加的空间大小

**释放内存空间**

free(*ptr)

悬挂指针之后，即free空间后，让prt指向NULL,即加上prt = NULL

**几个常用的api**

**strcpy**:  复制  strcpy(char* dest, const char *src)

//有strncpy：复制前n字符，以下函数同理，都是在判断条件下新加是否大于n或者减到0

```c
char* myStrcpy(char *des, char *src){//复制函数
    if(des ==NULL || src == NULL){
        return NULL;
    }
    char *bak = des;
    while(*src != '\0'){
        *des++ = *src++;//拷贝
        /*等价于 des  = *src;//拷贝
        des++;//偏移
        src++;*/
    }  
    *des = '\0';//加上结束标志
    return bak;//只能返回bak，而不是des
}
```

assert:  增加开销，多了判断

```c
include “assert.h”
assert(des != NULL && src != NULL)
```

strcat:  拼接  strcat(char* dest, const char *src)；//dest需要有足够大的空间

```C
#include <assert.h>
char* myStrcat(char *des, char *src){\
    char *bak = des;
    assert(des ==NULL || src == NULL);
    while(*des != '\0'){//让它到尾巴
        des++;
    }//也可以用for循环来写
    while((*des++ = *src++) != '\0');//赋值
    *des = '\0';//加上结束标志
    return bak;
}
```

strcmp:  比较  strcmp(const char *s1, const char *s2)  //返回值——1：前面大于后面    ； -1：后面大于前面  ；0：字符串一样

```c
//这个不太严谨
int myStrcmp(char *str1, cahr *srr2){
    int ret = 0;
    while(*sre1 && *str2 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    ret = *str1 - *str2;
    if(ret < 0){
        ret = -1;
    }
    if(ret > 0){
        ret =1;
    } 
    return ret;
}
```

```C
int myStrcmp(char *str1, cahr *srr2){
    int ret = 0;
    int n_str1 = 0;
    int n_str2 = 0;
    char *bakStr1 = str1;
    char *bakStr2 = str2;
    while(*sre1 && *str2 && (*str1 == *str2)){
        str1++;
        str2++;
    }
    if(*str1 || *str2){
        str1 = bakStr1;//指针回归
    	str2 = bakStr2;
        while(*str1){//计算字符串的ascii码并求和
        	n_str1 += *str1;
        	str1++;
    	}
     	while(*str2){
        	n_str2 += *str2;
         	str2++;
    	}
    }
    ret = n_str1 - n_str2;
    if(ret < 0){
        ret = -1;
    }
    if(ret > 0){
        ret =1;
    } 
    return ret;
}
```

## 结构体

定义不同数据类型变量

结构体定义、访问

```c
struct Student{
    int num;
    char name[32];
    int age;
};
int main(){
	struct Student stu1;
    struct Student stu2 = {1, "张三"， 3};
    struct Student max;
    //结构体可以直接赋值,但是结构体内变量需要一致
    max = stu2;
	//访问结构体变量
    stu1.num = 1;
    strcmp(stu1.name, "hello");
}
```

### 结构体数组

```c
struct Student{
    int num;
    char name[32];
    int age;
};
int arr1[3] = {1, 2, 3};
struct Student arr2[3] = {{1, "张三"，19},
                          {2, "李四"，20},
                          {3, "王五"，30}};
int len = sizeof(arr2)/sizeof(arr2[0]);//结构数组长度
```

