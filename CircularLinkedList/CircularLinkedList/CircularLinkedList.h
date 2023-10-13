/***************************************************************************
* CircularLinkedList.h
* Defines a circular linked list for demonstration and evaluation purposes 
*	for students at Whitworth University's CS273: Data Structures class.
*	Students are assigned to complete the incomplete definition, in the
*	process exercising their understanding of template classes, pointers,
*	and sequential containers.
* 
* Author: Matthew Bell and CS273
* Co-author: <TODO: PUT YOUR NAME HERE>
* 
* Miscelleneous credits:
* This example is loosely based on an earlier doubly linked list (non-circular)
* developed by the CS faculty @ Whitworth University, particularly Wizard Dr.
* Kent Jones and Wizard Dr. Ed Walker!
*****************************************************************************/


#ifndef CLL_H
#define CLL_H

/****************************************************************************
* We define our own namespace, CS273, so that our circular linked list cannot 
* be confused with anything in namespace std
*****************************************************************************/
namespace CS273 {

/****************************************************************************
* CircLinkedList defines a circular linked list as a list of nodes.
*****************************************************************************/
	template<class T>
	class CircLinkedList {
	private:
#pragma region NodeStruct
		/// <summary>
		/// struct node defines the nodes of which this list consists
		/// </summary>
		struct node {
			node* next; // Pointer to the next node in the list
			node* prev; // Pointer to the previous node in the list
			T data;		// The actual data stored in this node

			/// <summary>
			/// Constructor for node minimally needs data to point to
			/// </summary>
			node(const T& data, node* after = nullptr) : data(data) {
				//If after isn't null, then we need to insert our new node in front
				if (after != nullptr) {
					next = after;
					after->prev->next = this;
					after->prev = this;
				}
			}
		};
	public:
#pragma region Iterator
		/// <summary>
		/// The iterator for our circular linked list acts like a "line manager"
		/// for the class. Access to data stored in the list is mediated entirely
		/// via these iterators. (Note: iterators are public, nodes are private!)
		/// </summary>
		class iterator {
		private:
			CircLinkedList<T>* parent;	// The list this iterator belongs to
			node* cur;					//The current node this iterator points to

			/// <summary>
			/// The iterator for CircLinkedList has access to CircLinkedList's private
			/// data.
			/// </summary>
			friend class CircLinkedList<T>;
		};

	};
}
#endif
