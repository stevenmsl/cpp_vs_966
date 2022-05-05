#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol940;

/*
Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]
*/
tuple<vector<string>, vector<string>, vector<string>>
testFixture1()
{
  auto wordList = vector<string>{"KiTe", "kite", "hare", "Hare"};
  auto queries = vector<string>{"kite", "Kite", "KiTe", "Hare",
                                "HARE", "Hear", "hear", "keti", "keet", "keto"};
  auto output = vector<string>{"kite", "KiTe", "KiTe", "Hare", "hare", "", "", "KiTe", "", "KiTe"};

  return make_tuple(wordList, queries, output);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see " << Util::toString(get<2>(f))
       << ": " << Util::toString(sol.spellCheck(get<0>(f), get<1>(f))) << endl;
}

void testLower()
{
  cout << "Expect to see yellow: " << Util::toLower("YEllow") << endl;
}

main()
{
  test1();
  testLower();
  return 0;
}