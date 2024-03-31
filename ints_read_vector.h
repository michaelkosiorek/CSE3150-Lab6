#ifndef _INTS_READ_H_
#define _INTS_READ_H_

#include <istream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> ints_read_one_line(istream & in_stream);
std::ostream &operator<<(std::ostream &os, const std::vector<int> &input);
std::ostream &operator<<(std::ostream &os, const std::vector<double> &input);

#endif