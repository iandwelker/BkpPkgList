#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char * argv[]) {
    string origLine;
    string newLine;
    string origPkgName;
    string newPkgName;
    bool add = true;

    ifstream comp;
    ifstream orig;
    ofstream repl;

    comp.open(argv[1]);
    orig.open(argv[2]);
    repl.open(argv[3]);

    if (!comp || !orig || !repl) {
        cout << "Please input real files.\n";
        return 1;
    }

    while (getline(orig, origLine)) {
        repl << origLine << endl;
    } //This is just temporary until I figure out a way to insert the pkg names in the correct spot

    orig.close();

    while (getline(comp, newLine)) {
        newPkgName = "";
        orig.open(argv[2]);

        for (int i = 0; i < newLine.size() && newLine[i] != ' '; ++i) {
            newPkgName.push_back(newLine[i]);
        }

        while (getline(orig, origLine)) {
            origPkgName = "";
            if (origLine[0] != newPkgName[0]) {
                continue;
            }

            for (int i = 0; i < origLine.size() && !isspace(origLine[i]); ++i) {
                origPkgName.push_back(origLine[i]);
            }

            if (newPkgName == origPkgName) {
                add = false;
                break;
            }
        }

        if (add) {
            repl << newLine << endl;
        }

        orig.close();
    }

    return 0;
} 