#include "NetZeroEnergy.h"
#include <iomanip>

namespace NetZeroSpace
{
      /*    
            The variables for the class use arrays (maybe change to vectors.)
            There are other data structures to use like Linked Lists and Binary Trees.
            Linked Lists: This allows for elements to be deleted. That can't be done
            in an array because it is not dynamic, size stays the same for an array. 
            Basic information can be changed to a Linked List. The scenarios can be
            connected together as a Linked List as well.
            Binary Tree: This is best used for user decisions of yes and no.
            For the program, the user will give input on how much they think the
            solar energy will cover for the given scenario description. Binary 
            trees are also a great visual aid. At the results page the answers the
            user gave can be compared with the correct answers.
            
            Program Set-Up:
            Start: A summary of 5 Boro NYC Parks and what is Net Zero Energy.
            Begin: 
      */
      void NetZeroEnergy::introSetUp()
      {
            RENEWABLEENERGY=new node<std::string>("|RENEWABLE ENERGY GAINED|");
            ELECTRONICS=new node<std::string>("\t\t\t|ELECTRONICS COMPUTERS AND SERVERS|",RENEWABLEENERGY);
            GENERALPOWER=new node<std::string>("|GENERAL POWER AND GENERAL EQUIPMENT|\n",ELECTRONICS);
            LIGHTING=new node<std::string>("|LIGHTING|",GENERALPOWER);
            EXHAUSTHEATVENT=new node<std::string>("|EXHAUST FANS, HEATING, AND VENTILATION UNITS|",LIGHTING);
            AIRCONDITION=new node<std::string>("\n\t\t\t|AIR CONDITIONING|",EXHAUSTHEATVENT);
            Categories=new LList<std::string>(AIRCONDITION,RENEWABLEENERGY,6);
            // Renewable Energy Appliances list.
            AirConditioning=new node<std::string>("\n\t\t\t|Air Conditioner|");
            AirConditionList=new LList<std::string>(AirConditioning,NULL,1);
            // Exhaust Fans, Heating, and Ventilation Units Appliances List.
            HVAC=new node<std::string>("|HVAC|");
            AHU=new node<std::string>("\n\t\t\t|AHU|",HVAC);
            ExhaustList=new LList<std::string>(AHU,HVAC,2);
            // Lighting Applainces List.
            FlowtronBug=new node<std::string>("|Flowtron Bug Light|");
            Lightingg=new node<std::string>("\n\t\t\t|Lighting|",FlowtronBug);
            LightingList=new LList<std::string>(Lightingg,FlowtronBug,2);
            // General Power and General Equipment Appliances List.
            IceMachine=new node<std::string>("|Ice Machine|");
            LargeRefrigirator=new node<std::string>("\t\t\t|Large Refrigerator|",IceMachine);
            ThermRefrigirator=new node<std::string>("|Thermador Refrigerator|\n",LargeRefrigirator);
            Microwaves=new node<std::string>("|Microwaves|",ThermRefrigirator);
            ToasterOvens=new node<std::string>("|Toaster Ovens|",Microwaves);
            HandDryers=new node<std::string>("|Hand Dryers|",ToasterOvens);
            GolfCarts=new node<std::string>("|Golf Carts|",HandDryers);
            MohawkLifts=new node<std::string>("|Mohawk Lifts|",GolfCarts);
            Wheeltronic=new node<std::string>("\n\t\t\t|Wheeltronic Lifts|",MohawkLifts);
            GeneralList=new LList<std::string>(Wheeltronic,IceMachine,9);
            // Electronics, Computers, and Servers Appliances List.
            DesktopComp=new node<std::string>("|Desktop Computers|");
            XeroxPrint=new node<std::string>("|Xerox Printers|",DesktopComp);
            SOMDesktop=new node<std::string>("\n\t\t\t|SOM Office Desktops|",XeroxPrint);
            ElectronicList=new LList<std::string>(SOMDesktop,DesktopComp,3);
            // Renewable Energy Gained.
            SolarPanels=new node<std::string>("\n\t\t\t|Solar Panel Inverters|");
            RenewableList=new LList<std::string>(SolarPanels,NULL,1);
      };

      void NetZeroEnergy::intro()
      {
            std::cout<<"The Net Zero Energy Project was created"<<std::endl; 
            std::cout<<"in order to organize and record all of the daily activities"<<std::endl; 
            std::cout<<"that consume energy to answer one question:"<<std::endl; 
            std::cout<<"Under what circumstances would 5 Boro produce as much electricity"<<std::endl;
            std::cout<<"as it consumes?"<<std::endl;
            std::cout<<"To understand how to answer this question, continue with this interactive report."<<std::endl;
            std::cout<<"\n\nBelow are the six energy categories for 5 Boro:"<<std::endl;
            Categories->printlist(AIRCONDITION); 
            std::cout<<"\nBelow are the appliance names that belong to each category:"<<std::endl;
            AirConditionList->printlist(AirConditioning);
            ExhaustList->printlist(AHU);
            LightingList->printlist(Lightingg);
            GeneralList->printlist(Wheeltronic);
            ElectronicList->printlist(SOMDesktop);
            RenewableList->printlist(SolarPanels);
      };

      void NetZeroEnergy::defaultscen()
      {
            Toast_num=new binary_tree_node<int>(120);
            HandDry_num=new binary_tree_node<int>(50);
            // level 3
            GolfCarts_num=new binary_tree_node<int>(1300);
            SOMOffice_num=new binary_tree_node<int>(1160);
            Xerox_num=new binary_tree_node<int>(975);
            Wheeltro_num=new binary_tree_node<int>(920);
            LargeRef_num=new binary_tree_node<int>(860);
            Thermad_num=new binary_tree_node<int>(350);
            Flowtron_num=new binary_tree_node<int>(240);
            Microwaves_num=new binary_tree_node<int>(150,HandDry_num,Toast_num);
            // level 2
            AHU_num=new binary_tree_node<int>(15540,SOMOffice_num,GolfCarts_num);
            Lights_num=new binary_tree_node<int>(15200,Wheeltro_num,Xerox_num);
            IceMach_num=new binary_tree_node<int>(7550,Thermad_num,LargeRef_num);
            MohaLift_num=new binary_tree_node<int>(1368,Microwaves_num,Flowtron_num);
            // level 1
            AirCond_num=new binary_tree_node<int>(70000,Lights_num,AHU_num);
            Desktop_num=new binary_tree_node<int>(28340,MohaLift_num,IceMach_num);
            // root
            HVAC_num=new binary_tree_node<int>(70840,AirCond_num,Desktop_num);
            appliancenums=new bintoarray<int>(HVAC_num);
      };
}