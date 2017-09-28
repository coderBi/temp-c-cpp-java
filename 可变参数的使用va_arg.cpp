#include <windows.h>
#include <iostream>
using namespace std;

/*
va_arg������
	va_list ��ʵ��һ��void*ָ�룬���ֵ�����ʵ����fast���á�
	��...��ǰ��ı�������д��ݣ�...����ı��������δ���������ջ����va_list args���������������ջ���ġ�
	va_arg(args,int)�Ǵ�ջ��pop��һ��int�����һ��޸�ջ��ָ��args��
	va_end�Ǳ���ģ������ȥ��ֵ֮��û�е���va_end�������ܻᵼ��ջ���������ָ����������
note��
	����va_argӦ�ú�ʱ��ֹ���⣬һ��Ĵ�����Կ�����...���βε�ǰ��ָ��һ���������������...�д洢�Ĳ����ĸ�������һ�ַ�ʽ����...�п������һ����������ݣ���������0�������һ��Ԫ�ر������ڱ�λ��
	��printf�����ĺ�������ģʽ�ַ����д���ռλ�����������...�еĴ���Ĳ����ĸ�����ʵ��ռλ�����ж�Ӧ�������ʹﵽ�˿��ƽ�β��Ч����
*/

void func(int argc, ...){
    va_list args;
	//��ʼȡֵ  ���еڶ������������� ... ǰ��Ĳ���
    va_start(args, argc);
	char * str = NULL;
	//ȡ������Ĳ��������ҵ���char*����
    for(int i = 0; i < argc; ++i){
		str = va_arg(args,char*);
		//���¿��Կ���args���ָ��ı䶯
		cout << i << ": " << (int)args  << ": " << str << endl;
	}
	//����ȡֵ
	va_end(args); 

	//�ٴ�ȡֵ
	va_start(args,argc);
	cout << "va again: " << va_arg(args,char*) << endl;
}

int main(){
	func(2,"hello","world","welcome");
	return 0;
}
