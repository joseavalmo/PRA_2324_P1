#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

    private:
	    Node<T>* first;
	    int n;

    public:
	    ListLinked(){
	    first = nullptr;
	    n = 0;
	    }

	    ~ListLinked(){
		    for(int i=0; i < size(); i++){
		    Node<T>** aux = first->next;
		    delete first;
		    first = aux;
		    }
	    }

	    T operator[](int pos){
		    if(pos < 0 || pos > size()-1)
			    throw std::out_of_range("sobrecarga[]");
		    else
			    return get(pos);
	    }

	    friend std::ostream& operator<<(std::ostream &out, const ListLinked<T> &list){
		    for(int i=0; i < list.n; i++){
		    out << list.data << " ";
		    }
		    return out;
	    }

	    void insert(int pos, T e) override{
		    if(pos < 0 || pos > size())
			    throw std::out_of_range("Posicion Invalida");
		    else{
		    Node<T>* aux;
		    aux = new Node(e, std::next=Node(pos-1)->next);
		    Node(pos-1)->next = aux;
		    n++;
		    }
	    }

	    void append(T e) override{
		    Node<T>** aux = first->next;
		    first = new Node(e, std::next=aux);
		    n++;
	    }

	    void prepend(T e) override{
		    Node(size()-1)->next = new Node(e, std::next=nullptr);
	    }

	    T remove(int pos) override{
		    if(pos < 0 || pos > size())
                            throw std::out_of_range("Posicion Invalida");
                    else{
			    Node<T>** aux = Node(pos)->next;
			    Node<T>** prev = Node(pos-1);
			    Node(pos-1)->next = aux;
			    prev = aux;
			    aux = aux->next;
			    delete Node(pos);
			    n--;
		    }
	    }

	    T get(int pos) override{
		    if(pos < 0 || pos > size())
                            throw std::out_of_range("Posicion Invalida");
                    else{
		    return Node(pos).data;
		    }
	    }

	    int search(T e) override{
		    for(int i=0; i < size()-1; i++){
			    if (Node(i).data == e)
				    return i;
		    }
		    return -1;
	    }

	    bool empty() override{
		    if (n == 0)
			    return true;
		    else
			    return false;
	    }

	    int size() override{
	    return n;
	    }

};
