#include <iostream>
#include "FileManager.h"
#include "types/String.h"
#include "command/Parser.cpp"
#include "command/Create.h"
#include "command/Drop.h"
#include "command/Select.h"
#include "command/Update.h"
#include "command/Delete.h"
#include "command/Insert.h"

using namespace std;


int main() {
/*    FileManager f("a.txt", "w");
    String s;
    cout << "Input your multiline text" << endl;
    cin >> s;
    try {
        f.write(s);
        cout << endl;
        cout << "Successfully wrote the content!" << endl;
        cout << "Exiting..." << endl;
    } catch (const char* msg) {
        cout << msg << endl;
    }*/
    String query(';');
    cout << "Welcome to Database" << endl;
    cout << "Type commands" << endl;
    while (true) {
        cout << " $>:";
        cin >> query;
        switch (Parser::getCMD(query)) {
            case COMMAND_SELECT:
                Select select;
                select.run(query);
                break;
            case COMMAND_UPDATE:
                Update update;
                update.run(query);
                break;
            case COMMAND_DELETE:
                Delete del;
                del.run(query);
                break;
            case COMMAND_INSERT:
                Insert insert;
                insert.run(query);
                break;
            case COMMAND_DROP:
                Drop drop;
                drop.run(query);
                break;
            case COMMAND_CREATE:
                Create create;
                create.run(query);
                break;
            case COMMAND_EXIT:
                return 0;
            default:
                cout << "Command not found!" << endl;
                break;
        }
    }
    return 0;
}