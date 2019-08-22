#ifndef MAIN_SAVITCH_NETZEROENERGY_H
#define MAIN_SAVITCH_NETZEROENERGY_H
#include "node.h"
#include "llist.h"
#include "bintree.h"
#include "bintoarray.h"
#include <iostream>
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
            void introSetUp();
            void intro();
            void defaultscen();
            bool play();
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
            binary_tree_node<int>* Toast_num;
            binary_tree_node<int>* HandDry_num;
            // level 3
            binary_tree_node<int>* GolfCarts_num;
            binary_tree_node<int>* SOMOffice_num;
            binary_tree_node<int>* Xerox_num;
            binary_tree_node<int>* Wheeltro_num;
            binary_tree_node<int>* LargeRef_num;
            binary_tree_node<int>* Thermad_num;
            binary_tree_node<int>* Flowtron_num;
            binary_tree_node<int>* Microwaves_num;
            // level 2
            binary_tree_node<int>* AHU_num;
            binary_tree_node<int>* Lights_num;
            binary_tree_node<int>* IceMach_num;
            binary_tree_node<int>* MohaLift_num;
            // level 1
            binary_tree_node<int>* AirCond_num;
            binary_tree_node<int>* Desktop_num;
            // root
            binary_tree_node<int>* HVAC_num;
            bintoarray<int>* appliancenums;

            // A corresponding binary tree is to be made with appliance names in the same positions as 
            // the wattage numbers in the pervious tree.

            // level 4
            binary_tree_node<std::string>* Toast_name=new binary_tree_node<std::string>("|Toaster Ovens|");
            binary_tree_node<std::string>* HandDry_name=new binary_tree_node<std::string>("|Hand Dryers|");
            // level 3
            binary_tree_node<std::string>* GolfCarts_name=new binary_tree_node<std::string>("|Golf Carts|");
            binary_tree_node<std::string>* SOMOffice_name=new binary_tree_node<std::string>("|SOM Office Desktops|");
            binary_tree_node<std::string>* Xerox_name=new binary_tree_node<std::string>("|Xerox Machines|");
            binary_tree_node<std::string>* Wheeltro_name=new binary_tree_node<std::string>("|Wheeltronic Lift|");
            binary_tree_node<std::string>* LargeRef_name=new binary_tree_node<std::string>("|Large Refrigerator|");
            binary_tree_node<std::string>* Thermad_name=new binary_tree_node<std::string>("|Thermador Refrigerator|");
            binary_tree_node<std::string>* Flowtron_name=new binary_tree_node<std::string>("|Flowtron Bug Lights|");
            binary_tree_node<std::string>* Microwaves_name=new binary_tree_node<std::string>("|Microwaves|",HandDry_name,Toast_name);
            // level 2
            binary_tree_node<std::string>* AHU_name=new binary_tree_node<std::string>("|AHU|",SOMOffice_name,GolfCarts_name);
            binary_tree_node<std::string>* Lights_name=new binary_tree_node<std::string>("|Lights|",Wheeltro_name,Xerox_name);
            binary_tree_node<std::string>* IceMach_name=new binary_tree_node<std::string>("|Ice Machine|",Thermad_name,LargeRef_name);
            binary_tree_node<std::string>* MohaLift_name=new binary_tree_node<std::string>("|Mohawk Lifts|",Microwaves_name,Flowtron_name);
            // level 1
            binary_tree_node<std::string>* AirCond_name=new binary_tree_node<std::string>("|Air Conditioners|",Lights_name,AHU_name);
            binary_tree_node<std::string>* Desktop_name=new binary_tree_node<std::string>("|Desktop Computers|",MohaLift_name,IceMach_name);
            // level 0
            binary_tree_node<std::string>* HVAC_name=new binary_tree_node<std::string>("HVAC",AirCond_name,Desktop_name);
            bintoarray<std::string>* appliancenames=new bintoarray<std::string>(HVAC_name);
            

            std::string scenarios[9];// This array has the descriptions of 9 different energy use scenarios.
      };
}
#endif