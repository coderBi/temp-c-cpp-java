int main(){
	int i = 0;
	int j = &i;  //出现了一个警告，说是用指针初始化一个int但是没有进行转换(cast)
	int m = (int)&i; //正常

	int *p = 111; //也是一个警告，说是没有经过cast直接用int给指针赋值
	int *p1 = (int*)111;
	return 0;
}