#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
class List{
private:
    //head是一個指向Node的pointer
    //先初始化head指向NULL，empty list
    Node* head;
    Node* tail;
    int NodeCounter = 0;
public:
    //constructure，建立一個空List，
    List(){
        head = NULL;
        tail = NULL;
    }
    void InsertAtBegin(int x){
        //創建一個指向Node的pointer:temp
        //要求記憶體給Node
        Node* temp = new Node();
        //初始化新Node的data
        temp->data = x;
        //讓新Node指向和head指向一樣的地方（加新Node前的第一個Node）
        temp->next = head;
        //讓head指向和temp一樣的地方（新Node）
        head = temp;
        NodeCounter++;
    }
    //在linked list結尾增加新Node
    void addNode(int x){
        //Node* temp:創造一個指向Node的pointer
        //new Node():創造給Node的記憶體
        //"=":pointer指向Node
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        //若list裡面已經有node
        if(head!=NULL){
            //創造新的pointer指向HeadNode
            Node* temp1 = head;
            //做出traversal，從HeadNode出發直到碰到結尾的Node
            while(temp1->next!=NULL){
                temp1 = temp1->next;
            }
            //讓結尾Node指向新增的Node
            temp1->next = temp;
            cout<<"新NodeData為:"<<temp->data<<endl;
        }
        //若list裡面是空的，就創建新Node
        else{
            head = temp;
            cout<<"新NodeData為:"<<temp->data<<endl;
        }
        NodeCounter++;
    }
    void PrintNode(){
        //建立traversal
        Node* temp1 = head;
        cout<<"List is: ";
        while(temp1!=NULL){
            cout<<temp1->data<<" ";
            temp1 = temp1->next;
        }
        cout<<"Now has "<<NodeCounter<<" Node"<<endl;
        
    }
    void InsertAt(int data, int n){
        Node* temp = new Node;
        temp->data = data;
        temp->next = NULL;
        if(n<1||n>NodeCounter+1){
            cout<<"You can only insert node between 1 and "<< NodeCounter+1 <<endl;
            return;
        }
        //特殊情況，若要在n=1插入Node
        //則要操控headPointer
        else if(n==1){
            temp->next = head;
            head = temp;
            NodeCounter++;
            return;
        }
        //若n!=1
        else{
            //創造一個traversal(新的Pointer指向firstNode)
            Node* temp1 = head;
            //創造迴圈，讓temp1從firstNode出發跑n-1次
            //停在n-1的位置
            for(int i = 0; i < n-2; i++){
                temp1 = temp1->next;
            }
            //讓新建立的Node指向舊的n位置
            temp->next = temp1->next;
            //讓建立的traversal指向新的Node
            temp1->next = temp;
            NodeCounter++;
            return;
        }
    }
    void deleteAt(int n){
        Node* temp1 = head;
        if(n<1||n>NodeCounter){
            cout<<"You can only delete node between 1 and "<< NodeCounter <<endl;
            return;
        }
        //要改到head就要另外的程式
        else if (n == 1){
            head = temp1->next;
            //釋放被temp1指向的Node的記憶體
            delete temp1;
            NodeCounter--;
            return;
        }
        else{
            for(int i = 0; i < n-2; i++){
                temp1 = temp1->next;
            }
            //創建新的pointer指向要刪掉的Node
            Node* temp2 = temp1->next;
            //讓travasal指向的Node的next指向要被刪掉的Node的next
            temp1->next = temp2->next;
            //清除要刪掉的Node的記憶體
            delete temp2;
            NodeCounter--;
            return;
        }
    }
    void Reverse(){
        //創造3個pointer，才能把list反過來
        Node *current, *prev, *next;
        current = head;
        prev = NULL;
        while(current!=NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    //用Recursion的方法讓list反過來
    //只需用額外的一個pointer
    void ReverseRecursion(Node* p){
        //Exit condition
        //讓headPointer指向原本的結尾Node
        if(p->next == NULL){
            head = p;
            return;
        }
        //呼叫recursion函式
        ReverseRecursion(p->next);
        //建立新的pointer指向現在recursion的下一個Node
        Node* temp = p->next;
        //讓下個Node的next指向他的前一個Node
        temp->next = p;
        //讓現在recursion的這個Node的next指向NULL
        //方便下一步操作
        p->next = NULL;
    }
    //用recursion的方式print出所有Node
    void PrintRecursion(Node* p){
        //Exit condition, end recursion
        if(p==NULL) return;
        cout<<p->data<<" ";
        PrintRecursion(p->next);
    }
    //用recursion的方式print出所有Node
    //而且讓list完全相反 
    void ReversePrint(Node* p){
        if(p==NULL) return;
        //和PrintRecursion不同的地方：
        //先呼叫函式，再print出data
        ReversePrint(p->next);
        cout<<p->data<<" ";

    }
    //回傳和head指向同個地方的pointer
    Node* ReturnHead(){
        return head;
    }
};


int main(void){
    List list;
    list.addNode(1);
    list.addNode(3);
    list.addNode(5);
    list.addNode(7);
    list.InsertAtBegin(100);
    list.InsertAtBegin(50);
    list.PrintNode();
    list.InsertAt(36, 2);
    list.PrintNode();
    list.InsertAt(47,8);
    list.PrintNode();
    list.deleteAt(1);
    list.PrintNode();
    Node* temp = list.ReturnHead();
    list.ReverseRecursion(temp);
    list.PrintNode();
    
 
    
}
