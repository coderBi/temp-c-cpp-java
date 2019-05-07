#include <iostream>
#include <regex>

using namespace std;


int main(){
	std::regex pattern("((\\w+)://)?[\\w+\\.]*/([^\\?]*)(\\?(.*))?", std::regex::icase); //识别一个url
	std::string tomatched = "https://www.baidu.com/a/b?key=value";

	/*
	对下面问题进行分析：
	------------------
		关键点在于循环里面的那个重新赋值操作tomatched = sm[0]。
		首先，每一个string结构里面，都是内部封存了一个char*指向一个char数组空间，如果对string进行重新赋值，一般是会重新开辟一个char数组进行填充。所以在上面的赋值操作结束之后，实际上tomatch内部存储的字符串指向已经发生了变化。
		正则表达式匹配过程，内部会有一个指针去扫描string内部指向的那个char数组。如果在结果完全取出来之前对这个string进行赋值，那么可能导致正则指针指向的那个内存区成为垃圾区，因为目标字符串内部指向进行了重建。正则扫描在一个过时的垃圾区进行扫描，那么可能出现乱码，数据严重错乱等问题。
	*/
	std::smatch sm; //保存结果
	if(std::regex_match(tomatched, sm, pattern)){
		tomatched = sm[0]; //由于在匹配完全取出之前进行了这个赋值操作，导致后面的结果不可预测
		for(int i = 1; i < sm.size(); i++){
			std::cout << i << ":" << sm[i] << "...";
		}
	}
	return 0;
}