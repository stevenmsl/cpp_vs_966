#ifndef UTIL_H
#define UTIL_H

#include "node.h"

#include <vector>
#include <string>

using namespace sol940;
using namespace std;

namespace sol940
{
    class Util
    {
    public:
        static string toString(vector<string> input);
        static string toString(vector<int> input);
        static string toString(vector<vector<int>> input);
        static string toString(vector<vector<string>> input);
        static vector<string> split(string input);
        static vector<string> split(string input, char delimiter);
        static string toLower(const string &s);
    };
}

#endif