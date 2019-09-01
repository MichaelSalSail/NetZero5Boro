#ifndef MAIN_SAVITCH_NODE11_H  
#define MAIN_SAVITCH_NODE11_H
#include <cstdlib> // Provides size_t and NULL
#include <map>
#include <iostream>

namespace NetZeroSpace
{
	template <class Item>
    class node
	{
			public:
			// CONSTRUCTOR
			node(const Item& init_data = Item( ),node<Item>* init_link = NULL)
			{ 
				data_field = init_data; link_field = init_link; 
			}
			// Member functions to set the data and link fields:
			void set_data(const Item& new_data) 
			{ 
				data_field = new_data; 
			}
			void set_link(node<Item>* new_link) 
			{ 
				link_field = new_link; 
			}
			// Constant member function to retrieve the current data:
			Item data( ) const 
			{ 
				return data_field; 
			}
			// Two slightly different member functions to retrieve
			// the current link:
			const node<Item>* link( ) const 
			{ 
				return link_field; 
			}
			node<Item>* link( )  	  
			{ 
				return link_field; 
			}
			//implement the assignment operator
			node<Item>& operator = (Item value)
			{
				this->set_data(value);
				node<Item> result1=node<Item>(this->data(),this->link());
				node<Item>& result=result1;
				return result;
			}
			// FUNCTIONS for the linked list toolkit
			std::size_t list_lengT(const node<Item>* head_ptr);
			void list_head_insert(node*& head_ptr, const Item& entry); 
			void list_insert(node<Item>* previous_ptr, const Item& entry);  
			node* list_search(node<Item>* head_ptr, const Item& target);
			const node* list_search(const node<Item>* head_ptr, const Item& target);
			node* list_locate(node<Item>* head_ptr, std::size_t position);
			const node* list_locate(const node<Item>* head_ptr, std::size_t position);
			void list_head_remove(node<Item>*& head_ptr);
			void list_remove(node<Item>* previous_ptr);
			void list_clear(node<Item>*& head_ptr);
			void list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr);
			private:
			Item data_field;
			node<Item>* link_field; 
    };
}

#endif