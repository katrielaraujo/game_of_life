#include <string>
#include <vector>
#include <iostream>
#include "cell.h"
#include "gameLife.h"

namespace Life{
  //!<Use modulus to get wrapping effect at board edges
  short get_neighbor(Cell c, short row, short col){
    return c.board[(row + c.n_rows) % c.n_rows][(col + c.n_cols) % c.n_cols];  
  }

  //!<Get the account of neighbors
  short get_count(Cell c, short row, short col){
    short count{0};
    std::vector<short> deltas {-1, 0, 1};
    for (short dc : deltas) {
        for (short dr : deltas) {
            if (dr || dc) {
                count += Life::get_neighbor(c, row + dr, col + dc);
            }
        }
    }
    return count;
  }

  //!<Displays a cell individually
  void show_cell(short cell,char birth, char died) {
    std::cout << (cell ? birth : died);
  }

  //!< Displays an entire line and his start and end tags
  void show_row(std::vector<short> row, char birth, char died){
    std::cout << "[";
    for (int cell : row) 
      show_cell(cell, birth, died);
    std::cout << "]\n";
  }

  //!<Check the state of the cell. Return 1 if her born or survived or 0 if her dead
  short check(Cell c, short row, short col){
    short count = get_count(c, row, col);
    bool birth = !c.board[row][col] && count == 3;
    bool survive = c.board[row][col] && (count == 2 || count == 3);
    return birth || survive;
  }

  //!<update the cells after show they
  void update_cells(Cell c){
    Cell original(c);
    for (int row = 0; row < c.n_rows; row++) {
        for (int col = 0; col < c.n_cols; col++) {
            c.board[row][col] = check(original, row, col);
        }
    }
  }
}