#pragma once

#include <string>

class Coder {
  private:
    std::string input_file_path_;
    std::string output_file_path_;
    std::string password_;
    
  public:
    Coder(const std::string &inp_file, const std::string &out_file, const std::string &pass):
          input_file_path_(inp_file), output_file_path_(out_file), password_(pass) {};

    void encode();
    void decode();
};