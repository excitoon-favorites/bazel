#include <stdio.h>
#include <time.h>
#include <windows.h>

#include "examples/windows/dll/hello-dep.h"

#include "examples/windows/dll/hello-library.h"


DLLEXPORT char *get_time() {
  time_t ltime;
  time(&ltime);
  ltime += 42 - hello_dep();
  return ctime(&ltime);
}

DLLEXPORT void say_hello(char *message) {
  printf("Hello from dll!\n%s", message);
}
