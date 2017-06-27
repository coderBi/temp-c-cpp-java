//看到数据结构书上一种写法，感觉模糊，这里进行测试

#include <iostream>
using namespace std;

typedef struct TreeNode *PtrToNode;
//typedef struct PtrToNode Tree;  //这里是会报错的，说明数据结构书上的写法有问题  应该是不小心多写了一个struct
typedef PtrToNode Tree;

struct TreeNode
{
	int element;
	Tree left;
	Tree right;
};

int main(){
	Tree head = new struct TreeNode;
	head->element = 0;
	head->left = head->right = NULL;
	return 0;
}