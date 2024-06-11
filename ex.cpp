#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

multimap<string, string> BD;

string str1;
string instruction;
string info1;
string info2;

void Print(const multimap<string, string>& events);
void Add(multimap<string, string>& events, string info1, string info2);

int main() {
    while(true){
        getline(cin, str1);
        stringstream ss(str1);
        getline(ss, instruction, ' ');
        
        if(instruction == "Add"){
            getline(ss, info1, ' ');
            getline(ss, info2, ' ');
            Add(BD, info1, info2);
        }
    }
return 0;
}


void Add(multimap<string, string>& BD, string info1, string info2){
    BD.insert(make_pair(info1, info2));
}