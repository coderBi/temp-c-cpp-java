#include <iostream>
#include <winsock2.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

void showHostInfo(struct hostent * hostentry){
	//������
	cout << "the host name is :" << hostentry->h_name << endl; 
	//�������У��ڲ����صĽṹ��h_aliasesָ���һ��char*�������һ��Ԫ����null(Ҳ����˵�����ٴ���һ��Ԫ�أ�����Ķ����Ƿ�Ϊ�յ��ж�Ҳ����ʡ��)
	cout << "the alias found : " << endl;
	for(char** alias = hostentry->h_aliases; alias && *alias; alias++){
		cout << *alias << endl;
	}
	//ip��ַ���ͣ�Ŀǰһ��Ϊipv4
	cout << "the address type is : ";
	if(AF_INET == hostentry->h_addrtype){
		cout << "ipv4" << endl;
	}else if(AF_INET6 == hostentry->h_addrtype){
		cout << "ipv6" << endl;
	}else{
		cout << "other address type" << endl;
	}
	//ip��ַ�ĳ��ȣ�ipv4��Ӧ����4���ֽڣ�ipv6Ϊ16
	cout << "the length of ip is : " << hostentry->h_length << endl;
	//ip��ַ�б�,ÿһ��ip֮����ʹ��char*��ʾ����Ϊ��ͬ��Э����ܴ洢��ʽ��ͬ��Ϊ��������,ipv4��Ӧ����һ��4�ֽڴ洢�ռ䣨�ֽ�˳���Ƿ���ģ���һ���ֽڶ�Ӧ����ip�����λ����Ҳ���������ipv4������ͨ��ÿһ��char*���ʵõ�����һ��4�ֽڵ��ַ������洢�������Ǵ�ͷ���µ�ip�ڴ��ʾ
	cout << "the ip is : " << endl;
	struct in_addr *tmp = nullptr;
	for(char ** ip = hostentry->h_addr_list; ip && *ip; ip++){
		tmp = (struct in_addr*)*ip;//in_addr��һ���ṹ�壬����ֻ��һ��int���ipv4��Ӧ��int�����ֵΪ*(unsigned int*)(*ip) 
		cout << inet_ntoa(*tmp) << endl; //�������ƣ����ͣ���ipת��Ϊ��.�ָ�ĳ�����ip��ʽ
	}
}

int main(){
	WSADATA wa;
	int error = WSAStartup(MAKEWORD(2,2),&wa);
	if(error){
		cout << "init winsock fail" << endl;
		exit(-1);
	}
	struct hostent * hostentry = gethostbyname("www.baidu.com");
	if(!hostentry){
		cout << "cannot resolve the hostname gived" << endl;
		exit(-1);
	}
	//������
	cout << "the host name is :" << hostentry->h_name << endl; 
	//�������У��ڲ����صĽṹ��h_aliasesָ���һ��char*�������һ��Ԫ����null(Ҳ����˵�����ٴ���һ��Ԫ�أ�����Ķ����Ƿ�Ϊ�յ��ж�Ҳ����ʡ��)
	cout << "the alias found : " << endl;
	for(char** alias = hostentry->h_aliases; alias && *alias; alias++){
		cout << *alias << endl;
	}
	//ip��ַ���ͣ�Ŀǰһ��Ϊipv4
	cout << "the address type is : ";
	if(AF_INET == hostentry->h_addrtype){
		cout << "ipv4" << endl;
	}else if(AF_INET6 == hostentry->h_addrtype){
		cout << "ipv6" << endl;
	}else{
		cout << "other address type" << endl;
	}
	//ip��ַ�ĳ��ȣ�ipv4��Ӧ����4���ֽڣ�ipv6Ϊ16
	cout << "the length of ip is : " << hostentry->h_length << endl;
	//ip��ַ�б�,ÿһ��ip֮����ʹ��char*��ʾ����Ϊ��ͬ��Э����ܴ洢��ʽ��ͬ��Ϊ��������,ipv4��Ӧ����һ��4�ֽڴ洢�ռ䣨�ֽ�˳���Ƿ���ģ���һ���ֽڶ�Ӧ����ip�����λ����Ҳ���������ipv4������ͨ��ÿһ��char*���ʵõ�����һ��4�ֽڵ��ַ������洢�������Ǵ�ͷ���µ�ip�ڴ��ʾ
	cout << "the ip is : " << endl;
	struct in_addr *tmp = nullptr;
	for(char ** ip = hostentry->h_addr_list; ip && *ip; ip++){
		tmp = (struct in_addr*)*ip;//in_addr��һ���ṹ�壬����ֻ��һ��int���ipv4��Ӧ��int�����ֵΪ*(unsigned int*)(*ip) 
		cout << inet_ntoa(*tmp) << endl; //�������ƣ����ͣ���ipת��Ϊ��.�ָ�ĳ�����ip��ʽ
	}
	
	//���Ƶģ�����ʹ��gethostbyaddr��ȡ��������һ������Ϣ
	//struct in_addr ia;
	//ia.s_addr = inet_addr("183.232.231.174"); //ͨ���ַ������͵�ipת��Ϊ�����ƶ�Ӧ�Ĵ�ͷ���µ�����
	//cout << ia.s_addr << endl;
	struct hostent * hostentry1 = gethostbyaddr((char*)tmp, 4, AF_INET); //Ϊ���ݣ�����in_addr*ת��char*��ip���Ⱥ�ip����
	//���洫����ǰٶȷ�������ip��ʹ��gethostbyaddr�õ��Ľ����null�����������Ľ����ǣ�ʹ��ipȥ��ѯ�����������������ȥ��ѯdns�����������ӳ���ļ�����gethostbyname���ƣ�����һ���dnsֻ�Ǽ�¼������-->ipȴ���ټ�¼ip-->����������gethostbyaddr���빫��ip�󲿷�����¶��Ƿ���null�������ڱ���host�ļ�д��ip-->name��ӳ�䣬�����Ϳ��Եõ���ȷ����Ϣ��
	if(hostentry1)
		showHostInfo(hostentry1);
	else
		cout << "got no message" << endl;

	//����ʹ��127.0.0.1 ��ȡlocalhost������Ϣ���������ip-->name��ӳ����Ĭ���Դ��ģ����Կ��Է�����������Ϣ
	struct in_addr localhost;
	localhost.s_addr = inet_addr("127.0.0.1");
	struct hostent * hostentry2 = gethostbyaddr((char*)&localhost,4,AF_INET);
	//���ر���ӳ����Ϣ
	if(hostentry2)
		showHostInfo(hostentry2);
	else
		cout << "got no message" << endl;
	return 0;
}