#include <iostream>
using namespace std;

class Node{
	public:
		Node*next;
		int data;
		
		Node(int d){
			data = d;
			next=nullptr;
		}
};

class LinkedList{
	Node* head;
	public:
		LinkedList(){
			head = nullptr;
		}
		void insert_at_end(int data){
			Node *newnode = new Node(data);
			if(head==nullptr){
				head = newnode;
				return;
			}
			Node*temp = head;
			while(temp->next!=nullptr){
				temp = temp->next;
			}
			temp->next = newnode;
		}
		
		void insert_at_front(int data){
			Node *newnode = new Node(data);
			if(head==nullptr){
				head = newnode;
				return;
			}
			newnode->next = head;
			head = newnode;
		}

		void delete_from_end(){
			Node*temp = head, *prev;
			if(head==nullptr) return;
	
			if(head->next==nullptr){
				delete head;
				head = nullptr;
				return;
			}
			
			while(temp->next!=nullptr){
				prev = temp;
				temp = temp->next;
			}
			prev -> next = nullptr;
			delete temp;
			
		}
		
		
		void display(){
			Node *temp = head;
			while(temp!=nullptr){
				cout<<temp->data;
				temp = temp->next;
				if(temp!=nullptr) cout<<" -> ";
			}
			cout<<endl;
		}
		
		
		~LinkedList(){
			Node* temp1 = head, *temp2;
			
			while(temp1!=nullptr){
				temp2 = temp1->next;
				delete temp1;
				temp1 = temp2;
			}
		}
		
		void bubbleSort(){
			bool swapped = 0;
			Node*ptr1, *ptr2=nullptr;
			do{
				ptr1=head;
				swapped = 0;
				while(ptr1->next!=ptr2){
					if(ptr1->data > ptr1->next->data){
						int tempdata = ptr1->data;
						ptr1->data = ptr1->next->data;
						ptr1->next->data = tempdata;
						swapped = 1;
						
					}
					ptr1 = ptr1-> next;
				}
				ptr2 = ptr1;
			}while (swapped==1);
		}
		
		Node* getHead()const{return head;
		}
		void sethead(Node * n){
			head = n;
		}
};

void join(LinkedList *l1, LinkedList*l2){
	Node* temp1 = l1->getHead();
	Node* temp2 = l2->getHead();
	Node* next1, *next2;
	
	while(temp1 && temp2){
		next1 = temp1->next;
		next2 = temp2->next;
		
		temp1->next = temp2;
		temp2->next = next1;
		temp1 = next1;
		temp2 = next2;
	}
	
	l2->sethead(temp2);
	
}

int main(){
	LinkedList L;
	cout<<"List:"<<endl;
	L.insert_at_end(0);
	L.insert_at_end(5);
	L.insert_at_end(7);
	L.insert_at_end(4);
	L.display();
	cout<<"Bubble sorted:"<<endl;
	L.bubbleSort();
	L.display();
	
	LinkedList *l1 = new LinkedList();
	LinkedList *l2 = new LinkedList();	
	
	l1->insert_at_end(1);
	l1->insert_at_end(2);
	l1->insert_at_end(3);
	
	l2->insert_at_end(4);
	l2->insert_at_end(5);
	l2->insert_at_end(6);
	l2->insert_at_end(7);
	l2->insert_at_end(8);
	
	cout<<"List 1:"<<endl;
	l1->display();
	cout<<"List 2:"<<endl;
	l2->display();
	join(l1, l2);
	cout<<"After joining:"<<endl;
	cout<<"List 1:"<<endl;
	l1->display();
	cout<<"List 2:"<<endl;
	l2->display();

	delete l1;
	delete l2;
	
	return 0;
}