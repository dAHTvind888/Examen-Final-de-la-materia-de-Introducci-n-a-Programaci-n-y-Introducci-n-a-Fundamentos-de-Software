#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string input, command, date1, event1, date2, days, years, months;
vector<string> orden;
multimap<string, string> BD;

void Find(const multimap<string, string>& events, vector<string>& orden, string info1);
void Del_date_event(multimap<string, string>& events, string info1, string info2);
void Print(const multimap<string, string>& events);
void Add(multimap<string, string>& events, string info1, string info2);
void Del_complete(multimap<string, string>& events, string info1);
bool check_date_range(string s);
bool check_double_neg(string s);
void Complete(string& info1);

int main() {
    while(true){
        getline(cin, input);
        stringstream ss(input);
        getline(ss, command, ' ');
        if(command == "Add"){
            getline(ss, date1, ' ');
            if(check_double_neg(date1) && check_date_range(date1)){
                getline(ss, event1, ' ');
                Complete(date1);
                Add(BD, date2, event1);
            }
            else{
                return 0;
            }
        }
        else if(command == "Del"){
            getline(ss, date1, ' ');
            getline(ss, event1, ' ');
            if(check_double_neg(date1) && check_date_range(date1)){
                if(event1.empty()){
                    Complete(date1);
                    Del_complete(BD, date2);
                }
                else{
                    Complete(date1);
                    Del_date_event(BD, date2, event1);
                }
            }
            else{
                return 0;
            }
        }
        else if(command == "Print"){
            Print(BD);
        }
        else if(command == "Find"){
            getline(ss, date1, ' ');
            if(check_double_neg(date1) && check_date_range(date1)){
            Complete(date1);
            Find(BD, orden, date2);
            }
            else{
                return 0;
            }
        }
        else{
            cout << "Unknown command: " + command << endl;
            return 0;
        }
        input.clear();
        command.clear();
        date1.clear();
        event1.clear();
        date2.clear();
        days.clear();
        years.clear();
        months.clear();
        orden.clear();
    }
return 0;
}

bool check_double_neg(string s){
    int negative = 0;
    for(char c : s){
        if(c == '-'){
            ++negative;
            if(negative == 2){
                cout << "Wrong date format: " + s << endl;
                return false;
            }
        }
        else{
            negative = 0;
            continue;
        }
    }
    return true;    
}

bool check_date_range(string s){
    string year, month, day, aux_s;

    if(s[0] == '-'){
        for(int i = 1; i < s.size(); ++i){
            aux_s += s[i];
        }
    }
    else{
        aux_s = s;
    }
    
    stringstream date(aux_s);
    getline(date, year, '-');
    getline(date, month, '-');
    getline(date, day, ' ');
    
    int year_int = stoi(year);
    int month_int = stoi(month);
    int day_int = stoi(day);
    
    if(month_int <= 0 || month_int > 12){
        cout << "Month value is invalid: " + month << endl;    
        return false;
    }
    else if(day_int < 1 || day_int > 31){
        cout << "Day value is invalid: " + day << endl;
        return false;
    }
    return true;
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
        date2+= "-000";
        date2+= years;
    }
    else if(years.size() == 2){
        date2+= "-00";
        date2+= years;
    }
    else if(years.size() == 3){
        date2+= "-0";
        date2+= years;
    }
    else{
        date2+= '-';
        date2+= years;
    }
    if(months.size() == 1){
        date2+= "-0";
        date2+= months;
    }
    else{
        date2+= '-';
        date2+= months;
    }
    if(days.size() == 1){
        date2+= "-0";
        date2+= days;
    }
    else{
        date2+= '-';
        date2+= days;
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
        date2+= "000";
        date2+= years;
    }
    else if(years.size() == 2){
        date2+= "00";
        date2+= years;
    }
    else if(years.size() == 3){
        date2+= "0";
        date2+= years;
    }
    else{
        date2+= years;
    }
    if(months.size() == 1){
        date2+= "-0";
        date2+= months;
    }
    else{
        date2+= '-';
        date2+= months;
    }
    if(days.size() == 1){
        date2+= "-0";
        date2+= days;
    }
    else{
        date2+= '-';
        date2+= days;
    }
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

void Del_complete(multimap<string, string>& events, string info1){
    int j = 0;
    for(auto i = events.begin(); i != events.end();){
        if(i -> first == info1){
            i = events.erase(i);
            ++j;
        }
        else{
            ++i;
        }
    }
    cout << "Deleted " << j << " events" << endl;
}

void Del_date_event(multimap<string, string>& events, string info1, string info2){
    auto range = events.equal_range(info1);
    for(auto i = range.first; i != range.second;){
        if(i -> second == info2){
            i = events.erase(i); //erase borra el i actual y amuenta en uno su valor
            cout << "Deleted successfully" << endl;
            return;
        }
        else{
            ++i;
        }
    }
    cout << "Event not found" << endl;
}

void Print(const multimap<string, string>& events){
    string year;
    for(const auto& element : events){
        if(element.first[0] == '-'){
            continue;
        }
        else{
            cout << element.first << " " << element.second << endl;
        }
         
    }
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
            else if(orden[j] >= orden[j+1]){
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