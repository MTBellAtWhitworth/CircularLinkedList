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
#pragma endregion

		node* head;		// the "first" item in the list
		node* tail;		// the "last" item in the list
		int num_items;	// keeps track of the total number of items

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
		public:
			iterator(CircLinkedList<T>* parent = nullptr, node* cur = nullptr) :
				parent(parent), cur(cur) {}

			///
			/// Overloaded operators for advancing and for moving backwarts
			/// 
			iterator& operator++() {
				cur = cur->next;
				return *this;
			}
			iterator& operator--() {
				cur = cur->prev;
				return *this;
			}

			///
			/// Overloaded dereferencing operator for treating an iterator like
			/// a pointer
			/// 
			T& operator*() {
				return cur->data;
			}

			///
			/// Overloaded == and != to allow for comparing two iterators
			/// 
			bool operator==(const iterator& alt) {
				return (cur == alt.cur);
			}
			bool operator!=(const iterator& alt) {
				return cur != alt.cur;
			}
		};
#pragma endregion

		///
		/// Constructor for the list
		/// 
		CircLinkedList<T>() : head(nullptr), tail(nullptr), num_items(0) {}

#pragma region RuleOfThree
		///
		/// Recall: the Rule of Three requires that we define a destructor,
		/// a copy constructor, and an overloaded assignment operator!
		/// 
		/// First, the destructor
		virtual ~CircLinkedList<T>() {
			//March through the list destroying the whole thing!
			node* byebye = head;
			while (byebye) {
				node* forever = byebye;
				byebye = byebye->next;
				delete forever;
			}
		}
		/// <summary>
		/// The copy constructor makes a deep copy
		/// </summary>
		CircLinkedList<T>(const CircLinkedList<T>& alt) :
			head(nullptr), tail(nullptr), num_items(0) {
			
			node* n = alt.head;
			int items_copied = 0;
			while (items_copied < alt.num_items) {
				//TODO
			}
		}
	};
};
#endif
