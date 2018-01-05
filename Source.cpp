#include <iostream>
#include <fstream>
#include <string>


#include "Hash.h"


int main(int argc, char const *argv[])
{
  ifstream in_file;
  ofstream out_file;
 
  Hash<string> q;
 
  string command;
  string item;

  in_file.open(argv[1]);
  out_file.open(argv[2]);
 
  while (in_file >> command)
  {
    if (command == "clear")
    {
      q.clear();
      out_file << "clear" << endl;
    }
    else if (command == "add")
    {
      in_file >> item;
      out_file << "add " << item << endl;
      q.add(item);
      
    }
    else if (command == "print")
    {
      out_file << "print" << endl;
      q.print(out_file);
     
    }
    else if (command == "find")
    {
      in_file >> item;
      out_file << "find " << item << " " << q.find(item) << endl;
    }
    else if (command == "remove")
    {
      in_file >> item;
      out_file << "remove " << item << endl;
      q.remove(item);
   
    }
  }

  in_file.close();
  out_file.close();





 

 
 



  return 0;
}