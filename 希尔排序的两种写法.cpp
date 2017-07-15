#include <iostream>
using namespace std;

/*
关于希尔排序的几点个人理解：
1，无论是怎么选择 Hn Hn-1 ... H1 只要保证最后一次的步长是1，那么一定可以得到正确的结果，因为最后顶多最后进行一次完全的插入排序
2，步长应该是尽可能的没有明显的关联，最糟糕的步长序列是 1 2 4 .... 这样当降低步长的时候会处理到上一次已经排好了的序偶，造成了浪费
	而且减少了这一次可能有效处理逆序的机会。
*/

/*格式输出数组*/
void PrintArr(int arr[], int length){
	if(length <= 0)
		return;
	for(int i = 0; i < length -1; ++i)
		cout << arr[i] << ' ';
	cout << arr[length-1] << endl;
}

/*按照书上写的格式  这种格式很简洁*/
void ShellSort1(int arr[], int length){
	int tmp;
	for(int increment = length/2; increment > 0; increment >>= 1){
		/*一次向后扫描*/
		for(int i = increment; i < length; ++i){
			tmp = arr[i];
			int j;
			for(j = i; j >= increment && arr[j - increment] > tmp; j -= increment){
				arr[j] = arr[j - increment];
			}
			//找到了前面比他小的元素或者是一直找到了最前面  插入到正确的位置
			arr[j] = tmp;
		}
	}
}

/*个人写的一种更容易理解的方式*/
void ShellSort2(int arr[], int length){
	int tmp;
	for(int increment = length/2; increment > 0; increment >>= 1){
		//这里使用 i < length && i < 2 * increment是取得相当于原来的插入排序中的arr[1]序列
		for(int i = increment; i < length && i < 2 * increment; ++i){
			for(int j = i; j < length; j += increment){
				//以某一个arr[1]开始进行一趟的插入排序
				int z = j;
				int temp = arr[j];
				for(z = j; z >= increment && arr[z-increment] > temp; z -= increment){
					arr[z] = arr[z-increment];
				}
				arr[z] = temp;
			}
		}
	}
}

int main(){
	//测试数组
	int arr1[10] = {2,3,4,324, 662, 123, 4366, 875, 1, 0};
	int arr2[10] = {2,3,4,324, 662, 123, 4366, 875, 1, 0};

	//测试ShellSort1
	ShellSort1(arr1,10);
	PrintArr(arr1,10);
	//测试ShellSort2
	ShellSort2(arr2,10);
	PrintArr(arr2,10);
	return 0;
}