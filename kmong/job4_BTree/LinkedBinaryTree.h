#ifndef _LBINH
#define _LBINH
#include <list>

//template<typename T>
typedef int Elem;
class LinkedBinaryTree{

	protected:
		struct Node{
		//	T elt;
			Elem elt;
			Node* p,* l,* r;
			Node(): elt(0), p(0), l(0), r(0){}
		};

	public:
		class Position {
			private:
				Node* v;

			public:
				Position(Node* _v) : v(_v) {}
		//		T& operator*() const { // const added
			Elem& operator*() {
					return v->elt;
				}
				Position left() const {return v->l;}
				Position right() const {return v->r;}
				Position parent() const {return v->p;}
				bool isRoot() const {return !v->p;}
				bool isNull() const {return v==0;}  //isNull added. this replace STL list::end()
				bool isExternal() const {return !v->l && !v->r;} 
				friend class LinkedBinaryTree;
		};
		typedef std::list<Position> PositionList;

	public:
		LinkedBinaryTree();
		int size() const;
		bool empty() const;
		Position root() const;
		PositionList positions() const;
		void addRoot();
		void expandExternal(const Position& p);
		Position removeAboveExternal(const Position& p);
	protected:
		void preorder(Node* v, PositionList& pl) const;
	private:
		Node* _root;
		int n;
};

LinkedBinaryTree::LinkedBinaryTree() : _root(0), n(0) {}
int LinkedBinaryTree::size() const { return n; }
bool LinkedBinaryTree::empty() const {return size() ==0; }
LinkedBinaryTree::Position LinkedBinaryTree::root() const {return Position(_root); }
void LinkedBinaryTree::addRoot() {_root = new Node; n=1;}

void LinkedBinaryTree::expandExternal(const Position& po){ //make external to internal node
	Node* v = po.v;
	v->l = new Node;
	v->l->p = v;
	v->r = new Node;
	v->r->p = v;
	n+=2;
}

//why this func doesn't chk node "w" is internal or externaL???.... i dont understand
//without it, this func will make mass of error...(PJT)
LinkedBinaryTree::Position LinkedBinaryTree::
removeAboveExternal(const Position &po){  //remove external node with its parent

	Node* w = po.v; Node *v = w->p;
	if (w->l || w->r) ;
	Node* sib = (w==v->l?v->r:v->l); //"sib" parent another child
	if ( v == _root) { _root = sib; sib->p =0; } //if parent is root, then sib become root
	else {   //else sib becomes grandparent "gp"'s child. 
		Node* gp  = v->p;
		if ( v == gp->l) gp->l= sib; //chk where is "parent"'s position to "gp"
		else gp->r = sib;               //and then replace "parent"s position with "sib"
	}
	delete w; delete v;              //and then we free it. external node and its parent
	n-=2;
	return Position(sib);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const{
	PositionList pl;
	preorder(_root, pl);
	return PositionList(pl);
}

void LinkedBinaryTree::preorder(Node* v, PositionList& pl) const{
	pl.push_back(Position(v));
	if (v->l) preorder(v->l, pl);
	if (v->r) preorder(v->r, pl);
}

#endif 
