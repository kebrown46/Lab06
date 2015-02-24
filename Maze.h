//Katherine (Katie) Brown and Samuel Wehunt
//https://github.com/kebrown46/Lab06

#if !defined (MAZE_H)
#define MAZE_H

#include "Matrix.h"
using CSC2110::Matrix;
#include "Update.h"
#include "Drawable.h"
#include "StackLinked.h"
#include "Cell.h"
#include <gtkmm.h>

class Maze : public Drawable
{
   private:
      Matrix* maze;
      Update* gui;

      int width;
      int height;

      bool traverse();
      Cell* processBackTrack(StackLinked<Cell>* stack);
      void processSolution(StackLinked<Cell>* stack);
      bool isSolved(Cell* curr_cell, StackLinked<Cell>* stack);

      int WALL;
      int SPACE;
      int TRIED;
      int BACKTRACK;
      int PATH;

   public:
      Maze(Matrix* maze);
      virtual ~Maze();

      bool solve();
      void addListener(Update* gui);

      virtual void draw(Cairo::RefPtr<Cairo::Context> cr, int width, int height);
      virtual void mouseClicked(int x, int y);

};

#endif
