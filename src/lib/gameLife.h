#ifndef GAMELIFE_H
#define GAMELIFE_H

#include <string>
#include "cell.h"

namespace Life {
  class GameLife {
    public:
      Cell cell;
      string _filename;
      char _birth;
      char _died;
      int _maxgen;
      int _fps{2};

      
      void initialize(int argc,char *argv[]);
      void usage();
      void open_file();
  };
} // namespace Life

#endif