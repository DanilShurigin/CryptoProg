#include <iostream>
#include <stdexcept>

#include <cryptopp/cryptlib.h>

#include "comline_parser.hpp"
#include "coder.hpp"

int main(int argc, char** argv) {
  ComLineParser cmp(argc, argv);
  try {
    cmp.verifyInput();
  } catch( std::exception& ex ) {
    std::cerr << ex.what() << std::endl;
    exit(EXIT_FAILURE);
  }

  cmp();

  return 0;
}