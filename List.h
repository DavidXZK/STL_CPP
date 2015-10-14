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
		iterator begin(){
			return iterator(head->next);
		}
		const_iterator begin() const{
			return const_iterator(head->next);
		}
		iterator end(){
			return iterator(tail);
		}
		const_iterator end() const{
			return const_iterator(tail);
		}
		int size() const{
			return theSize;
		}
		bool empty() const{
			return (size() == 0);
		}
		void clear(){

		}
		Object& front(){
			return *begin();
		}
		const Object& front() const{
			return *begin();
		}
		
	public:
		class const_iterator{
			public:
				const_iterator():current(NULL){}   //构造函数

				const Object& operator*() const{   //取值
					return retrieve();
				}

				const_iterator& operator++(){     //前缀
					current = current->next;
					return *this;
				}
				const_iterator& operator++(int){   //后缀
					const_iterator old = *this;
					++(*this);
					return old;
				}

				bool operator==(const const_iterator &rhs) const{
					return current == rhs.current;
				}
				bool operator!=(const const_iterator &rhs) const{
					return !(*this == rhs);
				}

			protected:
				Node* current;
				Object& retrieve() const{
					return current->data;
				}
				const_iterator(Node*p):current(p){}

		};
		class iterator: public const_iterator{
			public:
				iterator(){}
				Object& operator*(){
					return retrieve();
				}
				const Object& operator*() const{
					return const_iterator::operator*();
				}

				iterator& operator++(){
					current = current->next;
					return *this;
				}

				iterator& operator++(int){
					iterator old = *this;
					++(*this);
					return old;
				}
			protected:
				iterator(Node*p):const_iterator(p){}

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