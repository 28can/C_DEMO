//代码中真正输入的会含有一个换位符如空格或者换行
//这里直接输入abc才会真正输入三个字符
#include <stdio.h>
int main(){
	char data1;
	char data2;
	char data3;
	scanf("%c%c%c",&data1,&data2,&data3);
	printf ("%C,%C,%C",\
			data1,data2,data3);
	return 0;
}