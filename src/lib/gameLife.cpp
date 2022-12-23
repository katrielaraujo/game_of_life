#include <cstdlib>
#include <fstream>
#include <iostream>
#include <cctype>
#include "gameLife.h"

using std::cout;

//<cfg_file>, --help, --maxgen e --fps

namespace Life{
  void GameLife::lack_of_parameters(){
    std::cout << "Ausência de parametros use sudoku --help para mais informações\n";
    exit(EXIT_FAILURE);
  }
  void GameLife::usage(){
    cout << "Usage: glife [options] input_cfg_file\n";
    cout << "Running options:\n";
    cout << "  --help Print this help text.\n";
    cout << "  --maxgen <num> Maximum number of generations to simulate. No default.\n";
    cout << "  --fps <num> # of generations presented p/ second. Default = 2 fps.\n";
    exit(EXIT_SUCCESS);
  }

  void GameLife::open_file(){
    string line;
    std::ifstream FileData(_filename);
    std::vector<string> lineTeste;
    if(FileData.is_open()){
      FileData >> cell.n_rows >> cell.n_cols >> _birth;
      while(not FileData.eof()){
        std::getline(FileData,line);
        lineTeste.push_back(line);
      }
      for(auto l:lineTeste)
        std::cout << l << '\n';
      FileData.close();
    }else{
      std::cerr << "Uh oh, "<<_filename<<" could not be opened for reading!\n";
      exit(EXIT_FAILURE);
    }
  }

  void GameLife::initialize(int argc,char **argv){
    if(argc == 1) lack_of_parameters();
    for(short ii{1};ii < argc;++ii){
      string args{argv[ii]};
      if(args == "--maxgen" and (argc >= (ii+2))){
        args = argv[++ii];
        if(isdigit(args[0]))
          _maxgen = atoi(args.c_str());
        else
          lack_of_parameters();
      }//MARGEN
      else if(args == "--maxgen" and (argc < (ii+2)))
        lack_of_parameters();
      else if(args == "--fps" and (argc >= (ii+2))){
        args = argv[++ii];
        if(isdigit(args[0]))
          _fps = atoi(args.c_str());
        else
          lack_of_parameters();
      }else if(args == "--fps" and (argc < (ii+2)))
        lack_of_parameters();
      else if(args == "--help")
        usage();
      else
        _filename = args;
    }
    cout << "Maxgen = " << _maxgen << " fps = " << _fps << " filename = "<<_filename<<"\n";
    open_file();
  }
}