//gcc -o main dlMain.c -ldl
// nm -D libplugin.so

#include <stdio.h>
#include <dlfcn.h> //따로 정적링크 필요 -ldl

int main()
{
    void *handle;
    void (*hello_func)();
    printf("main프로그램시작\n");
    getchar();

    handle = dlopen("./libplugin.so",RTLD_LAZY);
    hello_func = dlsym(handle, "hello");
    hello_func(); //플러그인 실행
    dlclose(handle);

    return 0;
}