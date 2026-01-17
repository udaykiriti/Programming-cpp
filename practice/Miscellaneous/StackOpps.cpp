#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;

  Node(int value)
  {
    data = value;
    next = nullptr;
  }
};

class Stack
{
private:
  Node *top;

public:
  Stack()
  {
    top = nullptr;
  }

  void push(int value)
  {
    Node *newNode = new Node(value);
    newNode->next = top;
    top = newNode;
    cout << value << " pushed to stack." << endl;
  }

  void pop()
  {
    if (isEmpty())
    {
      cout << "Stack Underflow!" << endl;
      return;
    }
    Node *temp = top;
    top = top->next;
    cout << temp->data << " popped from stack." << endl;
    delete temp;
  }

  int peek()
  {
    if (isEmpty())
    {
      cout << "Stack is empty." << endl;
      return -1;
    }
    return top->data;
  }

  bool isEmpty()
  {
    return top == nullptr;
  }

  void display()
  {
    if (isEmpty())
    {
      cout << "Stack is empty." << endl;
      return;
    }
    Node *temp = top;
    cout << "Stack: ";
    while (temp != nullptr)
    {
      cout << temp->data << " ";
      temp = temp->next;
    }
    cout << endl;
  }

  ~Stack()
  {
    while (!isEmpty())
      pop();
  }
};

int main()
{
  Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  s.display();

  cout << "Top element is: " << s.peek() << endl;

  s.pop();
  s.display();

  return 0;
}
