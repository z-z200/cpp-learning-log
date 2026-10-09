#include <iostream>
#include <string>
#include <vector>

struct Todo {
    std::string title;
    bool completed = false;
};

int main() {
    std::vector<Todo> todos;
    int choice = 0;

    do {
        std::cout << "\n1. Add todo\n";
        std::cout << "2. List todos\n";
        std::cout << "3. Mark todo completed\n";
        std::cout << "4. Delete todo\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";

        std::cin >> choice;

        if (choice == 1) {
            std::cin.ignore();

            Todo todo;
            std::cout << "Todo: ";
            std::getline(std::cin, todo.title);

            todos.push_back(todo);
            std::cout << "Added: " << todo.title << "\n";
        } else if (choice == 2) {
            if (todos.empty()) {
                std::cout << "No todos yet.\n";
            } else {
                for (std::size_t i = 0; i < todos.size(); ++i) {
                    std::cout << i + 1 << ". [";

                    if (todos[i].completed) {
                        std::cout << "x";
                    } else {
                        std::cout << " ";
                    }

                    std::cout << "] " << todos[i].title << "\n";
                }
            }
        } else if (choice == 3) {
            if (todos.empty()) {
                std::cout << "No todos to mark.\n";
            } else {
                int index = 0;
                std::cout << "Todo number: ";
                std::cin >> index;

                if (index < 1 || index > static_cast<int>(todos.size())) {
                    std::cout << "Invalid todo number.\n";
                } else {
                    const std::size_t position = static_cast<std::size_t>(index - 1);
                    todos[position].completed = true;
                    std::cout << "Marked completed: " << todos[position].title << "\n";
                }
            }
        } else if (choice == 4) {
            if (todos.empty()) {
                std::cout << "No todos to delete.\n";
            } else {
                int index = 0;
                std::cout << "Todo number: ";
                std::cin >> index;

                if (index < 1 || index > static_cast<int>(todos.size())) {
                    std::cout << "Invalid todo number.\n";
                } else {
                    const std::size_t position = static_cast<std::size_t>(index - 1);
                    std::cout << "Deleted: " << todos[position].title << "\n";
                    todos.erase(todos.begin() + static_cast<std::ptrdiff_t>(position));
                }
            }
        } else if (choice != 0) {
            std::cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    std::cout << "Goodbye.\n";
    return 0;
}