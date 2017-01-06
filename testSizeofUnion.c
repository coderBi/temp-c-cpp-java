#include <stdio.h>

union MyUion{
    int i;
    float f;
    double d;
    char c;
};

struct MyStruct{
    int i;
    float f;
    double d;

};

int main(){
   union MyUion u;
   u.i = 1;
   u.c = 'a';

   printf("u.c:%c\n",u.c);
   printf("u.i:%d\n",u.i);
   printf("sizeof u:%d\n",sizeof u);
   printf("sizeof MyUion:%d\n",sizeof(union MyUion));
   printf("sizeof MyStruct:%d\n",sizeof(struct MyStruct));
    return 0;
}
