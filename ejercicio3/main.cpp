#include <iostream>
#include <string>
#include <stack>
using namespace std;

template<typename T>
stack<T> reverseStack(stack<T> s){
    stack<T> reverse;
    while (!s.empty()){
        reverse.push(s.top());
        s.pop();
    }
    return reverse;
}

bool isPalindrome(string &word) {
    stack<char> wordStack;
    for (auto &i : word)
        // A = 65, Z = 90
        if (toupper(i) >= 65 && toupper(i) <= 90)
            wordStack.push(toupper(i));

    stack<char> reverse = reverseStack(wordStack);
    while (!wordStack.empty()){
        if (wordStack.top() != reverse.top()){
            cout << "La palabra/frase '" << word << "' no es un palindromo." << endl;
            return false;
        }
        wordStack.pop();
        reverse.pop();
    }
    cout << "La palabra/frase '" << word << "' es un palindromo." << endl;
    return true;
}


int main() {

    string testcase = "Anita lava la tina";
    isPalindrome(testcase);

    return 0;
}
