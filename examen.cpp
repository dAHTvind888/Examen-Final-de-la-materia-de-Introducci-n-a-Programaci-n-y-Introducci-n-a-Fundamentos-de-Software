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
string date;
string days;
string years;
string months;
vector<string> orden;
multimap<string, string> events;

void Find(const multimap<string, string>& events, vector<string>& orden, string info1);
void Del_date_event(multimap<string, string>& events, string info1, string info2);
void Print(const multimap<string, string>& events);
void Add(multimap<string, string>& events, string info1, string info2);
void Del_complete(multimap<string, string>& events, string info1, string info2);
void Complete(string& info1);

int main() {
    while(true){
        getline(cin, str1);
        stringstream ss(str1);
        getline(ss, instruction, ' ');
        
        if(instruction == "Del"){
            getline(ss, info1, ' ');
            getline(ss, info2, ' ');
            if(info2 == ""){
                Del_complete(events, info1, info2);
            }
            else{
                Del_date_event(events, info1, info2);
            }
        }
        else if(instruction == "Print"){
            Print(events);
        }
        else if(instruction == "Find"){
            getline(ss, info1, ' ');
            Complete(info1);
            Find(events, orden, date);
        }
        else if(instruction == "Add"){
            getline(ss, info1, ' ');
            getline(ss, info2, ' ');
            Complete(info1);
            Add(events, date, info2);

        }
        else{
            cout << "Unknow command: " << instruction << endl;
        }
        
        str1.clear();
        instruction.clear();
        info1.clear();
        info2.clear();
        date.clear();
        days.clear();
        years.clear();
        months.clear();
        orden.clear();
    }
    return 0;
}

void Find(const multimap<string, string>& events, vector<string>& orden, string info1){
    int i, j;
    string aux;
    for(const auto& element : events){
        if(element.first == info1){
            orden.push_back(element.second);
        }
    }
    for(i = 0; i < orden.size(); i++){
        for(j=0; j<orden.size();j++){
            if(j == orden.size()-1){
                break;
            }
            else if(orden[j] > orden[j+1]){
                aux = orden[j];
                orden[j] = orden[j+1];
                orden[j+1] = aux;
            }
        }
    }
    for(auto element : orden){
        cout << element << endl;
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

void Complete(string& info1){    
if(info1[0] == '-'){
    string aux;
    for(int i = 1; i < info1.size(); i++){
        aux+=info1[i];
    }
    stringstream s1(aux);
    getline(s1, years, '-');
    getline(s1, months, '-');
    getline(s1, days, '-');
    int year = stoi(years);
    int month = stoi(months);
    int day = stoi(days);
    years = to_string(year);
    months = to_string(month);
    days = to_string(day);
    if(years.size() == 1){
        date+= "-000";
        date+= years;
    }
    else if(years.size() == 2){
        date+= "-00";
        date+= years;
    }
    else if(years.size() == 3){
        date+= "-0";
        date+= years;
    }
    else{
        date+= '-';
        date+= years;
    }
    if(months.size() == 1){
        date+= "-0";
        date+= months;
    }
    else{
        date+= '-';
        date+= months;
    }
    if(days.size() == 1){
        date+= "-0";
        date+= days;
    }
    else{
        date+= '-';
        date+= days;
    }
}
else{
    stringstream s1(info1);
    getline(s1, years, '-');
    getline(s1, months, '-');
    getline(s1, days, '-');
    int year = stoi(years);
    int month = stoi(months);
    int day = stoi(days);
    years = to_string(year);
    months = to_string(month);
    days = to_string(day);
    if(years.size() == 1){
        date+= "000";
        date+= years;
    }
    else if(years.size() == 2){
        date+= "00";
        date+= years;
    }
    else if(years.size() == 3){
        date+= "0";
        date+= years;
    }
    else{
        date+= years;
    }
    if(months.size() == 1){
        date+= "-0";
        date+= months;
    }
    else{
        date+= '-';
        date+= months;
    }
    if(days.size() == 1){
        date+= "-0";
        date+= days;
    }
    else{
        date+= '-';
        date+= days;
    }
}
}