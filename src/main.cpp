#include <iostream>
#include "gameLife.h"

int main(int argc,char *argv[]){
  Life::GameLife life = Life::GameLife();
  life.initialize(argc,argv);
}