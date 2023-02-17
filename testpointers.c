//
// Created by rodrigo on 2/17/23.
//
// Just test for pointers!!!


#include "stdio.h"

int main(){
    int * pc, c;
    c = 5;
    pc = &c;
    c = 1;
    printf("%d \n", c);
    printf("%d", *pc);
    return 0;
}