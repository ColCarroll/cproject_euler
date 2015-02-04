#include <stdio.h>
#include "dbg.h"
#include <dlfcn.h>

typedef int(*lib_function)();

int main(int argc, char *argv[]){
    int rc = 0;
    char *problem = argv[1];
    int problem_length = sizeof(problem);
    char problem_library[problem_length + 3];
    check(argc == 2, "USAGE: ./solver 1");


    rc = sprintf(problem_library, "p%s.so", problem);

    void *lib = dlopen(problem_library, RTLD_NOW);
    check(lib != NULL, "FAILED TO open the library %s: %s", problem_library, dlerror())

    lib_function func = dlsym(lib, "solve");
    check(func != NULL, "DID not find solve function in the library %s: %s",
            problem_library, dlerror());

    rc = func();
    check(rc == 0, "Function solve returned %d", rc);

    rc = dlclose(lib);
    check(rc == 0, "Failed to close %s", problem_library);

    return 0;

error:
    return 1;
}
