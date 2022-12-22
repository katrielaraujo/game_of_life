#include <iostream>
#include "./lib/gameLife.h"

int main(int argc,char *argv[]){
  Life::GameLife life;
  life.initialize(argc, argv);
}