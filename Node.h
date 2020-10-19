#pragma once
#include <iostream>
class Node
{
public:

	int data;
	Node* next;

	// Function to print elements in the list
	static void printList(Node* n) {
		while (n != NULL) {
			std::cout << n->data << " | ";
			n = n->next;
		}
		std::cout << std::endl;
	}

	// Function to add a new element to the start of the list
	static void addToStart(Node** headReference, int newData) {
		Node* newNode = new Node();		// initialize a new node
		newNode->data = newData;		// pass new data to the new node
		newNode->next = *headReference;	// make previous head the next node after a new one
		*headReference = newNode;		// make the new node the head of the list

	}

	// Function to add a new element after a specified element in the list
	static void addAfter(Node* afterWhat, int newData) {
		Node* newNode = new Node();		// initialize a new node
		newNode->data = newData;		// pass new data to the new node
		newNode->next = afterWhat->next;// make previous nodes' next element new nodes' next element
		afterWhat->next = newNode;		// make new node the next element of the previous element
	}

	// Function to add a new element to the end of the list
	static void addToEnd(Node** endingElement, int newData) {
		Node* newNode = new Node();		// initialize a new node
		Node* end = *endingElement;		// initialize an ending element
		newNode->data = newData;		// pass new data to the new node
		newNode->next = NULL;			// make new nodes' next element as NULL

		if (*endingElement == NULL)	{	// if ending element is NULL, (empty list), we make new node the ending element
			*endingElement = newNode;	// i.e. adding it to the start of our list
			return;
		}

		while (end->next != NULL) {		// else traverse till' the last node
			end = end->next;
		}

		end->next = newNode;			// declare new node as the ending element of our list
		return;
		}

	// Function to delete a number from the list
	static void deleteNode(Node** headElement, int key) {
		Node* temp = *headElement, *previousElement=NULL;	// initialize a new node which stores head element and previous element
		if (temp != NULL && temp->data == key) {		// if the heads' node contains required element
			*headElement = temp->next;					// change heads' element
			free(temp);									// free the heads' element
			return;										// exit
		}

		while (temp != NULL && temp->data != key) {		// search for the key through the list
			previousElement = temp;						// keep track the previous element as well
			temp = temp->next;							// change the current element
		}

		if (temp == NULL) {								// if the key is not in the list, exit
			return;
		}

		previousElement->next = temp->next;				// change previous elements' next part before deleting the key

		free(temp);										// delete the node with the key
	}

	// Function to delete an element at position in the list
	static void deleteAtPosition(Node** headReference, int position) {
		if (headReference == NULL) {	// exit if the list is empty
			return;
		}

		Node* temp = *headReference;		// create a new node to store the head node

		if (position == 0) {			
			*headReference = temp->next;	// change head's reference
			free(temp);						// free old head
			return;
		}

		for (int i = 0; temp != NULL && i < position - 1; i++) {	//find previous node of the node we want to delete
			temp = temp->next;
		}

		if (temp == NULL || temp->next == NULL) {		// if position is more than number of nodes, exit
			return;
		}

		Node* next = temp->next->next;		// store the next node of the node we want to delete

		free(temp->next);		// delete the element
		temp->next = next;		// unlink the deleted node from the list	
	}

	// Function to delete the entire linked list
	static void clearList(Node** headReference) {
		Node* current = *headReference;		// initialize new node as a start of the list
		Node* next = NULL;					// initialize a temporary node to store next element

		while (current != NULL) {			// free elements starting from head
			next = current->next;
			free(current);
			current = next;
		}

		*headReference = NULL;				// nullify the head reference pointer

	}

	// Function to find length of a linked list
	static int getLength(Node* headReference) {
		int cnt = 0;
		while (headReference != NULL) {			// while head is not null
			headReference = headReference->next;// change the head's position
			cnt++;								// increase counter by 1
		}
		return cnt;
	}

	//Function to find out if an element is in the list
	static bool isInTheList(Node* headReference, int key) {
		Node* current = headReference;		// initialize a new node to store the head reference
		while (current != NULL) {			// if current is null, return false
			if (current->data == key) {		// if current is equal to element, return true
				return true;
			}
			current = current->next;		// if not, go right by one
		}
		return false;						// if the element is not present, return false
	}

	// Function to get an element at a specified posititon
	static int getElementAt(Node* headReference, int position) {
		Node* current = headReference;
		int count = 0;					// initialize counter to get to the position

		while (current != NULL) {
			if (count == position) {
				return current->data;	// if position is right, return the element
			}
			count++;					// else increase the counter by 1
			current = current->next;	// change current to the next element
		}

		return 0;						// if the element is not present, return 0 (false)
	}

	// Function to get an element at a specified position from the end of the list
	static int getElementReversedAt(Node* headReference, int position) {
		Node* current = headReference;
		int count = Node::getLength(current) - position -1;

		return Node::getElementAt(current, count);
	}

	// Function to get the middle element from a linked list
	static int getMiddleElement(Node* headReference) {
		Node* current = headReference;
		int count = Node::getLength(current) / 2;

		int element = Node::getElementAt(current, count);
		return element;
	}

	// Function to count how many times we met an element in the list
	static int countElement(Node* headReference, int element) {
		Node* current = headReference;
		int count = 0;
		while (current != NULL) {
			if (current->data == element) {
				count++;
			}
			current = current->next;
		}
		return count;
	}

};

