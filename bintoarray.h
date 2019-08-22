#ifndef BINTOARRAY_H
#define BINTOARRAY_H
#include "bintree.h"
#include <iostream>
#include <cstdlib>  // Provides NULL and size_t

namespace NetZeroSpace
{
      template <class Item>
      class bintoarray
      {
            public:
            //constructor
            //This constructor is a bintree to array conversion.
            //There is a seperate function to convert a binary tree to a heap.
            bintoarray(binary_tree_node<Item>* root_pls)
            {
                  length=1;
                  binary_tree_node<Item>* example_node=root_pls;
                  int depth1=0;
                  int current_depth=-1;
                  while(!((example_node->left())==NULL && (example_node->right())==NULL))
                  {
                        depth1++;
                        example_node=example_node->left();
                  }
                  example_node=root_pls;
                  int current_binary=0;
                  for(int i=0;i<=depth1;i++)
                  {
                        current_depth++;
                        for(int q=0;q<twos[i];q++)
                        {
                              current_binary=binary1[length-1];
                              cursor=NULL;
                              reversedigits(root_pls,current_binary);
                              example_node=cursor;
                              if(example_node==NULL)
                                    break;
                              else
                              {
                                    data[length-1]=example_node->data();
                                    length++;                                    
                              }
                              
                        }
                  }
                  length--;
            }
            void reversedigits(binary_tree_node<Item>* root_pls, int number)
            {
                  if(cursor==NULL)
                        cursor=root_pls;
                  if(number<10)
                        std::cout<<"";
                  else
                  {
                        reversedigits(root_pls,number/10);
                        if(number%10==1)
                              cursor=cursor->right();
                        if(number%10==0)
                              cursor=cursor->left();
                  }
                  
            }
            void printInfo()
            {
                  std::cout<<"The number of nodes in the tree is "<<length<<std::endl;
                  std::cout<<"The elements of the tree are:"<<std::endl;
                  for(int i=0;i<length;i++)
                  {
                        if(i==1||i==3||i==7||i==15||i==31)
                              std::cout<<"\n";
                        if(i==0||i==2)
                              std::cout<<"\t\t";
                        if(i==1)
                              std::cout<<"\t";
                        if(i>=3 && i<=6)
                              std::cout<<"    ";
                        if(i>=8 && i<=14)
                              std::cout<<" ";
                        std::cout<<data[i]<<" ";
                  }
                  std::cout<<std::endl;
            };
            //getters
            Item* data1(){return data;}
            int length1(){return length;}
            //member functions
            void heapify(binary_tree_node<Item>* root_pls);
            void insert(binary_tree_node<Item>* root_pls, int& thisis);
            void remove(binary_tree_node<Item>* root_pls, binary_tree_node<Item>* toremove);

            private:
            //This is the maximum number of elements in each binary tree level.
            int twos[6]={1,2,4,8,16,32};
            //This is the set of binary numbers that relate to the left and right movements of a binary tree.
            int binary1[63]={1,10,11,100,101,110,111,1000,1001,1010,1011,1100,1101,1110,1111,10000,10001,10010,10011,10100,10101,10110,10111,
            11000,11001,11010,11011,11100,11101,11110,11111,100000,100001,100010,100011,100100,100101,100110,100111,101000,101001,
            101010,101011,101100,101101,101110,101111,110000,110001,110010,110011,110100,110101,110110,110111,111000,111001,111010,
            111011,111100,111101,111110,111111};
            //Precondition: user gave a complete tree with a maximum depth of 5.
            Item data[63];
            //The spots in the array that are just null in the tree.
            //int nullspots[40];
            //Skip some binary numbers to avoid segmentation fault.
            //int skipbinnum[63];
            // The amount of binary numbers that is currently filled.
            //int skipnumcount=0;
            // The amount of empty tree array that is currently filled.
            //int nullcounter=0;
            // The amount of tree array that is currently filled.
            int length=1;
            // Default cursor.
            binary_tree_node<Item>* cursor=NULL;
      };
}
#endif