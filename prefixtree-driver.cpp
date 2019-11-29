#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

#include "prefixtree.h"

int main()
{
  PrefixTree pt;
  string cmd;

  cin >> cmd;
  while (cmd != "quit")
  {
    if (cmd == "search")
    {
      cin >> cmd;
      if (pt.contains(cmd))
        cout << "Word found" << endl;
      else
        cout << "Word not found" << endl;
    }
    else if (cmd == "add")
    {
      cin >> cmd;
      if (pt.isAllLetters(cmd))
        pt.addWord(cmd);
    }
    else if (cmd == "print")
      cout << pt << endl;
    cin >> cmd;
  }

  return 0;
}
