#include <ostream>

template <typename T> 
class Node {
	public:
		// miembros públicos
		T data;
		Node<T>* next;
		
		Node(T data, Node<T>* next=nullptr): data{data}, next{next} {}


		friend std::ostream& operator<<(std::ostream &out, const Node<T> &node){
			out << "Data --> " << node.data << std::endl;
			return out;	
		}

		void insert(int pos, T e){
			if(pos < size()){
				Node n = Node(e, nullptr);
				if(pos != 0){// inserta entre dos nodos
					int c=0;
					Node<T>* prev;
					while(next != nullptr && c < pos){//busca el puntero del nodo anterior
						next = next->next;
						c++;
						prev = next;
					}
					n->next = prev;
					prev = n;
				}else{
					n->next = next;
				}
			}
		}

		void append(T e){
			insert(0, e);
		}

		void prepend(T e){
			insert(size()-1, e);
		}

		T remove(int pos){
			if(pos < size()){
				if(pos != 0){ // borra un nodo entre otro node
					int c=0;
					Node<T>* prev;
					while(next != nullptr && c < pos){
						next = next->next;
						c++;
						prev=next;
					}
					prev=next->next;
				
				}
				delete this;
				
				
			}
		}

		T get(int pos){
			if(pos >= 0){
				int c=0;
				while(pos < size() && next != nullptr && c < pos){
					data = next.data;
					next = next->next;
					c++;		
				}
				return data;
			}
			throw std::invalid_argument("Posicion no valida");
		}

		int search(T e){
			int c=0;
			while(next != nullptr){
				if(e == data){
					return c;
				}
				next = next->next;
				c++;
			}
			return -1;
		}

		bool empty(){
			return data == NULL;
		}

		int size(){
			int c=0;
			while(next != nullptr){
				next = data->next;
				c++;
			}
			return c;
		}

};
