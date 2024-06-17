#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

void Find(const multimap<string, string>& events, vector<string>& orden, string info1);
void Del_date_event(multimap<string, string>& events, string info1, string info2);
void Print(const multimap<string, string>& events);
void Add(multimap<string, string>& events, string info1, string info2);
void Del_complete(multimap<string, string>& events, string info1);
bool check_date_range(string s);
bool check_double_neg(string s);
void Complete(string& info1, string& info2);