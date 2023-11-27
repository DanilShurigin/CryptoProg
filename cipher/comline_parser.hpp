#pragma once

#include <string>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class ComLineParser {
  private:
    po::options_description descr_;
    po::variables_map vm_;

    std::string input_file_path_;
    std::string output_file_path_;
  public:
    ComLineParser() = delete;
    ComLineParser(int argc, char** argv);

    void verifyInput();
    std::pair< std::string, std::string > get_file_pathes(){
      return std::make_pair(input_file_path_, output_file_path_);
    }
};