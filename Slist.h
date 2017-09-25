#pragma once

using namespace std;

class Snode {
public:
	Snode();
	Snode(int num);
	int getVal();
	Snode* getNext();
	void setNext(Snode* tnode);
private:
	int value;
	Snode* next;
	friend class Slist;
};
Snode::Snode()
{
	next = NULL;
}
Snode::Snode(int num)
{
	value = num;
	next = NULL;
}
inline int Snode::getVal()
{
	return value;
}
inline Snode * Snode::getNext()
{
	return next;
}
inline void Snode::setNext(Snode * tnode)
{
	next = tnode;
}

class Slist {
public:
	Slist();
	~Slist();
	void removeFront();
	bool empty() const;
	void insertFront(int num);
	void insertFrontNode(Snode* temp);
	void insertBack(int num);
	Snode* resetCur();
	Snode* getHead();
	void printList();
	void setHead(Snode* temp);
	void selectionSort_hard();
	void selectionSort_easy(Slist* sortedList);
	int greatestVal(Snode*n);
	Snode* greatestNode(Snode * start);
	Snode* removeNext(Snode* before);
	Snode* swapNode(Snode* current, Snode * beforeMin, Snode * min); //doesn't work
	
private:
	Snode* head;
	Snode* cur;
};
Slist::Slist()
{
	head = NULL;
	cur = head;
}
Slist::~Slist()
{
	while (!empty())
		removeFront();
}
void Slist::removeFront() {
	Snode* temp = head;
	head = temp->next;
	delete temp;
}
bool Slist::empty() const
{
	if (head)
		return true;
	else return false;
}
void Slist::insertFront(int num)
{
	Snode* temp = new Snode(num);
	temp->next = head;
	head = temp;
}
inline void Slist::insertFrontNode(Snode * temp)
{
	temp->next = head;
	head = temp;
}
inline void Slist::insertBack(int num)
{
	Snode * temp = new Snode(num);
	if (cur == NULL) {
		cur = temp;
		head = temp;
	}
	else {
		cur->next = temp;
		cur = temp;
	}
}
inline Snode * Slist::resetCur()
{
	return cur = head;
}
inline Snode * Slist::getHead()
{
	return head;
}
inline void Slist::printList()
{
	Snode* temp = head;
	while (temp!=NULL) {
		cout << temp->value << ' ';
		temp = temp->next;
	}
	cout << endl;
}
inline void Slist::setHead(Snode * temp)
{
	head = temp;
}
inline Snode * Slist::swapNode(Snode* current, Snode * beforeMin, Snode * min)
{

	//create a circular list somewhere. Fix
	//if its the head node, how to switch?
	//if it's the end node, how to switch?
	//if it's the middle node, how to switch?
	//if they're next to each other, just switch the node
	
	if (current == beforeMin)
	{
		current->next=min->next;
		min->next= current;
		return min;
	}
	else {
		Snode* temp = current->next;
		beforeMin->setNext(current);
		current->next=min->next;
		min->next=temp;
		return min;
	}
}
inline int Slist::greatestVal(Snode * n)
{
	if (n->next == NULL) { return n->value; }
	else {
		int tmp = greatestVal(n->next);
		if (tmp > n->value)
			return tmp;
		else return n->value;
	}
}
inline void Slist::selectionSort_hard()
{
	if (head == NULL)
		return ;

	Snode* marker = head;
	Snode* beforeMarker = NULL;
	Snode* pointer = NULL;
	Snode* beforeMin = NULL;
	//selection sort
	for (marker = head; marker != NULL && marker->next != NULL;) {
		Snode* min = marker;
		for (pointer = marker; pointer->next != NULL; pointer = pointer->next) {
			if (pointer->next->value < min->value) {
				min = pointer->next;
				beforeMin = pointer;
			}
		}
		Snode* temp = marker;
		marker = marker->next;

		//if min is temp (current head) then beforeMarker=min. Don't swap.
		//otherwise, swap
		if (min != temp) {
			if (min == marker) {                     //if it's next to tempHead
				temp->next = min->next;
				min->next = temp;
			}
			else {
				beforeMin->next = temp;          //if not next to tempHead
				temp->next = min->next;
				min->next = marker;
			}
			if (beforeMarker != NULL)               //don't swap if it's first time swap
				beforeMarker->next = min;
			if (head == temp)						//first time swap
				head = min;
		}
		beforeMarker = min;
		this->printList();
		/*cout << "marker " << marker->value << endl;
		cout << "beforeMarker " << beforeMarker->value << endl;
		cout << "pointer " << pointer->value << endl;
		cout << "beforeMin " << beforeMin->value << endl;*/


	}
	/*problem: if min is a head, swap occur, but head is omitted and algo skip it
	if min is a head,  sometime head.next is omitted
	if min is duplicate, and duplicate is head, head is omitted
	after swap, sometime head is omitted. But the list is ok

	if the tail.next of sorted list is sorted, it will skip over, but something keeps swapping it in next run.
	*/
}
inline Snode * Slist::greatestNode(Snode* start)
{
	Snode* tmp = start;
	Snode* beforeMax = start;
	int max = start->value;
	while (tmp->next != NULL) {
		if (tmp->next->value > max) {
			max = tmp->next->value;
			beforeMax = tmp;
		}
		tmp = tmp->next;
	}
	return beforeMax;
}
inline void Slist::selectionSort_easy(Slist * sortedList)
{	
	//find the largest node. Remove it. Then insert at the front of the other list.
	//Result: an ascending list.
	//Problem: this is not selection sort
	while (head != NULL){	
		//insertFront, that node is the new head
		Snode* temp = head;
		Snode*maxNode = temp;
		Snode*beforeMax = temp;
		int max = temp->value;

		//find largest (keep track of beforeMax and node itself)
		while (temp->next != NULL) {
			if (temp->next->value > max) {
				beforeMax = temp;
				max = temp->next->value;
				maxNode = temp->next;
			}
			temp = temp->next;
		}

		//remove largest
		if (maxNode == head && maxNode->next == NULL) {
			sortedList->insertFrontNode(maxNode);
			head = NULL;
			continue;
		}
		if (maxNode == head) {
			head = maxNode->next;
		}
		else {
			beforeMax->next = maxNode->next;
		}

		maxNode->next = NULL;
		//insert node to other list
		sortedList->insertFrontNode(maxNode);
		sortedList->printList();
	}
}
inline Snode* Slist::removeNext(Snode * before)
{
	Snode*temp = before->next;
	before->next = before->next->next;
	return temp;
}


