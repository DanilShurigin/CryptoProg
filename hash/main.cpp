#include <iostream>
#include <string>
#include <filesystem>

#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>

using namespace CryptoPP;

int main() {
  SHA256 hash;
  std::string digest;
  std::string file_path;

  // Input file path
  std::cout << "Path to file: ";
  std::cin >> file_path;

  if( !std::filesystem::is_regular_file(file_path) ) {
    std::cout << "Unaccessible file" << std::endl;
    exit(EXIT_FAILURE);
  }

  // Processing
  FileSource f(file_path.c_str(), true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));
  std::cout << digest << std::endl;
  return 0;
}