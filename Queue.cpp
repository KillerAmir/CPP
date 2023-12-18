#include <iostream>
#include <queue>

using namespace std;

int main() {
    queue<int> myQueue;

  
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

   
    cout << "Front element: " << myQueue.front() << endl;

   
    myQueue.pop();

    
    cout << "Size of the queue: " << myQueue.size() << endl;

    
    cout << "Is the queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl;

    return 0;
}
