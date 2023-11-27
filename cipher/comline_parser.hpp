#pragma once

#include <string>

#include <boost/program_options.hpp>

namespace po = boost::program_options;

class ComLineParser {
  private:
    po::options_description descr_;
    po::variables_map vm_;

    std::string defInputFilePath = "data/input.txt";
    std::string defOutputFilePath = "data/output.txt";

    std::string input_file_path_;
    std::string output_file_path_;
    std::string password_;
    bool encode_ = false;
    bool decode_ = false;
  public:
    ComLineParser() = delete;
    ComLineParser(int argc, char** argv);

    void verifyInput();
    void operator()();
};