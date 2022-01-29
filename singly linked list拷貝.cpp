#include <iostream>

template <typename T>
class Node {

  public:
    //constructor1.沒有賦予值時，next指向0(NULL)
    Node() : next(0) { }
    //constructor2.裡面賦予值時，next指向0(NULL)
    Node(const T& value) : val(value), next(0) { }
    T val;
    Node* next;

  private:
    Node(const Node& nd) { }
    Node& operator=(const Node& nd) { }
};

template <typename T>
class List {

  public:
    List() {
      begin = new Node<T>();
    }

    List(T initval) {
      begin = new Node<T>(initval);
    }
    List(const List& inp) {
      begin = new Node<T>(inp.begin->val);
      Node<T> *tempInitial = inp.begin->next;
      Node<T> *tempFinal = begin;

      while(tempInitial->next) {
        tempFinal->next = new Node<T>();
        tempFinal = tempFinal->next;
        tempFinal->val = tempInitial->val;
        tempInitial = tempInitial->next;
     }
  }


  void addVal(const T& val) {
    if(!begin->next && begin->val == 0) {
      begin->val = val;
    }
    else {
      Node<T> *temp = begin;
      while(temp->next) {
        temp = temp->next;
      }
    temp->next = new Node<T>(val);
    }
  }

  bool deleteVal(const T& val) {
    Node<T>* pos = isPresentN(val);
    if( pos == 0) return 0;
    if(pos == begin) { begin = pos->next; delete pos; return 1;  }

    Node<T>* temp = begin;
    while(temp->next != pos) {
      temp = temp->next;
    }
    Node<T>* delnode = temp->next;
    temp->next = temp->next->next;
    delete delnode;
    return 1;
  }



  Node<T>* isPresentN(const T& val) {
    Node<T>* temp = begin;
    while(temp) {
      if(temp->val == val)  return temp;
    temp = temp->next;
    }

  return 0;
  }

  bool isPresent(const T& val) {
    if(isPresentN(val)) return 1;
    return 0;
  }

  ~List() {
    Node<T>* temp= begin, *t;
    while(temp) {
      t = temp;
      temp = temp->next;
      delete t;
    }
  }

  private:
    Node<T> *begin;
};

int main(void){
    
}
