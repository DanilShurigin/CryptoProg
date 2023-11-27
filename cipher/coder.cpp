#include <iostream>

#include <cryptopp/cryptlib.h>
#include <cryptopp/rijndael.h>
#include <cryptopp/modes.h>
#include <cryptopp/files.h>
#include <cryptopp/osrng.h>
#include <cryptopp/hex.h>

#include "coder.hpp"

using namespace CryptoPP;

void Coder::encode() {
  try {
    password_ += std::string(AES::DEFAULT_KEYLENGTH - password_.size(), '0');
    CBC_Mode< AES >::Encryption encr;
    SecByteBlock iv(AES::BLOCKSIZE);
    encr.SetKeyWithIV((byte*)password_.c_str(), password_.size(), iv);

    FileSource(input_file_path_.c_str(), true, new StreamTransformationFilter(encr, new FileSink(output_file_path_.c_str())));

  } catch( CryptoPP::Exception& ex ) {
    std::cerr << ex.what() << std::endl;
    exit(EXIT_FAILURE);
  }

}

void Coder::decode() {
 try {
    password_ += std::string(AES::DEFAULT_KEYLENGTH - password_.size(), '0');
    CBC_Mode< AES >::Decryption decr;
    SecByteBlock iv(AES::BLOCKSIZE);
    decr.SetKeyWithIV((byte*)password_.c_str(), password_.size(), iv);

    FileSource(input_file_path_.c_str(), true, new StreamTransformationFilter(decr, new FileSink(output_file_path_.c_str())));

  } catch( CryptoPP::Exception& ex ) {
    std::cerr << ex.what() << std::endl;
    exit(EXIT_FAILURE);
  }

}