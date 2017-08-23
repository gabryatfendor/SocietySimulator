#include <utilities.h>

using namespace std;

vector<string> Configuration::loadConfiguration(string filename)
{
  vector<string> cfg;
  ifstream input(filename);
  if (!input.is_open())
  {
    cerr << "could not open " << filename << " for reading.\n";
    exit(1);
  }
  string line;
  while(getline(input, line))
  {
    if(line[0] != '#') //avoid commented lines
    {
      //trim out spaces
      line.erase(remove(line.begin(),line.end(),' '),line.end());
      //to lower
      transform(line.begin(), line.end(), line.begin(), ::tolower);
      cfg.push_back(line);
    }
  }
  return cfg;
}

int Configuration::value_for_key(vector<string> file, string key)
{
  int value = 0;
  vector<string>::iterator it;
  for(it = file.begin();it < file.end();it++)
  {
    string fileKey;
    //check where's =
    string::size_type pos = (*it).find('=');
    //takes what's before =
    if (pos != string::npos)
    {
        fileKey =  (*it).substr(0, pos);
    }
    //trim eventual spaces
    fileKey.erase(remove(fileKey.begin(),fileKey.end(),' '),fileKey.end());
    //if key from file is equal to key inputted
    if(fileKey == key)
    {
      //take the value
      string extracted = (*it).substr((*it).find("=")+1);
      //trim eventual blank spaces
      extracted.erase(remove(extracted.begin(),extracted.end(),' '),extracted.end());
      //convert string to int
      value = stoi(extracted);
    }
  }
  return value;
}
