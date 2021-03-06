#include <iostream>
#include <string>
#include <fstream>
#include "personality_test.h"


using namespace std;

void load_file(personality_test&);

/* main
 * Calls necessary functions in this file as well as functions in personality_test
 * @param None
 * @return None, Text to Console
 */
int main () {
    cout << "====================================" << endl;
    cout << "Welcome to CSCI262 Personality Test!" << endl;
    cout << "====================================" << endl << endl;

    personality_test test;

    // Uncomment the below methods as you complete them
    bool play_again = true;
    while(play_again){
        load_file(test);
        play_again = test.run_test();
    }
//    test.printout();
}

/* Load File Method
 * 1) Prompt the user for a file name. 
 * 2) Confirm that the file can be loaded
 * 3) Run personality_test::load to load in the data
 * 4) If personality_test::load fails, report this and retry
 * @param personality_test object (by reference)
 * @return None, Text to Console
 */
void load_file(personality_test& test) {
    bool a = true;
    while (a) {
        string fileName;
        cout << endl;
        cout << "Please enter the input file name, e.g., \"questions.txt\": ";\
        cin >> fileName;
        fstream fin(fileName);
        try {
            if(test.load(fin)){
                a = false;
            } else {
                throw runtime_error("Input file \"" + fileName + "\" appears to not be a proper file!");
            }
            fin.close();
        } catch (fstream::failure &e) {
            cout << endl;
            cout << "error opening file: \"" << fileName << "\" " << endl;
            a = true;
        } catch (runtime_error &e) {
            cout << e.what() << endl;
        }
    }
}
