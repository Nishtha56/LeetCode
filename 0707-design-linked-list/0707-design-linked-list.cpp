class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data=val;
        next=NULL;
    }
};

class MyLinkedList{
public:
    Node* head;
    Node* tail;
    int size;

    MyLinkedList(){
        head=NULL;
        tail=NULL;
        size=0;
    }

    int get(int index){
        if(index<0 || index>=size)
            return -1;

        Node* temp=head;

        for(int i=0;i<index;i++){
            temp=temp->next;
        }

        return temp->data;
    }

    void addAtHead(int val){
        Node* node=new Node(val);

        if(head==NULL){
            head=node;
            tail=node;
        }
        else{
            node->next=head;
            head=node;
        }

        size++;
    }

    void addAtTail(int val){
        Node* node=new Node(val);

        if(head==NULL){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }

        size++;
    }

    void addAtIndex(int index,int val){
        if(index<0 || index>size)
            return;

        if(index==0){
            Node* node=new Node(val);

            if(head==NULL){
                head=node;
                tail=node;
            }
            else{
                node->next=head;
                head=node;
            }

            size++;
            return;
        }

        if(index==size){
            Node* node=new Node(val);

            if(head==NULL){
                head=node;
                tail=node;
            }
            else{
                tail->next=node;
                tail=node;
            }

            size++;
            return;
        }

        Node* temp=head;

        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }

        Node* node=new Node(val);
        node->next=temp->next;
        temp->next=node;

        size++;
    }

    void deleteAtIndex(int index){
        if(index<0 || index>=size)
            return;

        if(index==0){
            Node* temp=head;
            head=head->next;

            if(size==1)
                tail=NULL;

            delete temp;
            size--;
            return;
        }

        Node* temp=head;

        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }

        Node* del=temp->next;
        temp->next=del->next;

        if(del==tail)
            tail=temp;

        delete del;
        size--;
    }
};