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
      }
    }
  }

  if(startCount == 0){        // no start found
    return EXIT_FAILURE;
  } else if(startCount > 1){  // more than 1 start found
    return EXIT_FAILURE;
  }

  // TODO: breadth-first search
  

  // TODO: Write solution image to file
  
}
