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
      string _filename{"./data/cfg2.dat"};
      char _birth;
      char _died;
      int _maxgen;
      int _fps{2};

      void usage();
      void open_file();
      void lack_of_parameters();
      void initialize(int argc,char **argv);
      void generate_life();
      void extinction();
      bool stable(std::string&, std::string&);
  };
} // namespace Life

#endif