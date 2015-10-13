#ifndef LIST_C_H
#define LIST_C_H
#include <iostream>
using namespace std;

template <typename Object>
class List{
	private:
		struct Node
		{
			Object data;
			Node* prev;
			Node* next;
			Node(const Object& d = Object() , Node* p = NULL , Node* n = NULL): data(d),prev(p),next(n){}
		};
	public:
		List(){
			init();
		}
		List(const List& rhs){
			init();
			*this = rhs;
		}
		~List(){

		}
		const List& operator=(const List& rhs){
			if(this == &rhs){
				return *this;
			}
			
		}
		int size() const{
			return theSize;
		}
		bool empty() const{
			return (size() == 0);
		}
		void clear(){

		}
	public:
		class const_iterator{

		};
		class iterator:const_iterator{

		};
	private:
		int theSize;
		Node* head;
		Node* tail;

		void init(){
			theSize = 0;
			head = new Node;
			tail = new Node;
			head->next = tail;
			tail->prev = head;
		}
}
#endif    //LIST_C_H