# 初识

## 环境配置

模拟linux开发环境下，在终端指令执行

- 下载wingw,建议网页跳转，解压就能用；
- notepade  **→**  编码 **→** ansi；
- 支持中文 **→**  设置 **→** 首选项 **→** 新建 **→** 默认语言 **→** 编码选GB2312 ；
- ！不能建文件拖拽到notepad++ 图标**→** 文件配置出问题；
- 先打开notepad++再把文件拖进去再写代码。

## 数据的表现形式

#### scanf

##### 指定字符输入__2.9

```C
	char str[100];
	while (~scanf("%5s", str, sizeof(str)))
	{
		printf("%s\n", str);
	}
```

#####  混合数据输入__2.10

不能含有空格、换行，系统会自动识别

```C
scanf("%d%c%f",&data1,&data2,&data3);
```

### getchar、putchar、puts、gets_17

puts:输出字符串

gets:输入字符串

putchar：输出字符

getchar:输入字符

