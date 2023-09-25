#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

	private:
		// miembros privados
		T* arr;
		int max;
		int n;
		static const int MINSIZE;

	public:
		// miembros públicos, incluidos los heredados de List<T>
		void insert(int pos, T e){
			if(pos <0 || pos>size()-1)
				throw std::out_of_range("Posicion no valida");
			arr[pos] = e;
		}

		void append(T e){
			insert(max-1, e);
		}

		void prepend(T e){
			insert(0, e);
		}
		
		T remove(int pos){
			if(pos <0 || pos>size()-1)
				throw std::out_of_range("Posicion no valida");
			T aux=arr[pos];
			delete arr[pos];
			return aux;			
		}

		T get(int pos){
			if(pos <0 || pos>size()-1)
				throw std::out_of_range("Posicion no valida");
			return arr[pos];
		}
		
		int search(T e){
			for(int i=0; i<n; i++){
				if(arr[i]== e)
					return i;
			}
			return -1;
		}
		
		bool empty(){ 
			return n==0; 
		}
		
		int size(){
			return max;
		}
		


		
		ListArray();
		~ListArray(){
			delete[] arr;
		}


		T operator[](int pos){
			return get(pos);
		}
		
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
			out << "Instancia 0: " << list.get(0);
			return out;
		}

		void resize(int new_size){
			T* new_arr = new T[new_size];
			for(int i=0; i<n; i++){
				new_arr[i] = arr[i];
			}
			delete[] arr;
			arr = new_arr;
			max = new_size;
		}
};


