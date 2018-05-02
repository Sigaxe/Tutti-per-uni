#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <class T>
class Pila {
	private:
		vector<T> v;
	public:
		Pila() {
			
		}
		Pila(int dim) {
			v.reserve(dim);
		}
		
		int getNElem() {
			return v.size();
		}
		void push(const T& elem) {
			v.push_back(elem);
		}
		T pop() {
			if(!v.empty()) {
				T elem = v.back();
				v.pop_back();
				return elem;
			}
			throw string("Empty stack");
		}
		bool empty() {
			if(v.size() == 0) return true;
			return false;
		}
		
		void stampa(ostream& os) {
			for(int i = 0; i < v.size(); i++) {
				os << v[i] << " ";
			}
			os << endl;
		}
};

template <class T>
ostream& operator<<(ostream& os, Pila<T> p) {
	//Overloading operatore <<
	p.stampa(os);
	return os;
}
