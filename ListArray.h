#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size);

    public:
    	ListArray(){
	}
	~ListArray(){
	}
	T operator[](int pos){
		return get(pos);
	}
	friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		return out;
	}

	void insert(int pos, T e) override{
	}
        void append(T e) override{
	}
        void prepend(T e) override{
	}
        T remove(int pos) override{
		return 0;
	}
        T get(int pos) override{
		return 0;
	}
        int search(T e) override{
		return 0;
	}
        bool empty() override{
		return 0;
	}
        int size() override{
		return 0;
	} 	
};
