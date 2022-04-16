#include <queue>
void reverseQueue(queue<int> &input) {
    if(input.empty())
        return;

	int lastElement = input.front();
    input.pop();
    reverseQueue(input);
    input.push(lastElement);
}