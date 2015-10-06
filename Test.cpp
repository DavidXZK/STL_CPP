#include "Vector.h"

int main(){
	Vector<int> vector_C;
	for(int i = 0; i < 100;i ++){
		vector_C.push_back(i);
	}
	for(int i = 0; i < 100;i ++){
		cout<<i<<" "<<vector_C[i]<<endl;
	}
	return 0;
}