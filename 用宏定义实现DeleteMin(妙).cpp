#include <iostream>
using namespace std;

typedef struct QueueStruct *PriorityQueue;

struct QueueStruct
{
	int element;
	/*这暂时就用一个next代替其他的指针进行测试*/
	PriorityQueue next;
};

#define DeleteMin(H) ({int elementToReturn = FindMin(H); H = DeleteMin1(H); elementToReturn;})

int FindMin(PriorityQueue h){
	return h->element;
}

PriorityQueue DeleteMin1(PriorityQueue h){
	PriorityQueue next = h->next;
	delete h;
	return next;
}

int main(){
	//建立队列
	PriorityQueue h = new QueueStruct{100,NULL};
	PriorityQueue next = new QueueStruct{101,NULL};
	h->next = next;
	//测试DeleteMin函数
	cout << DeleteMin(h) << endl;;
	//第二次测试
	cout << DeleteMin(h) << endl;
	return 0;
}