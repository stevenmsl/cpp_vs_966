
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <stack>

using namespace std;
namespace sol940
{

  class Solution
  {
  private:
    string replaceVowels(const string &s);
    unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

  public:
    vector<string> spellCheck(vector<string> &wordList, vector<string> &queries);
  };
}
#endif