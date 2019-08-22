#include "node.h"
#include <cassert>
#include <cstdlib>

namespace NetZeroSpace
{
    template <class Item>
    std::size_t node<Item>::list_lengT(const node<Item>* head_ptr)
    {
        // Library facilities used: cstdlib
        const node<Item>* cursor;
        std::size_t answer = 0;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            ++answer;
        return answer;
    };
    template <class Item>
    void node<Item>::list_head_insert(node<Item>*& head_ptr, const Item& entry)
    {
	    head_ptr = new node<Item>(entry, head_ptr);
    };
    template <class Item>
    void node<Item>::list_insert(node<Item>* previous_ptr, const Item& entry) 
    {
        node<Item> *insert_ptr;
        insert_ptr = new node(entry, previous_ptr->link( ));
        previous_ptr->set_link(insert_ptr);
    };
    template <class Item>
    node<Item>* node<Item>::list_search(node* head_ptr, const Item& target) 
    {
        node<Item> *cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        return NULL;
    }
    template <class Item>
    const node<Item>* node<Item>::list_search(const node<Item>* head_ptr, const Item& target) 
    // Library facilities used: cstdlib
    {
        const node<Item>* cursor;
        for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
            if (target == cursor->data( ))
                return cursor;
        return NULL;
    };
    template <class Item>
    node<Item>* node<Item>::list_locate(node<Item>* head_ptr, std::size_t position) 
    // Library facilities used: cassert, cstdlib
    {
        node<Item>* cursor;
        std::size_t i;
        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link( );
        return cursor;
    };
    template <class Item>
    const node<Item>* node<Item>::list_locate(const node<Item>* head_ptr, std::size_t position) 
    // Library facilities used: cassert, cstdlib
    {
        const node<Item>* cursor;
        size_t i;
        assert (0 < position);
        cursor = head_ptr;
        for (i = 1; (i < position) && (cursor != NULL); i++)
            cursor = cursor->link( );
        return cursor;
    };
    template <class Item>
    void node<Item>::list_head_remove(node<Item>*& head_ptr)
    {
        node *remove_ptr;
        remove_ptr = head_ptr;
        head_ptr = head_ptr->link( );
        delete remove_ptr;
    };
    template <class Item>
    void node<Item>::list_remove(node<Item>* previous_ptr)
    {
	    node<Item>* remove_ptr;
	    remove_ptr = previous_ptr->link( );
	    previous_ptr->set_link( remove_ptr->link( ) );
	    delete remove_ptr;
    };
    template <class Item>
    void node<Item>::list_clear(node<Item>*& head_ptr)
    // Library facilities used: cstdlib
    {
	    while (head_ptr != NULL)
	        list_head_remove(head_ptr);
    };
    template <class Item>
    void node<Item>::list_copy(const node<Item>* source_ptr, node<Item>*& head_ptr, node<Item>*& tail_ptr) 
    // Library facilities used: cstdlib
    {
	    head_ptr = NULL;
	    tail_ptr = NULL;
	    // Handle the case of the empty list.
	    if (source_ptr == NULL)
	        return;
	    // Make the head node for the newly created list, and put data in it.
	    list_head_insert(head_ptr, source_ptr->data( ));
	    tail_ptr = head_ptr;
	    // Copy the rest of the nodes one at a time, adding at the tail of new list.
	    source_ptr = source_ptr->link( ); 
	    while (source_ptr != NULL)
	    {
	        list_insert(tail_ptr, source_ptr->data( ));
	        tail_ptr = tail_ptr->link( );
	        source_ptr = source_ptr->link( );
	    }
	};
}