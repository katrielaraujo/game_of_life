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
      string _filename{"./data/cfg2.dat"};
      char _birth;
      char _died;
      int _maxgen;
      int _fps{2};

      void usage(); 
      Cell open_file(); //!< Open the file e insert into matrix
      void lack_of_parameters(); 
      void initialize(int argc,char **argv); //!< Receive the commandline and insert dates
      void generate_life(Cell); //!<Control the Game
      void extinction(Cell);    //!<Check if the game are over by extinction
      bool stable(std::string, std::string);//!<Check if the game are over by stability
  };
} // namespace Life

#endif