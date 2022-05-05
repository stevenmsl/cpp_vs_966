#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <queue>
#include <string>
#include <sstream>
#include <algorithm>
using namespace sol940;
using namespace std;

/*takeaways
  - by replacing the vowels in the word list and queries with a
    generic symbol makes it easier to compare when there are
    vowel errors
    kite -> k*t*
    keto, kito, keti... -> k*t*
  - pay attention to the precedence rules defined
*/

vector<string> Solution::spellCheck(vector<string> &wordList, vector<string> &queries)
{
  auto words = unordered_map<string, string>();
  auto wordsLower = unordered_map<string, string>();
  auto wordsRepVowel = unordered_map<string, string>();
  for (auto w : wordList)
  {
    words[w] = w;
    auto l = Util::toLower(w);
    /* we need to return the first match */
    if (!wordsLower.count(l))
      wordsLower[l] = w;
    auto r = replaceVowels(l);
    if (!wordsRepVowel.count(r))
      wordsRepVowel[r] = w;
  }

  auto result = vector<string>();

  for (auto w : queries)
  {
    /*as is */
    if (words.count(w))
    {
      result.push_back(words[w]);
      continue;
    }
    /* case-insensitive */
    auto l = Util::toLower(w);
    if (wordsLower.count(l))
    {
      result.push_back(wordsLower[l]);
      continue;
    }
    /* the positions of vowels are the same */
    auto r = replaceVowels(l);
    if (wordsRepVowel.count(r))
    {
      result.push_back(wordsRepVowel[r]);
      continue;
    }
    result.push_back("");
  }

  return result;
}

string Solution::replaceVowels(const string &s)
{
  auto result = string("");
  for (auto c : s)
    if (vowels.count(c))
      result.push_back('*');
    else
      result.push_back(c);
  return result;
}
