#include <stack>
#include <queue>
#include <string>

using namespace std;

class StackQueue {
public:
    void push(int x);
    int pop();
    string to_string();
private:
    stack<int> s1;
    stack<int> s2;
};

void StackQueue::push(int x) {

}

int StackQueue::pop() {

}

string StackQueue::to_string() {
    return "";
}

int main() {
    StackQueue q;
    q.push(2);
    q.push(3);
    int a = q.pop();

    return 0;
}
