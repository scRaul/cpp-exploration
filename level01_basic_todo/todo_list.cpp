#include <iomanip>
#include <iostream>
#include <vector>


using std::cout;

const char ADD_MODE = 'a';
const char MARK_MODE = 'm';
const char REMOVE_MODE = 'r';

const std::string TODO_COMPLETE = u8"\2714";

const std::string MARKING_PROMPT = "Check or Uncheck Todo";
const std::string ADDING_PROMPT = "Adding Todos";
const std::string REMOVE_PROMPT = "Remove Todos";

int main() {
    std::vector<std::string> todos;
    std::vector<bool> todo_state;
    int count = 0;
    char state = MARK_MODE;
    std::string input = "";

    while (true) {
        std::string prompt = state == MARK_MODE ? MARKING_PROMPT : state == ADD_MODE ? ADDING_PROMPT : REMOVE_PROMPT;
        cout << prompt << "\n\n";


        for (size_t i = 0; i < todos.size(); i++) {
            if (todos[i] == "")
                continue;
            std::string mark = todo_state[i] ? TODO_COMPLETE : " ";
            cout << i << "." << "[" << mark << "]" << todos[i] << "\n";
        }
        cout << "\n\n";
        cout << "(enter \'h\' for help)  : ";
        std::getline(std::cin, input);

        if (input.length() == 1 && input[0] == 'h') {
            cout << "quit the program: C^c\n\n";
            cout << "mark mode controls:\n";
            cout << "\tenter \'a\' to go to adding mode\n";
            cout << "\tenter \'r\' to go to remove mode\n";
            cout << "\tenter <index of todo> to go to toggle complete state\n";

            cout << "add mode controls:\n";
            cout << "\tenter C^n to go to go mark mode\n";
            cout << "\tenter <todo item> to add a todo\n";

            cout << "remove mode controls:\n";
            cout << "\tenter C^m to go to go mark mode\n";
            cout << "\tenter <index of todo> to remove a todo\n";

            cout << "enter any key to go back";
            std::cin >> input;
        } else if (state == MARK_MODE) {
            if (input[0] == 'a' && input.length() == 1) {
                state = ADD_MODE;
            } else if (input[0] == 'r' && input.length() == 1) {
                state = REMOVE_MODE;
            } else {
                int index = std::stoi(input);
                if (index < count && todos[index] != "") {
                    todo_state[index] = !todo_state[index];
                }
            }
        } else if (state == ADD_MODE) {
            if (input[0] == 14)
                state = MARK_MODE;
            else {
                todos.push_back(input);
                todo_state.push_back(false);
                count++;
            }
        } else if (state == REMOVE_MODE) {
            if (input[0] == 14)
                state = MARK_MODE;
            else {
                int index = std::stoi(input);
                if (index < todos.size()) {
                    todos[index] = "";
                    todo_state[index] = false;
                    count--;
                }
            }
        }
        input = "";
    }
    return 0;
}