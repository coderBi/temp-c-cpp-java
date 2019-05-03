#include <iostream>
#include <regex>
using namespace std;


int main(){
	/*-------regex_match的三个重载函数，都是进行整个字符串模式匹配测试的，如果符合某种模式就返回true，可以通过附加参数的重载函数返回匹配的子表达式结果------**/
	//regex_match(string/const char[],regex)，只是返回指定的字符串是否可以匹配某种模式，不返回匹配的表达式和子表达式
	regex r("start.*"); //以start开头的模式
	cout << boolalpha << regex_match("starthelloworld", r) << endl; //true
	cout << regex_match("starrrrrr", r) << endl; //false
	cout << regex_match("rrstart", r) << endl; //false
	cout << regex_match("start", r) << endl; //true

	//regex_match(const char[],cmatch,regex)，将匹配的结果存储在第二个参数中，第二个参数cmatch类型是内部封装了char*数组的类结构
	cmatch cm;
	bool matched = regex_match("start hello world", cm, regex("start(.*)"));
	if(matched){
		//index为0的是全匹配的结果
		for(int i = 0; i < cm.size(); ++i){
			cout << cm[i] << endl;
		}
	}
	//regex_match(string, smatch, regex)和上面的返回cmatch的重载类似，只是这里的每一个返回的结果内部存储的是string而不是char*
	smatch sm;
	//matched = regex_match(string("startwithstart,interesting"), sm, regex("start(.*)")); //报错，没有这个类型的重载，因为"startwithstart,interesting"被理解成了const cahr[]
	//matched = regex_match(string("startwithstart,interesting"), sm, regex("start(.*)")); //这次测试发现在最新的std::regex中设定禁止对一个临时的string进行正则匹配（因为，好比是函数返回的临时字符串，对它进行匹配最好是先自己手动接受了再使用）
	string tomatched = "startwithstart,interesting";
	matched = regex_match(tomatched, sm, regex("start(.*)")); 
	if(matched){
		//index为0的是全匹配的结果
		for(int i = 0; i < sm.size(); ++i){
			cout << sm[i] << endl;
		}
	}

	/*----regex_search(string,smatch,regex)是大家常用的正则匹配，是从开始向后查询一种模式匹，可以根据需求返回多个匹配结果------**/
	string tosearched = "<p>this is a paragraph</p> <a>this ia a link</a>";
	//sm存储的是每一次找到的匹配结果
	while(regex_search(tosearched, sm, regex("<(.+)>(.*)</\\1>"))){
		cout << "found in search:" << endl;
		for(smatch::iterator it = sm.begin(); it != sm.end(); it++){
			cout << (*it) << endl;
		}
		cout << "print found in search over" << endl;
		tosearched = sm.suffix(); //在剩余的字符串中重新搜索
	}

	/*--string = regex_replace(replaced, regex, toreplace)可以在指定的字符串中匹配然后替换为指定的内容，返回替换之后的结果字符串--------------*/
	string toreplaced = "get www.baidu.com \r\n http1.0\r\n";
	string result = regex_replace(toreplaced, regex("(GET|POST)\\s+(\\S+)", regex::icase), "$1$2");
	cout << toreplaced << endl;
	cout << result << endl;
	return 0;
}