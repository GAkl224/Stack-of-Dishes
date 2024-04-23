#include <iostream>
#include <array>
#include <string>

using namespace std;

class Dish {
private:
    string description;

public:
    
    Dish() : description("") {}

    Dish(string description) : description(description) {}

    string get_description() const {
        return description;
    }
};

class DishStack {
private:
    static const int MAX_SIZE = 100;
    array<Dish, MAX_SIZE> stackArray;
    int topIndex;

public:
    DishStack() : topIndex(-1) {}

    void push(const Dish& dish) {
        if (topIndex == MAX_SIZE - 1) {
            cout << "Stack is full. Cannot push more elements." << endl;
            return;
        }
        stackArray[++topIndex] = dish;
    }

    Dish pop() {
        if (topIndex == -1) {
            cout << "Stack is empty. Cannot pop." << endl;
            return Dish(""); 
            
        }
        return stackArray[topIndex--];
    }

    Dish peek() const {
        if (topIndex == -1) {
            cout << "Stack is empty. Cannot peek." << endl;
            return Dish(""); 
            
        }
        return stackArray[topIndex];
    }

    int size() const {
        return topIndex + 1;
    }
};

int main() {
    DishStack stack;
    Dish one_dish("One");
    Dish two_dish("Two");
    Dish three_dish("Three");
    Dish four_dish("Four");

    int stack_size = stack.size();

    stack.push(one_dish);
    stack.push(two_dish);
    stack.push(three_dish);
    stack.push(four_dish);

   

    int size_after_pushes = stack.size();

    Dish peeked_dish = stack.peek();

    Dish popped_dish = stack.pop();

    Dish another_popped_dish = stack.pop();

    int final_size = stack.size();

    return 0;
}
