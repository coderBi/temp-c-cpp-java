#include <iostream>
#include <cstring> //卧槽memcpy竟然在string.h中
using namespace std;

int main(){
	char s1[10] = {0};
	const char *s2 = "hello";

	memcpy(s1,s2, strlen(s2) + 1);

	cout << s1 << endl;
	return 0;
}