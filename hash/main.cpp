#include <iostream>
#include <string>

#include <cryptopp/cryptlib.h>
#include <cryptopp/hex.h>
#include <cryptopp/files.h>
#include <cryptopp/sha.h>

using namespace CryptoPP;

int main() {
  SHA256 hash;
  std::string digest;
  std::string file_path = "input_file.txt";
  FileSource f(file_path.c_str(), true, new HashFilter(hash, new HexEncoder(new StringSink(digest))));
  std::cout << digest << std::endl;
  return 0;
}