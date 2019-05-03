#include <iostream>
#include <regex>
using namespace std;


int main(){
	/*-------regex_match���������غ��������ǽ��������ַ���ģʽƥ����Եģ��������ĳ��ģʽ�ͷ���true������ͨ�����Ӳ��������غ�������ƥ����ӱ��ʽ���------**/
	//regex_match(string/const char[],regex)��ֻ�Ƿ���ָ�����ַ����Ƿ����ƥ��ĳ��ģʽ��������ƥ��ı��ʽ���ӱ��ʽ
	regex r("start.*"); //��start��ͷ��ģʽ
	cout << boolalpha << regex_match("starthelloworld", r) << endl; //true
	cout << regex_match("starrrrrr", r) << endl; //false
	cout << regex_match("rrstart", r) << endl; //false
	cout << regex_match("start", r) << endl; //true

	//regex_match(const char[],cmatch,regex)����ƥ��Ľ���洢�ڵڶ��������У��ڶ�������cmatch�������ڲ���װ��char*�������ṹ
	cmatch cm;
	bool matched = regex_match("start hello world", cm, regex("start(.*)"));
	if(matched){
		//indexΪ0����ȫƥ��Ľ��
		for(int i = 0; i < cm.size(); ++i){
			cout << cm[i] << endl;
		}
	}
	//regex_match(string, smatch, regex)������ķ���cmatch���������ƣ�ֻ�������ÿһ�����صĽ���ڲ��洢����string������char*
	smatch sm;
	//matched = regex_match(string("startwithstart,interesting"), sm, regex("start(.*)")); //����û��������͵����أ���Ϊ"startwithstart,interesting"��������const cahr[]
	//matched = regex_match(string("startwithstart,interesting"), sm, regex("start(.*)")); //��β��Է��������µ�std::regex���趨��ֹ��һ����ʱ��string��������ƥ�䣨��Ϊ���ñ��Ǻ������ص���ʱ�ַ�������������ƥ����������Լ��ֶ���������ʹ�ã�
	string tomatched = "startwithstart,interesting";
	matched = regex_match(tomatched, sm, regex("start(.*)")); 
	if(matched){
		//indexΪ0����ȫƥ��Ľ��
		for(int i = 0; i < sm.size(); ++i){
			cout << sm[i] << endl;
		}
	}

	/*----regex_search(string,smatch,regex)�Ǵ�ҳ��õ�����ƥ�䣬�Ǵӿ�ʼ����ѯһ��ģʽƥ�����Ը������󷵻ض��ƥ����------**/
	string tosearched = "<p>this is a paragraph</p> <a>this ia a link</a>";
	//sm�洢����ÿһ���ҵ���ƥ����
	while(regex_search(tosearched, sm, regex("<(.+)>(.*)</\\1>"))){
		cout << "found in search:" << endl;
		for(smatch::iterator it = sm.begin(); it != sm.end(); it++){
			cout << (*it) << endl;
		}
		cout << "print found in search over" << endl;
		tosearched = sm.suffix(); //��ʣ����ַ�������������
	}

	/*--string = regex_replace(replaced, regex, toreplace)������ָ�����ַ�����ƥ��Ȼ���滻Ϊָ�������ݣ������滻֮��Ľ���ַ���--------------*/
	string toreplaced = "get www.baidu.com \r\n http1.0\r\n";
	string result = regex_replace(toreplaced, regex("(GET|POST)\\s+(\\S+)", regex::icase), "$1$2");
	cout << toreplaced << endl;
	cout << result << endl;
	return 0;
}