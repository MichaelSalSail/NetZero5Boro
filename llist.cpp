#include "LList.h"
#include "node.h"

namespace NetZeroSpace
{
    template <class Item>
    void LList<Item>::append(const Item& entry)
    {
        node<Item>* toend=new node<Item>(entry);
        tail_ptr->set_link(toend);
        tail_ptr=toend;
        list_length++;
    };
    template <class Item>
    void LList<Item>::insert(std::size_t position, const Item& entry)
    {
        node<Item>* previous;
        node<Item>* insert_ptr;
        if(position>list_length||position<1)
        {
            throw std::out_of_range(std::string("The position is not available.\n"));
        }
        else if(position==1)
        {
            node<Item>* begin=new node<Item>(entry,head_ptr);
            head_ptr=begin;
            list_length++;
        }
        else if(position==list_length)
        {
            node<Item>* toend=new node<Item>(entry);
            tail_ptr->set_link(toend);
            tail_ptr=toend;
            list_length++;
        }
        else
        {
            node<Item>* cursor;
            int counter=0;
            for(cursor=head_ptr;cursor!=NULL; cursor=cursor->link())
            {
                counter++;
                if(counter==(position-1))
                {
                    previous=cursor;
                }
                if(counter==position)
                {
                    insert_ptr=new node<Item>(entry,cursor);
                }
            }
            previous->set_link(insert_ptr);
        }
    };
    template <class Item>
    const node<Item>* LList<Item>::search(const Item& target)
    {
        const node<Item>* cursor;
        for(cursor=head_ptr; cursor !=NULL; cursor=cursor->link())
        {
            if(cursor->data()==target)
            {
                return cursor;
            }
        }
        return NULL;
    };
    template <class Item>
    const node<Item>* LList<Item>::locate(std::size_t position)
    {
        if(position>list_length||position<1)
            return NULL;
        else
        {
            const node<Item>* cursor;
            int counter=0;
            for(cursor=head_ptr; cursor!=NULL; cursor=cursor->link())
            {
                counter++;
                if(counter==position)
                    return cursor;
            }
        }
        
    };
    template <class Item>
    //remove by value, remove all
    bool LList<Item>::remove(const Item& target)
    {
        bool result=false;
        node<Item>* remove_ptr;
        int counter=0;
        int counter2=0;
        int itevenexist=0;
        node<Item>* cursor;
        for(cursor=head_ptr;cursor!=NULL;cursor=cursor->link())
        {
            counter++;
            if(cursor->data()==target)
            {
                itevenexist=100;
                break;
            }
        }
        if(itevenexist==0)
        {
            std::cout<<"Your playing tricks input not found.\n";
            return result;
        }
        for(cursor=head_ptr;cursor!=NULL;cursor=cursor->link())
        {
            counter2++;
            if(counter2==(counter-1))
            {
                remove_ptr=cursor->link();
                cursor->set_link(remove_ptr->link());
                delete remove_ptr;
                result=true;
                list_length--;
                break;
            }
        }
        return result;
    };
    template <class Item>
    void LList<Item>::clear()
    {
        while(head_ptr!=NULL)
        {
            list_head_remove(head_ptr);
            list_length--;
        }
    };
    template <class Item>
    LList<Item>* LList<Item>::copy()
    {
        LList<Item>* result=new LList<Item>(head_ptr,tail_ptr,list_length);
        return result;
    };
    template <class Item>
	node<Item>* LList<Item>::operator[] (size_t ind)
	{
		if(ind>list_length||ind<0)
		{
			return NULL;
		}
		else
		{
			node<Item>* cursor;
			int counter=0;
			for (cursor = head_ptr; cursor != NULL; cursor = cursor->link( ))
			{
				counter++;
				if(counter==(ind+1))
				{
					return cursor;
				}
			}
		}
	};


    template <class Item>
    std::list<std::tuple<Item, int>> frequency(LList<Item> data)
	{
		const node<Item>* cursor;		//Cursor in outer for loop.
		const node<Item>* cursortwin;		//Cursor in inner for loop. 
		int element=0;
		int elementschecked[data.length(data.gethead_ptr())]={ };
		std::list<std::tuple<Item, int>> TotaLList;
		int counter=0;                 //The number of times that the int was in the list.
		int currentindex=-1;	       //Current position in the LList<Item> used for array of elements.
					       //Don't want repeated elements to show in the result.
		int spacesfilled=0;
		bool getout=false;	       //If were checking for an element that was already checked, break;
		for (cursor = data.gethead_ptr(); cursor != NULL; cursor = cursor->link( ))
		{
			currentindex++;
			counter=0;
			element=cursor->data();
			if(currentindex!=0 && spacesfilled>0)
			{
				for(int i=0;i<spacesfilled;i++)
				{
					if(elementschecked[i]==element)
					{
						getout=true;
					}
				}
			}
			if(getout==true)
			{
				getout=false;
				continue;	//Move on to the next iteration of the for loop.
			}
			for (cursortwin = data.gethead_ptr(); cursortwin != NULL; cursortwin = cursortwin->link( ))
			{
				if(cursortwin->data()==element)
				{
					counter++;
				}
			}
			if(counter>=2)
			{
				elementschecked[spacesfilled]=element;
				spacesfilled++;
			}
			std::cout<<"The element to be added is: "<<element<<". This appears "<<counter<<" times."<<std::endl;
			std::tuple<Item, int> result(element,counter);
			TotaLList.push_back(result);
		}
		return TotaLList;
	};
}