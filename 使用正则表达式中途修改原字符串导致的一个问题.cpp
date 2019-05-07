#include <iostream>
#include <regex>

using namespace std;


int main(){
	std::regex pattern("((\\w+)://)?[\\w+\\.]*/([^\\?]*)(\\?(.*))?", std::regex::icase); //ʶ��һ��url
	std::string tomatched = "https://www.baidu.com/a/b?key=value";

	/*
	������������з�����
	------------------
		�ؼ�������ѭ��������Ǹ����¸�ֵ����tomatched = sm[0]��
		���ȣ�ÿһ��string�ṹ���棬�����ڲ������һ��char*ָ��һ��char����ռ䣬�����string�������¸�ֵ��һ���ǻ����¿���һ��char���������䡣����������ĸ�ֵ��������֮��ʵ����tomatch�ڲ��洢���ַ���ָ���Ѿ������˱仯��
		������ʽƥ����̣��ڲ�����һ��ָ��ȥɨ��string�ڲ�ָ����Ǹ�char���顣����ڽ����ȫȡ����֮ǰ�����string���и�ֵ����ô���ܵ�������ָ��ָ����Ǹ��ڴ�����Ϊ����������ΪĿ���ַ����ڲ�ָ��������ؽ�������ɨ����һ����ʱ������������ɨ�裬��ô���ܳ������룬�������ش��ҵ����⡣
	*/
	std::smatch sm; //������
	if(std::regex_match(tomatched, sm, pattern)){
		tomatched = sm[0]; //������ƥ����ȫȡ��֮ǰ�����������ֵ���������º���Ľ������Ԥ��
		for(int i = 1; i < sm.size(); i++){
			std::cout << i << ":" << sm[i] << "...";
		}
	}
	return 0;
}