// Copyright 2017 Sam Pickell
#include <boost/regex.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

int main(int argc, char* argv[]) {
  int line_number = 1;
  boost::regex start_up("[0-9]{4}-[0-9]{2}-[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9]"
"{2}:\\s[(]log[.]c[.]166[)]\\sserver\\sstarted\\s");
  boost::regex success("[0-9]{4}-[0-9]{2}-[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9]{2}"
"[.][0-9]{3}:INFO:oejs[.]AbstractConnector:Started\\sSelectChannelConnector@[0-"
"9]{1}[.][0-9]{1}[.][0-9]{1}[.][0-9]{1}:[0-9]{4}");
  boost::posix_time::time_duration diff;
  std::string time_start;
  std::string time_end;
  std::ifstream fin;
  std::ofstream fout;
  std::string s, t;
  std::string input_file = argv[1];
  std::string output_file = input_file;
  output_file.append(".rpt");

  // Open files
  fin.open(input_file.c_str());
  if (fin.fail()) {
      std::cout << "Failed to open file" << std::endl;
      exit(1);
    }
  fout.open(output_file.c_str());
  if (fout.fail()) {
      std::cout << "Failed to open output file" << std::endl;
      exit(1);
    }
  // End opening

  std::getline(fin, s);
  while (!fin.eof()) {
      if (boost::regex_match(t, start_up) && boost::regex_match(s, success)) {
          // success
          fout << line_number << "(" << input_file << "): " << s.substr(0, 19)
               << " Boot Completed" << std::endl;
          // boot time
          time_end = s.substr(0, 19);
          boost::posix_time::ptime start =
            boost::posix_time::time_from_string(time_start);
          boost::posix_time::ptime end =
            boost::posix_time::time_from_string(time_end);
          diff = end - start;
          fout << "Boot Time: " << diff.total_milliseconds() << "ms"
               << std::endl;
          fout << std::endl;
          t = "empty";
        } else if (boost::regex_match(t, start_up) &&
               boost::regex_match(s, start_up)) {
          // failure
          fout << "**** Incomplete boot ****" << std::endl;
          fout << std::endl;
          t = "empty";
        }

        if (boost::regex_match(s, start_up)) {
          fout << "=== Device boot ===" << std::endl;
          fout << line_number << "(" << input_file << "): " << s.substr(0, 19)
               << " Boot Start" << std::endl;
          time_start = s.substr(0, 19);
          t = s;
        }
      std::getline(fin, s);
      line_number++;
    }

  fin.close();
  fout.close();

  return 0;
}
