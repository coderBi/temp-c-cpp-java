#include <stdio.h>

int check(int x, int y, int z){ //检查这三个数是否可以构成三角形。
	if( x + y > z && x + z > y && y + z > x) //注：由于这里判断之前已经有两个数相同了，在三个数都不为零的情况下，其实只要符合第三个数小于这两个相同的数的 2 倍就是三角形
		return 1;
	return 0;
}

int main(){
	int x, y, z, count = 0;
	int i = 100;
	for(; i <= 999; ++i){
		x = i / 100;
		y = (i % 100) / 10;
		z = i % 10;
		
		if(x == 0 || y == 0 || z == 0){
			continue;
		}
		if((x == y || x == z || y == z) && check(x, y, z)){
			count++;
			printf("%d ",i);
		}
	}
	printf("\ncount: %d", count);
	return 0;
}