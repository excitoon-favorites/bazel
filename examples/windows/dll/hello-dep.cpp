﻿#include "hello-dep-of-dep.h"

#include "hello-dep.h"


int hello_dep()
{
    // cdecl, can only be linked statically
    return -hello_dep_of_dep();
}
