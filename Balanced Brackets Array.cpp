#include <iostream>
#include <string>
using namespace std;


// ===== ArrayStack Implementation =====
template <typename T>
class ArrayStack {
private:
    static const int MAX_SIZE = 1000;
    T data[MAX_SIZE];
    int topIndex;


public:
    ArrayStack() : topIndex(-1) {} // Initialize empty stack


    bool isEmpty() const { return topIndex == -1; } // check if the stack is empty or not?


    bool isFull() const { return topIndex == MAX_SIZE - 1; } // check wether if the stack reach its capacity


    void push(const T& item) {
        if (isFull()) throw overflow_error("Stack overflow"); // push an item on to the stack // overflow means if there's no space left
        data[++topIndex] = item; // pre-increment then place the item at the new top
    }


    void pop() {
        if (isEmpty()) throw underflow_error("Stack underflow"); // remove the top item from the stack // underflow means if stack is empty
        --topIndex; // decrement the top index to remove the element logically
    }


 // return the current top element by value
    T top() const {
        if (isEmpty()) throw underflow_error("Stack is empty");
        return data[topIndex];
    }
};


// check if the open and close is matching (valid or invalid)
// ===== Bracket Checking Function =====
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}


// Scan text left to right and detect mismatch or unmatch brackets
// ===== Linter Function =====
int checkBalancedBrackets(const string& text) {
    ArrayStack<char> stack;


    for (int i = 0; i < text.size(); ++i) {
        char ch = text[i];
        if (ch == '(' || ch == '[' || ch == '{') {
            stack.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (stack.isEmpty()) return i + 1;  // unmatched closing bracket
            char topChar = stack.top();
            if (!isMatchingPair(topChar, ch)) return i + 1;  // mismatch
            stack.pop();
        }
    }


    if (!stack.isEmpty()) return text.size() + 1;  // if the stack is not empty it means that there's at least once
    return -1; // valid
}


// ===== Main for Demonstration =====
int main() {
    string input;
    cout << "Enter expression: "; // User input
    getline(cin, input); // read full line including space


    int errorIndex = checkBalancedBrackets(input); // call out checkBalanceBrackets input
    if (errorIndex == -1) //
        cout << "Valid brackets!" << endl;
    else
        cout << "Invalid at position " << errorIndex << endl;


    return 0;
}
