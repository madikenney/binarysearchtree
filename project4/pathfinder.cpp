#include <cstdlib>
#include <iostream>
#include <string>

#include "lib/Image.hpp"
#include "List.hpp"
#include "Queue.hpp"

// Struct used to store locations of specific pixels in the maze
struct State {
  int row;
  int col;
};

int main(int argc, char *argv[])
{
  // get input/output file names from command line arguments
  if (argc != 3) {
    std::cout << "Usage: pathfinder "
              << "<first_input_filename> <second_output_filename>\n"
              << std::endl;
    return EXIT_FAILURE;
  }

  std::string input_file = argv[1];
  std::string output_file = argv[2];

  // Read input image from file
  Image image = readFromFile(input_file);
  int rows = image.height();
  int cols = image.width();

  // Find start pixel (red)
  State start{-1, 1};
  int startCount = 0;

  for(u_char i=0; i<rows; i++){
    for(u_char j=0; j<cols; j++){
      if(image(i, j) == RED){
        start = {i, j};
        startCount++;
      } else if(image(i, j) != WHITE || image(i,j) != BLACK){
        return EXIT_FAILURE;  // pixel is invalid color
      }
    }
  }

  if(startCount == 0){        // no start found
    return EXIT_FAILURE;
  } else if(startCount > 1){  // more than 1 start found
    return EXIT_FAILURE;
  }

  // TODO: breadth-first search
  Queue<State, List<State>> frontier; // Queue of states to be explored
  std::vector<std::vector<bool>> explored(rows, std::vector<bool>(cols, false));  // 2D vector of bools size rowxcol to keep track of explored states
  
  frontier.enqueue(start);
  explored[start.row][start.col] = true;  // start = visited

  bool found = false;
  State goal;

  while(!frontier.isEmpty()){
    // Get next state
    State curr = frontier.peekFront();
    frontier.dequeue();

    int curr_row = curr.row;
    int curr_col = curr.col;

    // Check for goal state
    // Check border on all sides
    bool isBorder = (curr_row == 0 || curr_row == rows-1) || 
                    (curr_col == 0 || curr_col == cols-1);

    // Check current state's color (open space or start)
    bool correctColor = image(curr_row, curr_col) == WHITE ||
                        image(curr_row, curr_col) == RED;

    if(isBorder && correctColor){
      goal  = curr;
      found = true;
      break;
    }
  }

  // TODO: Write solution image to file
  if(found){
    image(goal.row, goal.col) = GREEN;
    std::cout << "Solution Found!";
  } else {
    std::cout << "No Solution Found...";
  }

  writeToFile(image, output_file);

  return EXIT_SUCCESS;
}
