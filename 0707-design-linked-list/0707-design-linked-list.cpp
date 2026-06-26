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
    int sz;

    MyLinkedList(){
        head=NULL;
        tail=NULL;
        sz=0;
    }

    int get(int index){
        if(index<0 || index>=sz)
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

        sz++;
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

        sz++;
    }

    void addAtIndex(int index,int val){
        if(index<0 || index>sz)
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

            sz++;
            return;
        }

        if(index==sz){
            Node* node=new Node(val);

            if(head==NULL){
                head=node;
                tail=node;
            }
            else{
                tail->next=node;
                tail=node;
            }

            sz++;
            return;
        }

        Node* temp=head;

        for(int i=0;i<index-1;i++){
            temp=temp->next;
        }

        Node* node=new Node(val);
        node->next=temp->next;
        temp->next=node;

        sz++;
    }

    void deleteAtIndex(int index){
        if(index<0 || index>=sz)
            return;

        if(index==0){
            Node* temp=head;
            head=head->next;

            if(sz==1)
                tail=NULL;

            delete temp;
            sz--;
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
        sz--;
    }
};