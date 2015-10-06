#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

template <typename Object>
class Vector
{
	public:
		Vector(int initSize = 0): theSize(initSize),theCapcity(initSize + SPARE_CAPACITY){
			objects = new Object[theCapcity];
		}
		~Vector(){
			delete[] objects;
		}
		Vector(const Vector& rhs): objects(NULL){    // so question here.why initialized objects here? & operator= call here
			operator = (rhs);
		}
		const Vector& operator = (const Vector& rhs){
			if(this != rhs){
				delete [] objects;
				theSize = rhs.size();
				theCapcity = rhs.capcity();
				objects = new Object[theCapcity];
				for(int i = 0; i < theSize; i ++){
					objects[i] = rhs.objects[i];
				}
			}
			return *this;
		}
		void resize(int newsize){
			if(newsize > theCapcity){
				reserve(2*newsize + 1);
			}
			theSize = newsize;
		}
		void reserve(int newCapacity){
			if(newCapacity < theCapcity){
				return;
			}
			Object* oldObject = objects;
			objects = new Object[newCapacity];
			for(int i = 0;i < theSize;i ++){
				objects[i] = oldObject[i];
			}
			theCapcity = newCapacity;
			delete[] oldObject; 
		}
		int size() const {
			return theSize;
		}
		int capcity() const {
			return theCapcity;
		}
		bool empty() const {
			return (size()==0);
		}
		Object& operator [] (int index){
			return objects[index];
		}
		const Object& operator [] (int index) const{
			return objects[index];
		}
		void push_back(const Object& object){
			if(theSize == theCapcity){
				reserve( theCapcity * 2 + 1 );
			}
			objects[theSize ++] = object;
		}
		void pop_back(){
			theSize --;
		}
		const Object& back() const{
			return objects[theSize-1];
		} 
		enum { SPARE_CAPACITY = 16 };

	private:
		int theSize;
		int theCapcity;
		Object *objects;
};
#endif //VECTOR_H