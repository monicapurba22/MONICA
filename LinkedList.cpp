#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//linkedlist node menggunakan class

using namespace std;

class Node{
	public:
		char id;
		Node *next;
		
		Node(){
			next = NULL;
		}
};

class LinkedList{
	public:
		Node *head;
		Node *tail;
		
		LinkedList (){
			head = tail = NULL;
		}
		//ini adalah cara cepat untuk mendapatkan node
		void insertToHead(char data) {
			Node *node = new Node();
			node->id = data;
			
			Node *tmp = head;
			head = node;
			node->next = tmp;
		}
		
		void insertToTail(char data){
			Node *node = new Node();
			node->id = data;
			
			tail->next = node;
			tail = node;
		}	
		void travesal(){
		/*	if (head!=NULL){
				Node *tmp = head;
				do{
					cout << tmp->id<<"->";
					tmp = tmp->next;
				}while (tmp != NULL);
			}*/
			
		}
		
		void insertDataAfter(char data, char after))
			if (head==NULL)
				cout << "ERROR : LinkedList Empty" << endl;
			else if (tail->id==after){
				insertToTail(data);
			} else {
				
				Node *tmp = he4ad;
				
				while (tmp->id!=after && tmp!=NULL){
					tmp = tmp->next
				}
				if(tmp==NULL)
					cout << "ERROR : "
			}
		}
};

int main(int argc, char** argv) {
	//ini cara lebih terperinci
		LinkedList *list1 = new LinkedList();
	
	Node *node1 = new Node();
	node1->id = 'A';
	//outputnya akan tetap NULL karena nextnya adalah NULL
	list1->head = node1;
	list1->tail = node1;
	
	Node *node2 = new Node();
	node2->id = 'B';
	
	list1->head->next = node2;
	list1->tail = node2;
	
	
	cout << list1->head->id << endl;
//	cout << list1->head->next->id; (untuk akses b dari Head)
	cout << list1->tail->id << endl;
	//outputnya akan 0 atau NULL
	
	//cout << list1;
	//outputnya yang ditunjuk akan abstrak
	
	Node *nodeX = new Node();
	nodeX->id = 'X';
	
	Node *tmp = list1->head->next;
	list1->head = nodeX;
	nodeX->next = tmp;
	
	//contohnya
	list1->insertToTail('C');
	list1->insertToTail('D');
	
	list1->insertToHead('Y');
	
	
	cout << list1->head->id << endl;
	cout << list1->tail->id ;

	

	return 0;
}
