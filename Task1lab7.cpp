#include <iostream>
using namespace std;
 
//double linked list

class Node{
	public:
		Node*next, *prev;
		int data;
		
		Node(int d){
			data = d;
			prev=next=nullptr;
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
			newnode->prev = temp;
		}
		void insert_at_front(int data){
			Node *newnode = new Node(data);
			if(head==nullptr){
				head = newnode;
				return;
			}
			head->prev = newnode;
			newnode->next = head;
			head = newnode;
		}
		
		void delete_from_front(){
			if (head==nullptr) return;
			Node*temp = head;
			head = head->next;
			if(head!=nullptr)
				head->prev = nullptr;
			delete temp;
		}

		void delete_from_end(Node* temp = nullptr){
			if(head==nullptr) return;
			if(temp==nullptr) temp=head;
			if(head->next==nullptr){
				delete head;
				head = nullptr;
				return;
			}
			if(temp->next==nullptr){
				temp->prev->next = nullptr;
				delete temp;
				return;
			}
			delete_from_end(temp->next);
		}
	
	private:
		void delete_from_Pos_rec(int pos, Node*temp){
			if (head==nullptr||pos<1) return;
			if(temp==nullptr){
				cout<<"position not in linked list";
				return;
			}
			if(pos==1){
				if(temp==head){
					delete_from_front();
					return;
				}
				else{
					Node*prev = temp->prev;
					Node*next = temp->next;
					if(prev!=nullptr) prev->next = next;
					if(next!=nullptr) next->prev = prev;
					delete temp;
					return;
				}
			}
				
			delete_from_Pos_rec(pos-1, temp->next);
		}
	public:

		void delete_from_Pos(int pos){
			delete_from_Pos_rec(pos, head);
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
	private:
		void reverse_List(Node* curr){
			if(curr==nullptr) return;
			Node*temp = curr->next;
			curr->next = curr->prev;
			curr->prev = temp;

			if (curr->prev==nullptr){
				head = curr;
				return;
			}

			return reverse_List(curr->prev);
		}
	public:
		void reverse(){
			reverse_List(head);
		}
		
		~LinkedList(){
			Node* temp1 = head, *temp2;
			
			while(temp1!=nullptr){
				temp2 = temp1->next;
				delete temp1;
				temp1 = temp2;
			}
		}
};

int main(){
	LinkedList L;
	for(int i=1;i<=5;i++)
		L.insert_at_end(i);
	cout<<"List: "<<endl;
	L.display();
	
	L.reverse();
	cout<<"Reversed: "<<endl;
	L.display();
	
	L.delete_from_Pos(3);
	cout<<"3rd position deleted: "<<endl;
	L.display();

	L.delete_from_end();
	L.delete_from_front();
	cout<<"Front and end element deleted: "<<endl;
	L.display();
	
	
	return 0;
}