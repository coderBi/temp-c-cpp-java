#include <iostream>
#include <regex>

using namespace std;

class Test1{
	public:
		int num;
	public:
		Test1(){
			Test1(100);
		}
		Test1(int num){
			this->num = num;
		}	
};
class Test2{
	public:
		int num;
	public:
		Test2(){
			new (this)Test2(100); //��thisָ��Ŀռ�ȥ����������󣬻��this���и���(this�����ǲ����޸ĵ�û�а취this = new֮��Ĳ���)
		}
		Test2(int num){
			this->num = num;
		}	
};

int main(){
	Test1 t1;
	cout << t1.num << endl; //����ֵ����Ϊ�ڹ��캯����ʹ�õ��Ǹ�Test1(100)��ʵ�Ǵ�����һ����ʱ����
	Test2 t2;
	cout << t2.num << endl; //100����Ϊ�ڲ�ʹ�õ�new��������thisָ��Ŀռ���п��ٵ�(��ôʹ��ǰ�����Լ���Ϊ�Ǻ����)
	return 0;
}