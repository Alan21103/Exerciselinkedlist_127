#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
	Node* prev;
};

class CircularLinkedList {
private:
	Node* LAST;

public:
	CircularLinkedList() {
		LAST = NULL;
	}

	void addNode();
	bool search(int rollno, Node** previous, Node** current);
	bool listEmpty();
	bool delNode();
	void traverse();
};

void CircularLinkedList::addNode() { //  Add Method AddNode
	int rollNumber;
	string name;
	cout << "\nEnter the roll number of the student: ";
	cin >> rollNumber;
	cout << "\nEnter the name of the student: ";
	cin >> name;
	Node* newNode = new Node();		// step 1
	newNode->rollNumber = rollNumber;			// step 2
	newNode->name = name;				// step 2

	/*insert a node in the beginning of a doubly - linked list*/
	if (LAST == NULL || rollNumber <= LAST->rollNumber) {
		if (LAST != NULL && rollNumber == LAST->rollNumber) {
			cout << "\nDuplicate number not allowed" << endl;
			return;
		}
		newNode->next = LAST;	// step 3
		if (LAST != NULL)
			LAST->next = newNode;	// step 4
		newNode->next = NULL;		// step 5
		LAST = newNode;			// step 6
		return;
	}

	/*Inserting a Node between two nodes in the list*/
	Node* current = LAST;	//step 1a
	Node* previous = NULL;	//step 1b
	while (current->next != NULL && current->next->rollNumber < rollNumber)  // step 1c
	{
		previous = current;
		current = current->next;
	}

	if (current->next != NULL && rollNumber == current->next->rollNumber) {
		cout << "\nDuplicate roll number not allowed" << endl;
		return;
	}

	newNode->next = previous->next;	//step 4
	newNode->next = current->next;		// step 5
	if (LAST != NULL)
		current->next = LAST;		//step 6
	current->next = newNode;			// step 7
}

bool CircularLinkedList::search(int rollno, Node** Saputra, Node** Rosihan) {
	*Saputra = LAST->next;
	*Rosihan = LAST->next;

	while (*Rosihan != LAST) {
		if (rollno == (*Rosihan)->rollNumber) {
			return true;
		}
		*Saputra = *Rosihan;
		*Rosihan = (*Rosihan)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}

bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}

bool CircularLinkedList::delNode() {
	Node* previous, * current;
	previous = current = NULL;
	if (search(rollNumber, &previous, &current) == false)
		return false;
	if (current->next != NULL)
		current->next->prev = previous;					//step 2
	if (previous != NULL)
		previous->next = current->next;					// step 3
	else
		LAST = current->next;

	delete current;	//step 4
	return true;
}
void CircularLinkedList::traverse(){
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* currentNode = LAST->next;
		while (currentNode != LAST) {
			cout << currentNode->rollNumber << " " << currentNode->name << endl;
			currentNode = currentNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}

int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
			}
			case '2': {
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}