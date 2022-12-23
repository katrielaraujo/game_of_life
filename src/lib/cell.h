#ifndef CELL_H
#define CELL_H

#include <string>
using std::string;
#include <vector>

namespace Life{
  class Cell {
    public:  
      std::vector<std::vector<short>> board;
      std::vector<std::string> generations;
      short n_rows;
      short n_cols;
  
      Cell(){}
      Cell(short rows, short cols){
        n_rows = rows;
        n_cols = cols;
        for(int i = 0; i < n_rows; i++){
          for(int j = 0; j < n_cols; j++){
              board[i][j] = 0;
          }
        }      
      }
      ~Cell(){}
      Cell(const Cell& c){
        board = c.board;
        n_rows = c.n_rows;
        n_cols = c.n_cols;
      }

      short get_neighbor(Cell, short, short);        //!< Use modulus to get wrapping effect at board edges
      short get_count(Cell, short, short);           //!< Get the account of neighbors
      short check(Cell, short, short);               //!< Check the state of the cell. Return 1 if her born or survived or 0 if her dead
      short is_alive();                              //!< Get the account of alive cells
      void show_cell(short, char, char);             //!< Displays a cell individually
      void show_row(std::vector<short>, char, char); //!< Displays an entire line and his start and end tags
      void show_board(Cell, char, char);             //!< Displays the gameboard
      void update_cells(Cell);                       //!< Update the cells after show they
      std::string board_to_string(Cell);             //!< Get the string version of an generation to compare stability
  }; 
}
#endif