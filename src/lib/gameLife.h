#ifndef GAMELIFE_H
#define GAMELIFE_H

#include <string>
#include "cell.h"

namespace Life {
  class GameLife {
    public:
      GameLife(){}
      ~GameLife(){}
      GameLife(const GameLife& c);
      Cell cell;
      string _filename;
      char _birth;
      char _died;
      int _maxgen;
      int _fps{2};

      void usage();
      void open_file();
      void initialize(int argc,char **argv);
  };
} // namespace Life

#endif