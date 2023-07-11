#include <stdio.h>
#include <dlfcn.h>
#include "add.h"

typedef int (*AddFunction)(int, int);

int main() {
    // 半动态链接方式
    int result1 = 0;
    result1 = add(2, 5);
    printf("半动态链接: %d\n", result1);
    
    // 完全动态链接方式
    void* handle = dlopen("./libadd.so", RTLD_LAZY);
    if (handle == NULL) {
        fprintf(stderr, "无法加载动态链接库: %s\n", dlerror());
        return 1;
    }

    AddFunction add1 = (AddFunction)dlsym(handle , "add");
    if (add1 == NULL) {
        fprintf(stderr, "无法获取函数地址: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    int result2 = add1(3, 5);
    printf("完全动态链接: %d\n", result2);

    dlclose(handle);

    return 0;
}

