#include <stdio.h>
int main(){
	char str[100];
	printf("��ӭ���٣�");
	while (~scanf("%5s", str, sizeof(str)))
	{
		printf("%s\n", str);
	}
	return 0;
}