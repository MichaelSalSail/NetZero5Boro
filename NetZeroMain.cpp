#include "node.h"
#include "llist.h"
#include "bintree.h"
#include "bintoarray.h"
#include "NetZeroEnergy.h"
#include <iostream>
#include <string>
using namespace NetZeroSpace;

int main()
{
      NetZeroEnergy* example=new NetZeroEnergy();
      example->introSetUp();
      example->intro();
      example->defaultscen();
      std::cout<<"\nThe interactive report will now begin based off the information given."<<std::endl;
      std::cout<<"Press Enter to continue.";
      example->eat_line();
      example->play();

      
}














