#ifndef BINTREENETZERO_H
#define BINTREENETZERO_H
#include <iostream>
#include <cstdlib>  // Provides NULL and size_t

namespace NetZeroSpace
{
    template <class Item>
    class binary_tree_node
    {
        public:
        // TYPEDEF
        //typedef Item value_type;
        // CONSTRUCTOR
        binary_tree_node(const Item& init_data = Item(), 
                        binary_tree_node<Item>* init_left = NULL, binary_tree_node<Item>* init_right = NULL)
        { 
            data_field = init_data; 
            left_field = init_left; 
            right_field = init_right;
        }

        // MODIFICATION MEMBER FUNCTIONS
        Item& data( ) { return data_field; }
        binary_tree_node<Item>* left( ) { return left_field; }
        binary_tree_node<Item>* right( ) { return right_field; }
        void set_data(const int& new_data) { data_field = new_data; }
        void set_left(binary_tree_node<Item>* new_left) { left_field = new_left; }
        void set_right(binary_tree_node<Item>* new_right) { right_field = new_right; }

        // CONST MEMBER FUNCTIONS
        const Item& data( ) const { return data_field; }
        const binary_tree_node<Item>* left( ) const { return left_field; }
        const binary_tree_node<Item>* right( ) const { return right_field; }
        bool is_leaf( ) const 
        {
            return (left_field == NULL) && (right_field == NULL); 
        }

    
        private:
        Item data_field;
        binary_tree_node<Item>* left_field;
        binary_tree_node<Item>* right_field;

    };

}

#endif