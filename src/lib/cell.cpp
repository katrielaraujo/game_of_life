#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "cell.h"
#include "gameLife.h"

namespace Life{
  //!<Use modulus to get wrapping effect at board edges
  short Cell::get_neighbor(Cell c, short row, short col){
    return c.board[(row + c.n_rows) % c.n_rows][(col + c.n_cols) % c.n_cols];  
  }

  //!<Get the account of neighbors
  short Cell::get_count(Cell c, short row, short col){
    short count{0};
    std::vector<short> deltas {-1, 0, 1};
    for (short dc : deltas) {
        for (short dr : deltas) {
            if (dr || dc) {
                count += get_neighbor(c, row + dr, col + dc);
            }
        }
    }
    return count;
  }

  short Cell::is_alive(){
    short count = 0;
    for(int i = 0; i < n_rows; i++)
      for(int j = 0; j < n_cols; j++)
        if(board[i][j] == 1)
          count++;
    return count;      
  }

  //!<Displays a cell individually
  void Cell::show_cell(short cell,char birth, char died) {
    std::cout << (cell ? birth : died);
  }

  //!< Displays an entire line and his start and end tags
  void Cell::show_row(std::vector<short> row, char birth, char died){
    std::cout << "[";
    for (int cell : row) 
      show_cell(cell, birth, died);
    std::cout << "]\n";
  }
  //!< Displays the gameboard
  void Cell::show_board(Cell c, char birth, char died){
      for (const auto& row : c.board) { show_row(row, birth, died); }
  }

  //!<Check the state of the cell. Return 1 if her born or survived or 0 if her dead
  short Cell::check(Cell c, short row, short col){
    short count = get_count(c, row, col);
    bool birth = !c.board[row][col] && count == 3;
    bool survive = c.board[row][col] && (count == 2 || count == 3);
    return birth || survive;
  }

  //!<update the cells after show they
  void Cell::update_cells(Cell c){
    Cell original(c);
    for (int row = 0; row < c.n_rows; row++) {
        for (int col = 0; col < c.n_cols; col++) {
            c.board[row][col] = check(original, row, col);
        }
    }
  }
  
  //!< Get the string version of an generation to compare stability
  std::string board_to_string(Cell c){
    std::ostringstream oss;
    for(int i{0}; i < c.n_rows; i++)
      for(int j{0}; j < c.n_cols; j++)
        oss << c.board[i][j];
    return oss.str();    
  }
}