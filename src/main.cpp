#include <iostream>
#include <sstream>
#include "./lib/gameLife.h"

int main(int argc,char *argv[]){
  Life::GameLife life = Life::GameLife();
  life.initialize(argc,argv);
  life.generate_life();
}