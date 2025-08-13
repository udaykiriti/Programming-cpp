#include <iostream>
using namespace std;

const int MAX = 100; // Maximum size of stack
int stack[MAX];      // Stack array
int top = -1;        // Index of top element

void push(int value)
{
  if (top >= MAX - 1)
  {
    cout << "Stack Overflow!" << endl;
    return;
  }
  top++;
  stack[top] = value;
  cout << value << " pushed to stack." << endl;
}

void pop()
{
  if (top < 0)
  {
    cout << "Stack Underflow!" << endl;
    return;
  }
  cout << stack[top] << " popped from stack." << endl;
  top--;
}

int peek()
{
  if (top < 0)
  {
    cout << "Stack is empty." << endl;
    return -1;
  }
  return stack[top];
}

void display()
{
  if (top < 0)
  {
    cout << "Stack is empty." << endl;
    return;
  }
  cout << "Stack: ";
  for (int i = top; i >= 0; i--)
  {
    cout << stack[i] << " ";
  }
  cout << endl;
}

int main()
{
  push(10);
  push(20);
  push(30);
  display();
  cout << "Top element is: " << peek() << endl;
  pop();
  display();`
  return 0;
}
