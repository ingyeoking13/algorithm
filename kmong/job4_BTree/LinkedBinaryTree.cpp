#include "LinkedBinaryTree.h"

LinkedBinaryTree::LinkedBinaryTree() : _root(NULL), n(0) {}
int LinkedBinaryTree::size() const { return n; }
bool LinkedBinaryTree::empty() const {return size() ==0; }
LinkedBinaryTree::Position LinkedBinaryTree::root() const {return Positon(_root); }
void LinkedBinaryTree::addRoot() {_root = new Node; n=1}

void LinkedBinaryTree::expandExternal(const Position& po){ //make external to internal node
	Node* v = po.v;
	v->l = new Node;
	v->l->p = v;
	v->r = new Node;
	v->r-> = v;
	n+=2;
}

//why this func doesn't chk node "w" is internal or externaL???.... i dont understand
//without it, this func will make mass of error...
LinkedBinaryTree::Position LinkedBinaryTree::
removeAboveExternal(const Positon &po){  //remove external node with its parent
	Node* w = po.v; Node *v = w->p;
	Node* sib = (w==v->l?v->r:v->l); //"sib" parent another child
	if ( v == _root) { _root = sib; sib->p =0; } //if parent is root, then sib become root
	else {   //else sib becomes grandparent "gp"'s child. 
		Node* gp  = v->p;
		if ( v == gp->l) gp->left = sib; //chk where is "parent"'s position to "gp"
		else gp->r = sib;               //and then replace "parent"s position with "sib"
	}
	delete w; delete v;              //and then we free it. external node and its parent
	n-=2;
	return Position(sib);
}

LinkedBinaryTree::PositionList LinkedBinaryTree::positions() const{
	PositionList pl;
	preorder(_root, pl);
	return PositionsList(pl);
}

void LinkedBinaryTree::predorder(Node* v, PositionList& pl) const{
	pl.push_back(Position(v));
	if (v->l) preorder(v->l, pl);
	if (v->r) preorder(v->r, pl);
}
