#include <stdexcept>
#include <iostream>
#include <filesystem>
#include <fstream>

#include "comline_parser.hpp"
#include "coder.hpp"

ComLineParser::ComLineParser(int argc, char** argv) {
  descr_.add_options()
    ("help,h", "Help message")
    ("in_file,i",
      po::value< std::string >(&input_file_path_),
      "File with message")
    ("out_file,o",
      po::value< std::string >(&output_file_path_),
      "File for result of running")
    ("encode,e",
      po::bool_switch(&encode_),
      "Encoding mode")
    ("decode,d",
      po::bool_switch(&decode_),
      "Decoding mode")
    ("password,p",
      po::value< std::string >(&password_),
      "Password")
    ;
  
  po::store(po::parse_command_line(argc, argv, descr_), vm_);
  po::notify(vm_);
}

void ComLineParser::verifyInput() {
  // Help message
  if( vm_.count("help") ) {
    std::cout << "./cipher.exec -d/-e -p arg [-i arg -o arg -h]" << std::endl;
    descr_.print(std::cout);
    exit(EXIT_SUCCESS);
  }

  if( vm_.count("in_file") == 0 ) {
    input_file_path_ = defInputFilePath;
  }
  {
    std::ifstream f(input_file_path_, std::ios_base::app);
    f.close();
    if( !std::filesystem::is_regular_file(input_file_path_) ) {
      throw std::runtime_error("Unaccessible input file");
    }
  }

  if( vm_.count("out_file") == 0 ) {
    output_file_path_ = defOutputFilePath;
  }
  {
    std::ifstream f(output_file_path_, std::ios_base::app);
    f.close();
    if( !std::filesystem::is_regular_file(output_file_path_) ) {
      throw std::runtime_error("Unaccessible output file");
    }
  }
  if( encode_ == decode_ ) {
    throw std::runtime_error("Mode input error");
  }
  if( vm_.count("password") == 0 ) {
    throw std::runtime_error("--password is required but missing");
  }

}

void ComLineParser::operator()() {
  Coder coder(input_file_path_, output_file_path_, password_);
  if( encode_ ) {
    coder.encode();
  } else if( decode_ ) {
    coder.decode();
  }
}