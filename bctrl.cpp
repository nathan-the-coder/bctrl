#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <stack>
#include <typeinfo>

using namespace std;
int usage();


int main(int argc, char** argv)
{

  stack<string> params;

  if (argc < 2) {
    cout << "bctrl <options> <percent>" << endl;
    cout << "No arguments provided!" << endl;
    cout << "Try './bctrl --help/-h' for more information" << endl;
    exit(1);
  }


  string bfile = "/sys/class/backlight/*/brightness";

  if (strcmp(argv[1], "-s") == 0 || strcmp(argv[1], "--set") == 0) 
  {
    string comm = "sudo echo -n ";
    comm.append(argv[2]);
    comm.append(" | sudo tee "+bfile);
    system(comm.c_str());

  }
  else if (strcmp(argv[1], "--get") == 0)
  {
    string comm = "sudo sh -c 'cat ";
    comm.append(bfile+"'");
    system(comm.c_str());

  }
  else if (strcmp(argv[1], "-h") == 0 ||
      strcmp(argv[1], "--help") == 0)
  {
    usage();
  }
  else
  {
    string opt = argv[1];
    if (opt[0] == '-' &&
        opt[1] == '-' ||
        opt[1] == '-')
    {
      cerr << "bctrl: unknown option -- "
           << "'" 
           << argv[1] << "'" << endl;
      cout << "Try './bctrl --help/-h' for more information" << endl;
      exit(1);
    }
    else
    {
      cerr << "bctrl: invalid option -- "
           << "'" << argv[1] << "'" << endl;
      cout << "Try './bctrl --help/-h' for more information" << endl;
      exit(1);
    }
  }

  return EXIT_SUCCESS;
}

int usage()
{
  cout << "HELP: bctrl <options> <percent>" << endl <<
          " ___________________________________________" << endl <<
          " | -s  | --set  | set the brightness level |" << endl <<
          " | --get        | get the brightness level |" << endl <<
          " | -h  | --help | show this help menu      |" << endl <<
          " |-----------------------------------------|" << endl;
  return 0;
}
