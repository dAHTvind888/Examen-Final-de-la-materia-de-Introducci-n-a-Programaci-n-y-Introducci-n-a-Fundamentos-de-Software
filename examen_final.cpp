#include"examen.h"

string input, command, date1, event1, date2;
vector<string> orden;
multimap<string, string> BD;

int main() {
    while(true){
        getline(cin, input);
        stringstream ss(input);
        getline(ss, command, ' ');
        if(command == "Add"){
            getline(ss, date1, ' ');
            if(check_double_neg(date1) && check_date_range(date1)){
                getline(ss, event1, ' ');
                Complete(date1, date2);
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
                    Complete(date1, date2);
                    Del_complete(BD, date2);
                }
                else{
                    Complete(date1, date2);
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
            Complete(date1, date2);
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
        orden.clear();
    }
return 0;
}

