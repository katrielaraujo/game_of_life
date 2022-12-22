#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cctype>
#include "gameLife.h"

using std::cout;

//<cfg_file>, --help, --maxgen e --fps

namespace Life{
  void GameLife::usage(){
    cout << "Usage: glife [options] input_cfg_file\n";
    cout << "Running options:\n";
    cout << "  --help Print this help text.\n";
    cout << "  --maxgen <num> Maximum number of generations to simulate. No default.\n";
    cout << "  --fps <num> # of generations presented p/ second. Default = 2 fps.\n";
  }

  void GameLife::open_file(){
    string line;
    std::ifstream FileData(_filename);
    if(FileData.is_open()){
      FileData >> cell.n_rows >> cell.n_cols >> _birth;
      while(not FileData.eof()){
        for(auto ca: line){
          for(int ii{0}; ii < cell.n_rows;++ii){
            for(int jj{0};(jj < cell.n_cols) or (jj <line.size());++jj)
              cell.board.at(ii).at(jj) = (ca == _birth)? 1 : 0;
          }
          if(ca != _birth) 
            _died = ca;
        }
      }
    }else{
      std::cerr << "Uh oh, "<<_filename<<" could not be opened for reading!\n";
      exit(EXIT_FAILURE);
    }
  }

  void GameLife::initialize(int argc,char *argv[]){
    for(short ii{1};ii < argc;++ii){
      string args{argv[ii]};
      if(args == "--maxgen" and (argc >= (ii+2))){
        args = argv[++ii];
        if(isdigit(args[0]))
          _maxgen = atoi(args.c_str());
        else{
          std::cout << "Ausência de parametros use sudoku --help para mais informações\n";
          exit(EXIT_FAILURE);
        }
      }//MARGEN
      else if(args == "--maxgen" and (argc < (ii+2))){
        std::cout << "Ausência de parametros use sudoku --help para mais informações\n";
          exit(EXIT_FAILURE);
      }else if(args == "--fps" and (argc >= (ii+2))){
        args = argv[++ii];
        if(isdigit(args[0]))
          _fps = atoi(args.c_str());
        else{
          std::cout <<"Ausência de parametros use sudoku --help para mais informações\n";
          exit(EXIT_FAILURE);
        }
      }else if(args == "--fps" and (argc < (ii+2))){
        std::cout <<"Ausência de parametros use sudoku --help para mais informações\n";
        exit(EXIT_FAILURE);
      }else if(args == "--help"){
        //usagen("");
      }else
        _filename = args;
    }
    open_file();
  }
}