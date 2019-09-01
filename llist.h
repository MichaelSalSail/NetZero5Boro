#ifndef MAIN_SAVITCH_LIST1_H
#define MAIN_SAVITCH_LIST1_H
#include <cstdlib>
#include <list>
#include <tuple>
#include <iostream>
#include "node.h"

namespace NetZeroSpace
{
    template <class Item>
    class LList
    {
        public:

        //Default constructor and constructor
        LList()
        {
            head_ptr=NULL;
            tail_ptr=NULL;
            list_length=0;
        }
        LList(node<Item>* first, node<Item>* second, std::size_t lengthh)
        {
            head_ptr=first;
            tail_ptr=second;
            list_length=lengthh;
        }

        //setters
        void sethead(node<Item>* first)
        {
            head_ptr=first;
        }
        void settail(node<Item>* second)
        {
            tail_ptr=second;
        }
        void setlength(size_t lengthh)
        {
            list_length=lengthh;
        }

        //getters
        const node<Item>* gethead_ptr()
        {
            return head_ptr;
        }
        const node<Item>* gettail_ptr()
        {
            return tail_ptr;
        }

        //modified functions from the linked list toolkit
        size_t length(const node<Item>* head_ptr)
        {
            size_t result=list_lengT(head_ptr);
            list_length=result;
            return list_length;
        }
        //Added function to print out data in each node
        void printlist(const node<Item>* head_ptr)
        {
            const node<Item>* cursor;
            //std::cout<<"The list contains data ";
            for(cursor=head_ptr; cursor!=NULL;cursor=cursor->link())
            {
                std::cout<<cursor->data()<<"  ";
            }
            std::cout<<"\n";
        }

        //add to end, insert at position P
        void append(const Item& entry);
        void insert(std::size_t position, const Item& entry);

        //find first occurence
        const node<Item>* search(const Item& target);
        const node<Item>* locate(std::size_t position);

        //remove by value, remove all
        bool remove(const Item& target);
        void clear();

        //returns new list
        LList<Item>* copy();

        //additional functions to index into list and overwrite node
        node<Item>* operator[] (std::size_t ind);
        node<Item>& operator = (Item i);

        std::list<std::tuple<Item, int>> frequency(LList<Item> data);

        private:
            node<Item>* head_ptr;
            node<Item>* tail_ptr;
            std::size_t list_length;
    };
}
#endif