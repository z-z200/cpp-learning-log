#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<std::string> todos;
    int choice = 0;

    do {
        std::cout << "\n1. Add todo\n";
        std::cout << "2. List todos\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore();

            std::string todo;
            std::cout << "Todo: ";
            std::getline(std::cin, todo);

            todos.push_back(todo);
            std::cout << "Added: " << todo << "\n";
        } else if (choice == 2) {
            if (todos.empty()) {
                std::cout << "No todos yet.\n";
            } else {
                for (std::size_t i = 0; i < todos.size(); ++i) {
                    std::cout << i + 1 << ". " << todos[i] << "\n";
                }
            }
        } else if (choice != 0) {
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    std::cout << "Goodbye.\n";
    return 0;
}