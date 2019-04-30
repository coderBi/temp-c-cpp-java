#include <iostream>
#include <winsock2.h>
using namespace std;

#pragma comment(lib,"ws2_32.lib")

void showHostInfo(struct hostent * hostentry){
	//主机名
	cout << "the host name is :" << hostentry->h_name << endl; 
	//别名序列，内部返回的结构中h_aliases指向的一个char*数组最后一个元素是null(也就是说它至少存在一个元素，下面的对其是否为空的判断也可以省略)
	cout << "the alias found : " << endl;
	for(char** alias = hostentry->h_aliases; alias && *alias; alias++){
		cout << *alias << endl;
	}
	//ip地址类型，目前一般为ipv4
	cout << "the address type is : ";
	if(AF_INET == hostentry->h_addrtype){
		cout << "ipv4" << endl;
	}else if(AF_INET6 == hostentry->h_addrtype){
		cout << "ipv6" << endl;
	}else{
		cout << "other address type" << endl;
	}
	//ip地址的长度，ipv4对应的是4个字节，ipv6为16
	cout << "the length of ip is : " << hostentry->h_length << endl;
	//ip地址列表,每一个ip之所以使用char*表示，因为不同的协议可能存储格式不同，为了向后兼容,ipv4对应的是一个4字节存储空间（字节顺序是反序的，第一个字节对应的是ip的最低位），也就是如果是ipv4，这里通过每一个char*访问得到的是一个4字节的字符串，存储的内容是大头朝下的ip内存表示
	cout << "the ip is : " << endl;
	struct in_addr *tmp = nullptr;
	for(char ** ip = hostentry->h_addr_list; ip && *ip; ip++){
		tmp = (struct in_addr*)*ip;//in_addr是一个结构体，里面只有一个int存放ipv4对应的int，这个值为*(unsigned int*)(*ip) 
		cout << inet_ntoa(*tmp) << endl; //将二进制（整型）的ip转化为用.分割的常见的ip格式
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
	//主机名
	cout << "the host name is :" << hostentry->h_name << endl; 
	//别名序列，内部返回的结构中h_aliases指向的一个char*数组最后一个元素是null(也就是说它至少存在一个元素，下面的对其是否为空的判断也可以省略)
	cout << "the alias found : " << endl;
	for(char** alias = hostentry->h_aliases; alias && *alias; alias++){
		cout << *alias << endl;
	}
	//ip地址类型，目前一般为ipv4
	cout << "the address type is : ";
	if(AF_INET == hostentry->h_addrtype){
		cout << "ipv4" << endl;
	}else if(AF_INET6 == hostentry->h_addrtype){
		cout << "ipv6" << endl;
	}else{
		cout << "other address type" << endl;
	}
	//ip地址的长度，ipv4对应的是4个字节，ipv6为16
	cout << "the length of ip is : " << hostentry->h_length << endl;
	//ip地址列表,每一个ip之所以使用char*表示，因为不同的协议可能存储格式不同，为了向后兼容,ipv4对应的是一个4字节存储空间（字节顺序是反序的，第一个字节对应的是ip的最低位），也就是如果是ipv4，这里通过每一个char*访问得到的是一个4字节的字符串，存储的内容是大头朝下的ip内存表示
	cout << "the ip is : " << endl;
	struct in_addr *tmp = nullptr;
	for(char ** ip = hostentry->h_addr_list; ip && *ip; ip++){
		tmp = (struct in_addr*)*ip;//in_addr是一个结构体，里面只有一个int存放ipv4对应的int，这个值为*(unsigned int*)(*ip) 
		cout << inet_ntoa(*tmp) << endl; //将二进制（整型）的ip转化为用.分割的常见的ip格式
	}
	
	//类似的，可以使用gethostbyaddr获取到和上面一样的信息
	//struct in_addr ia;
	//ia.s_addr = inet_addr("183.232.231.174"); //通过字符串类型的ip转换为二进制对应的大头朝下的整型
	//cout << ia.s_addr << endl;
	struct hostent * hostentry1 = gethostbyaddr((char*)tmp, 4, AF_INET); //为兼容，传入in_addr*转的char*，ip长度和ip类型
	//上面传入的是百度服务器的ip，使用gethostbyaddr得到的结果是null。对这个结果的解释是，使用ip去查询主机名，这个过程是去查询dns服务器上面的映射文件，和gethostbyname类似，但是一般的dns只是记录了主机-->ip却很少记录ip-->主机。所以gethostbyaddr传入公网ip大部分情况下都是返回null，可以在本地host文件写入ip-->name的映射，这样就可以得到正确的信息了
	if(hostentry1)
		showHostInfo(hostentry1);
	else
		cout << "got no message" << endl;

	//下面使用127.0.0.1 获取localhost主机信息。由于这个ip-->name的映射是默认自带的，所以可以返回正常的信息
	struct in_addr localhost;
	localhost.s_addr = inet_addr("127.0.0.1");
	struct hostent * hostentry2 = gethostbyaddr((char*)&localhost,4,AF_INET);
	//返回本地映射信息
	if(hostentry2)
		showHostInfo(hostentry2);
	else
		cout << "got no message" << endl;
	return 0;
}