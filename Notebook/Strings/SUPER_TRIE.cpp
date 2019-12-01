#include<bits/stdc++.h>
#include<vector>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const short ALP = 26;
typedef struct node *pnode;
struct node{
	int in;
	pnode *m;
};
pnode create(){
	pnode aux = new node;
	aux->in = -1;
	aux->m = new pnode[ALP];
	forn(i, ALP) aux->m[i] = NULL;
	return aux;
}
template<class T>
	class trie{
		private:
			pnode _root, _begin;
			int _size;
			vector<T> _content;
			vector<string> _keys;
		public:
			trie(){
				_root = create();
				_begin = create();
				_begin->m[ALP - 1] = _root;
				_size = 0;
			}
			T &operator[](const string &s){
				int n = s.size(), index;
				pnode act = _root;
				forn(i, n){
					index = s[i] - 'a';
					if(act->m[index] == NULL) act->m[index] = create();
					act = act->m[index];
				}
				if(act->in == -1){
					act->in = _size++;
					_content.push_back(T());
					_keys.push_back(s);
				}
				return _content[act->in];
			}
			int size(){ return _size; }
			struct iterator{
				private:
					vector<pair<pnode, int> > _travel;
					trie *_owner;
				public:
					bool operator++(){
						if(!_travel.size()) return false;
						pair<pnode, int> *state = &_travel.back();
						pnode act = state->first, sig;
						int index = state->second + 1;
						while(index < ALP && act->m[index] == NULL) index++;
						if(index == ALP){
							_travel.pop_back();
							return ++*this;
						}
						state->second = index;
						sig = act->m[index];
						_travel.push_back({sig, -1});
						if(sig->in != -1) return true;
						return ++*this;
					}
					iterator(){}
					iterator(trie<T> &t){
						_travel.push_back({t._begin, ALP - 2});
						_owner = &t;
					}
					void init(trie<T> &t){
						_travel.push_back({t._begin, ALP - 2});
						_owner = &t;
					}
					string key(){	return _owner->_keys[_travel.back().first->in]; }
					T &val(){	return _owner->_content[_travel.back().first->in]; }
			};
	};
int main(){
	trie<int> t;
	t["hoy"] = 1;
	t["hola"] = 3;
	t["hoz"] = 5;
	t["arbol"] = 7;
	t["planta"] = 9;
	for(trie<int>::iterator it(t); ++it;) cout<<it.key()<<": "<<it.val()<<endl;
	cout<<t.size()<<endl;
	return 0;
}
