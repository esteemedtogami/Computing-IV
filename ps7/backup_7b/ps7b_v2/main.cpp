// Copyright 2017 Sam Pickell
#include <boost/regex.hpp>
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "boost/date_time/gregorian/gregorian.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"

void populate_vectors(std::vector<std::string>& a, std::vector<std::string>& b,
		      std::vector<std::string>& c, std::vector<std::string>& d);
void print_stats(std::vector<std::string>& a, std::vector<std::string>& b,
		 std::vector<std::string>& c, std::vector<std::string>& d,
		 std::ofstream& fout, std::ifstream& fin, std::string name);

int main(int argc, char* argv[]) {
  int line_number = 1;

  // regex
  boost::regex start_up("[0-9]{4}-[0-9]{2}-[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9]"
"{2}:\\s[(]log[.]c[.]166[)]\\sserver\\sstarted\\s");
  boost::regex success("[0-9]{4}-[0-9]{2}-[0-9]{2}\\s[0-9]{2}:[0-9]{2}:[0-9]{2}"
"[.][0-9]{3}:INFO:oejs[.]AbstractConnector:Started\\sSelectChannelConnector@[0-"
"9]{1}[.][0-9]{1}[.][0-9]{1}[.][0-9]{1}:[0-9]{4}");
  boost::regex services("Starting\\sService[.].*");
  boost::regex service_success("Service\\sstarted\\ssuccessfully[.].*");

  // vectors
  std::vector<std::string> service_name;
  std::vector<std::string> service_start;
  std::vector<std::string> service_end;
  std::vector<std::string> service_elapsed_time;
  
  // time
  boost::posix_time::time_duration diff;
  std::string time_start;
  std::string time_end;
  std::string s_total_time;

  std::ifstream fin;
  std::ofstream fout;
  std::string s, t;
  std::string service_1;
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
    
     // start of new stuff

    if (boost::regex_match(t, start_up) && boost::regex_match(s, services))
      {
	std::stringstream out;
	
        for (unsigned int i = 0; i < service_name.size(); i++)
	  {
	    std::string finder = service_name.at(i);
	    std::size_t pos = s.find(finder);
	    if (pos != std::string::npos)
	      {
		service_1 = finder;
		out << line_number;
		service_start.at(i) = out.str();
		break;
	      }
	  }
      }

    if (boost::regex_match(t, start_up) &&
	boost::regex_match(s, service_success))
      {
	std::stringstream out;
	unsigned int i = 0;
	    
            for (i = 0; i < service_name.size(); i++)
	      {
		std::string finder = service_name.at(i);
	        std::size_t pos = s.find(finder);
		//if (service_1 == service_name.at(i))
		if (pos != std::string::npos &&
		    (service_start.at(i) != "Not started"))
		  {
		    out << line_number;
		    service_end.at(i) = out.str();

		    // grab elapsed time
		    std::size_t my_start = 0;
		    std::size_t my_end = 0;
		    std::string ela_time;

		    my_start = s.find("(");
		    if (my_start != std::string::npos)
		      {
			++my_start;
			my_end = s.find(")");
			if (my_end != std::string::npos)
			  {
			    ela_time = s.substr(my_start, my_end - my_start);
			  }
		      }
		    service_elapsed_time.at(i) = ela_time;
		    break;
		  }
	      }
      }
    
     // end of new stuff
     
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

	  // service printout
	  print_stats(service_name, service_start, service_end,
		      service_elapsed_time, fout, fin, input_file);
	  
        } else if (boost::regex_match(t, start_up) &&
               boost::regex_match(s, start_up)) {
          // failure
          fout << "**** Incomplete boot ****" << std::endl;
          fout << std::endl;
          t = "empty";

	  // service printout
	  print_stats(service_name, service_start, service_end,
		      service_elapsed_time, fout, fin, input_file);
        }

        if (boost::regex_match(s, start_up)) {
          fout << "=== Device boot ===" << std::endl;
          fout << line_number << "(" << input_file << "): " << s.substr(0, 19)
               << " Boot Start" << std::endl;
          time_start = s.substr(0, 19);
          t = s;

	  // service startup
	  populate_vectors(service_name, service_start, service_end,
		   service_elapsed_time);
        }
      std::getline(fin, s);
      line_number++;
    }

  fin.close();
  fout.close();

  return 0;
}

void populate_vectors(std::vector<std::string>& a, std::vector<std::string>& b,
		      std::vector<std::string>& c, std::vector<std::string>& d)
{
  a.push_back(" Logging");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" DatabaseInitialize");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" MessagingService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" HealthMonitorService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" Persistence");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" ConfigurationService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" LandingPadService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" PortConfigurationService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" CacheService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" ThemingService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" StagingService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" DeviceIOService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" BellService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" GateService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" ReaderDataService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" BiometricService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" StateManager");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" OfflineSmartviewService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" AVFeedbackService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" DatabaseThreads");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" SoftLoadService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" WATCHDOG");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" ProtocolService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");

  a.push_back(" DiagnosticsService");
  b.push_back("Not started");
  c.push_back("Not completed");
  d.push_back(" ");
}

void print_stats(std::vector<std::string>& a, std::vector<std::string>& b,
		 std::vector<std::string>& c, std::vector<std::string>& d,
		 std::ofstream& fout, std::ifstream& fin, std::string name)
{
  std::vector<std::string> boot_failures;
  unsigned int my_size = a.size();
  
  fout << "Services" << std::endl;

  for(unsigned int i = 0; i < my_size; i++)
    {
      fout << "     " << a.at(i) << std::endl;
      fout << "          Start: " << b.at(i) << "(" << name << ")" << std::endl;
      fout << "          Completed: " << c.at(i)
	   << "(" << name << ")" <<  std::endl;
      if(c.at(i) == "Not completed")
	{
	  boot_failures.push_back(a.at(i));
	}
      fout << "          Elapsed Time: " << d.at(i) << std::endl;
    }
  if (boot_failures.size() > 0)
    {
      fout << "     *** Services not successfully started:";
      for(unsigned int i = 0; i < boot_failures.size(); i++)
	{
	  if(i != (boot_failures.size() - 1))
	    {
	      fout << boot_failures.at(i) << ",";
	    }
	  else
	    {
	      fout << boot_failures.at(i) << std::endl;
	    }
	}
    }
  a.clear();
  b.clear();
  c.clear();
  d.clear();
}
