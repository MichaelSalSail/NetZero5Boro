#include "node.h"
#include "llist.h"
#include "bintree.h"
#include "bintoarray.h"
#include "NetZeroEnergy.h"
#include <iostream>
#include <string>
using namespace NetZeroSpace;

//g++ node.h node.cpp llist.h llist.cpp bintree.h bintoarray.h NetZeroEnergy.h NetZeroEnergy.cpp NetZeroMain.cpp
int main()
{
      NetZeroEnergy* example=new NetZeroEnergy();
      example->introSetUp();
      example->intro();

      
}