// Ä£ÄâÊµÏÖ strcat
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* Mystrcat(char* dest, const char* arr){
	int i = 0;
	int len = 0;
	len = strlen(dest);
	while (arr[i] != '\0'){
		dest[len + i] = arr[i];
		++i;
	}
	dest[len + i + 1] = '\0';
	return dest;
}


int main(){
	char arr[] = "mydbvhj dgfg";
	char dest[1024] = "This is ";
	Mystrcat(dest, arr);
	printf("%s\n", dest);

	system("pause");
	return 0;

}