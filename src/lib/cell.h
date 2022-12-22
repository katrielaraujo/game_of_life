#ifndef CELL_H
#define CELL_H

#include <string>
using std::string;
#include <vector>

namespace Life{
  class Cell {
    public:  
      std::vector<std::vector<short>> board;
      short n_rows;
      short n_cols;
  
      Cell(){
        for(int i = 0; i < n_rows; i++)
            for(int j = 0; j < n_cols; j++)
              board[i][j] = 0;
      }
      Cell(short rows, short cols){
        n_rows = rows;
        n_cols = cols;
        for(int i = 0; i < n_rows; i++)
            for(int j = 0; j < n_cols; j++)
              board[i][j] = 0;
      }
      ~Cell();
      Cell(const Cell& c){
        board = c.board;
        n_rows = c.n_rows;
        n_cols = c.n_cols;
      }

      short get_neighbor(Cell, short, short);
      short get_count(Cell, short, short); 
      void show_cell(short);
      void show_row(std::vector<short>);
      void show_board(Cell);
      short check(Cell, short, short);
      void update_cells(Cell);
  }; 
}
#endif