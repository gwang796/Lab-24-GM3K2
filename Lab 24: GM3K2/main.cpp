//
//  main.cpp
//  Lab 24: GM3K2
//
//  Created by Guo An Wang on 10/26/25.
//

//
//  main.cpp
//  COMSC-210 | lab 23: Goat Manager 3001 | Guo An Wang
//  IDE: Xcode
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include <ctime>
#include <cstdlib>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;

//select_function no longer needed because set is based on uniqueness of data

//function delete_goat deletes user selected goat object
//arguments: Goat set trip
//return: none
void delete_goat(set<Goat> &trip);

//function add_goat adds a goat with random values
//arguments: Goat set trip, array of names, array of colors
//return: none
void add_goat(set<Goat> &trip, string [], string []);

//function display_goat displays list
//arguments: Goat set trip
//return: none
void display_trip(set<Goat> trip);

//function main_menu has user choose action
//arguments: none
//return: none
int main_menu();

int main() {
    srand(time(0));
    bool again = true;
    // read & populate arrays for names and colors
    ifstream fin("Names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("Colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();
    set<Goat> trip; //declare Goat list trip
    int choice;
    while (again) { //loops until again = false
        choice = main_menu();
        if (choice == 1) {
            add_goat(trip, names, colors);
        } else if (choice == 2) {
            delete_goat(trip);
        } else if (choice == 3) {
            display_trip(trip);
        } else if (choice == 4){
            cout << "Exiting program" << endl;
            again = false;
        }
    }
    return 0;
}
int main_menu() {
    int user;
    cout << "*** GOAT MANAGER 3001 ***" << endl;
    cout << "[1] Add a goat \n[2] Delete a goat \n[3] List goats \n[4] Quit" << endl;
    cout << "Choice --> ";
    cin >> user;
    cin.ignore();
    if (user < 0 || user > 4) {
        cout << "Not a valid option" << endl;
        return 1;
    }
    return user;
}
void add_goat(set<Goat> &trip, string names[], string colors[]){
    int randomName = rand() % SZ_NAMES;
    int randomColor = rand() % SZ_COLORS;
    int randomAge = rand() % MAX_AGE;
    
    string name = names[randomName];
    string color = colors[randomColor];
    
    Goat newGoat(name, randomAge, color);
    trip.insert(newGoat);
    display_trip(trip);
}

void delete_goat(set<Goat> &trip){
    if (trip.empty()) {
        cout << "List is empty" << endl;
        return;
     }
    int a;
    string n,c;
    cout << "Enter name to delete: ";
    cin >> n;
    cin.ignore();
    cout << "Enter age to delete: ";
    cin >> a;
    cin.ignore();
    cout << "Enter color to delete: ";
    cin >> c;
    cin.ignore();
    int counter = 1;
    for (auto it = trip.begin(); it != trip.end(); ++it) { //iterates through whole list
        if (it->get_name()==n && it->get_age()==a && it->get_color()==c) { //but only prints at selected delete goat
            cout << "Deleting: " << "[" << counter << "] " <<  it->get_name() << " (" << it->get_age() << ", " << it->get_color() << ") " << endl;
            //use it++ because it deletes it the moves to next node
            //if erase.(it) that completely deletes it, so doing ++it after is invalid because its indefined
            trip.erase(it++);
            display_trip(trip);
            return;
        }
    }
    cout << "\nGoat was not found" << endl;
    cout << endl;
}
void display_trip(set<Goat> trip){
    if (trip.empty()) {
        cout << "List is empty" << endl;
        cout << endl;
        return;
    }
    cout << "\nGoat List: " << endl;
    int i = 1;
    for (auto &val : trip) {
        cout << "[" << i++ << "] " << val.get_name() << " (" << val.get_age() << ", " << val.get_color() << ") " << endl;
    }
    cout << endl;
}
