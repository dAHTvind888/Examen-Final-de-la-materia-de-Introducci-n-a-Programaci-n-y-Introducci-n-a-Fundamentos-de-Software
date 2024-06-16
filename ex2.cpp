#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string str1;
string instruction;
string info1;
string info2;

multimap<string, string> BD;

void Find(const multimap<string, string>& events, string info1);
void Del_date_event(multimap<string, string>& events, string info1, string info2);
void Print(const multimap<string, string>& events);
void Add(multimap<string, string>& events, string info1, string info2);
void Del_complete(multimap<string, string>& events, string info1, string info2);

int main() {
    while(true){
        getline(cin, str1);
        stringstream ss(str1);
        getline(ss, instruction, ' ');
        
        if(instruction == "Del"){
            getline(ss, info1, ' ');
            getline(ss, info2, ' ');
            if(info2 == ""){
                Del_complete(BD, info1, info2);
            }
            else{
                Del_date_event(BD, info1, info2);
            }
        }
        else if(instruction == "Print"){
            Print(BD);
        }
        else if(instruction == "Find"){
            getline(ss, info1, ' ');
            Find(BD, info1);
        }
        else if(instruction == "Add"){
            getline(ss, info1, ' ');
            getline(ss, info2, ' ');
            Add(BD, info1, info2);

        }
        
        str1.clear();
        instruction.clear();
        info1.clear();
        info2.clear();
    }
    return 0;
}

void Find(const multimap<string, string>& events, string info1){
    for(const auto& element : events){
        if(element.first == info1){
            cout << element.second << endl;
        }
    }

}
void Del_complete(multimap<string, string>& events, string info1, string info2){
    int j = 0;
    auto range = events.equal_range(info1);
    for(auto i = range.first; i != range.second; ++i){
        if(i -> first == info1){
            events.erase(i);
           j+=1;
        }
    }
    cout << "Deleted " << j << " events" << endl;
}

void Del_date_event(multimap<string, string>& events, string info1, string info2){
    auto range = events.equal_range(info1);
    for(auto i = range.first; i != range.second; ++i){
        if(i -> second == info2){
            events.erase(i);
            cout << "Deleted successfully" << endl;
            return;
        }
    }
    cout << "Event not found" << endl;
}

void Print(const multimap<string, string>& events){
    for(const auto& element : events){
        cout << element.first << " " << element.second << endl; 
    }
}

void Add(multimap<string, string>& events, string info1, string info2){
    for(const auto& element : events){
        if(info1 == element.first && info2 == element.second){
            return;
        }
    }
    events.insert(make_pair(info1, info2));
}