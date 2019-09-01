#ifndef MAIN_SAVITCH_NETZEROENERGY_H
#define MAIN_SAVITCH_NETZEROENERGY_H
#include "node.h"
#include "llist.h"
#include "bintree.h"
#include "bintoarray.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <vector>

namespace NetZeroSpace
{
      class NetZeroEnergy
      {
            public:
            NetZeroEnergy()
            {
                  std::cout<<"Welcome to 5 Boro Parks and Recreation."<<std::endl;
            }
            ~NetZeroEnergy();
            void eat_line()
            {
                  char next;
                  do
                  {
                        std::cin.get(next);
                  } 
                  while (next!='\n');
                  
            }
            void introSetUp();
            void intro();
            void defaultscen();
            void play();
            void feedback()
            {
                  std::cout<<std::endl;
                  std::getline(std::cin,usersaid[arrayspot]);
                  std::string numberput=usersaid[arrayspot];
                  userinput[arrayspot]=std::stod(numberput);
                  if(abs(userinput[arrayspot]-answers[arrayspot])<=0.5)
                        std::cout<<"Correct!"<<std::endl;
                  else if(abs(userinput[arrayspot]-answers[arrayspot])>0.5 && abs(userinput[arrayspot]-answers[arrayspot])<=5)
                        std::cout<<"Your answer is close."<<std::endl;
                  else if(abs(userinput[arrayspot]-answers[arrayspot])>5 && abs(userinput[arrayspot]-answers[arrayspot])<=10)
                        std::cout<<"Your answer is somewhat near."<<std::endl;
                  else
                        std::cout<<"Your answer is not close. Rethink it next time."<<std::endl;
                  arrayspot++;
            }
            void assesment()
            {
                  int corrects=0;
                  for(int i=0;i<arrayspot;i++)
                  {
                        if(abs(userinput[i]-answers[i])<=0.5)
                              corrects++;
                  }
                  std::cout<<"\nYou got "<<corrects<<"/8 answers correct."<<std::endl;
                  if(corrects<8)
                        std::cout<<"Try to get all answers correct next time."<<std::endl;
                  else
                        std::cout<<"Congratulations, you are energy proficient."<<std::endl;
                  
            }

            private:
            // There are 6 different categories for all energy usage/renewable energy gained.
            node<std::string>* RENEWABLEENERGY;       node<std::string>* ELECTRONICS;
            node<std::string>* GENERALPOWER;          node<std::string>* LIGHTING;
            node<std::string>* EXHAUSTHEATVENT;       node<std::string>* AIRCONDITION;
            LList<std::string>* Categories;
            // Renewable Energy Appliances list.
            node<std::string>* AirConditioning;       LList<std::string>* AirConditionList;
            // Exhaust Fans, Heating, and Ventilation Units Appliances List.
            node<std::string>* HVAC;                  node<std::string>* AHU;
            LList<std::string>* ExhaustList;
            // Lighting Applainces List.
            node<std::string>* FlowtronBug;           node<std::string>* Lightingg;
            LList<std::string>* LightingList;
            // General Power and General Equipment Appliances List.
            node<std::string>* IceMachine;            node<std::string>* LargeRefrigirator;
            node<std::string>* ThermRefrigirator;     node<std::string>* Microwaves;
            node<std::string>* ToasterOvens;          node<std::string>* HandDryers;
            node<std::string>* GolfCarts;             node<std::string>* MohawkLifts;
            node<std::string>* Wheeltronic;           LList<std::string>* GeneralList;
            // Electronics, Computers, and Servers Appliances List.
            node<std::string>* DesktopComp;           node<std::string>* XeroxPrint;
            node<std::string>* SOMDesktop;            LList<std::string>* ElectronicList;
            // Renewable Energy Gained.
            node<std::string>* SolarPanels;           LList<std::string>* RenewableList;

            // The above used the linked list data structure while the below will now use the
            // binary tree data structure.
            // The first binary tree is a heap that follows a strict weak ordering of the Wattage numbers.
            // level 4
            binary_tree_node<int>* Toast_num;         binary_tree_node<int>* HandDry_num;
            // level 3
            binary_tree_node<int>* GolfCarts_num;     binary_tree_node<int>* SOMOffice_num;
            binary_tree_node<int>* Xerox_num;         binary_tree_node<int>* Wheeltro_num;
            binary_tree_node<int>* LargeRef_num;      binary_tree_node<int>* Thermad_num;
            binary_tree_node<int>* Flowtron_num;      binary_tree_node<int>* Microwaves_num;
            // level 2
            binary_tree_node<int>* AHU_num;           binary_tree_node<int>* Lights_num;
            binary_tree_node<int>* IceMach_num;       binary_tree_node<int>* MohaLift_num;
            // level 1
            binary_tree_node<int>* AirCond_num;       binary_tree_node<int>* Desktop_num;
            // root
            binary_tree_node<int>* HVAC_num;
            bintoarray<int>* appliancenums;

            // A corresponding binary tree is to be made with appliance names in the same positions as 
            // the wattage numbers in the pervious tree.

            // level 4
            binary_tree_node<std::string>* Toast_name;      binary_tree_node<std::string>* HandDry_name;
            // level 3
            binary_tree_node<std::string>* GolfCarts_name;  binary_tree_node<std::string>* SOMOffice_name;
            binary_tree_node<std::string>* Xerox_name;      binary_tree_node<std::string>* Wheeltro_name;
            binary_tree_node<std::string>* LargeRef_name;   binary_tree_node<std::string>* Thermad_name;
            binary_tree_node<std::string>* Flowtron_name;   binary_tree_node<std::string>* Microwaves_name;
            // level 2
            binary_tree_node<std::string>* AHU_name;        binary_tree_node<std::string>* Lights_name;
            binary_tree_node<std::string>* IceMach_name;    binary_tree_node<std::string>* MohaLift_name;
            // level 1
            binary_tree_node<std::string>* AirCond_name;    binary_tree_node<std::string>* Desktop_name;
            // level 0
            binary_tree_node<std::string>* HVAC_name;
            bintoarray<std::string>* appliancenames;
            


            std::string dummyvar="";
            double answers[8]={21.93,17.52,13.44,12.24,14.1,15.08,15.76,100};// This array has the answers for 8 scenarios.
            int arrayspot=0;        // Counter keeps track of position of array as it is being filled.
            std::string usersaid[8];// This array keeps all answers the user gave.
            double userinput[8];    // Converts string inputs from the user to double.


      };
}
#endif