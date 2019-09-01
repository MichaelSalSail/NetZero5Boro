#include "NetZeroEnergy.h"
#include <iostream>
#include <iomanip>
#include <string>

namespace NetZeroSpace
{
      
      void NetZeroEnergy::introSetUp()
      {
            RENEWABLEENERGY=new node<std::string>("|RENEWABLE ENERGY GAINED|");
            ELECTRONICS=new node<std::string>("\t\t\t|ELECTRONICS, COMPUTERS, AND SERVERS|",RENEWABLEENERGY);
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
            std::cout<<"\nThe Net Zero Energy Project was created in order to organize and record all of"<<std::endl;
            std::cout<<"the daily activities that consume energy to answer one question:"<<std::endl; 
            std::cout<<"Under what circumstances would 5 Boro produce as much electricity as it consumes?"<<std::endl;
            std::cout<<"To understand how to answer this question, continue with this interactive report."<<std::endl;
            std::cout<<"\nREAD THE INFORMATION GIVEN BEFORE PRESSING ENTER."<<std::endl;
            std::cout<<"Press enter to continue."<<std::endl;
            eat_line();
            std::cout<<"\n\nBelow are the six energy categories for 5 Boro:"<<std::endl;
            Categories->printlist(AIRCONDITION); 
            std::cout<<"\nBelow are the appliance names that belong to each category:"<<std::endl;
            AirConditionList->printlist(AirConditioning);
            ExhaustList->printlist(AHU);
            LightingList->printlist(Lightingg);
            GeneralList->printlist(Wheeltronic);
            ElectronicList->printlist(SOMDesktop);
            RenewableList->printlist(SolarPanels);
            std::cout<<"\nPress Enter to continue.";
            eat_line();
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
            HVAC_num=new binary_tree_node<int>(70840,Desktop_num,AirCond_num);
            appliancenums=new bintoarray<int>(HVAC_num);
            std::cout<<"\n\nThe first binary tree is a heap that follows a strict weak ordering of the Wattage numbers."<<std::endl;
            std::cout<<"It is to be read from least to greatest starting at the bottom from left to right moving up."<<std::endl;
            appliancenums->printInfo();
            std::cout<<"\nPress Enter to continue.";
            eat_line();

            Toast_name=new binary_tree_node<std::string>("|Toaster Ovens|");
            HandDry_name=new binary_tree_node<std::string>("|Hand Dryers|");
            // level 3
            GolfCarts_name=new binary_tree_node<std::string>("|Golf Carts|");
            SOMOffice_name=new binary_tree_node<std::string>("|SOM Office Desktops|");
            Xerox_name=new binary_tree_node<std::string>("|Xerox Machines|");
            Wheeltro_name=new binary_tree_node<std::string>("|Wheeltronic Lift|");
            LargeRef_name=new binary_tree_node<std::string>("|Large Refrigerator|");
            Thermad_name=new binary_tree_node<std::string>("|Thermador Refrigerator|");
            Flowtron_name=new binary_tree_node<std::string>("|Flowtron Bug Lights|");
            Microwaves_name=new binary_tree_node<std::string>("|Microwaves|",HandDry_name,Toast_name);
            // level 2
            AHU_name=new binary_tree_node<std::string>("|AHU|",SOMOffice_name,GolfCarts_name);
            Lights_name=new binary_tree_node<std::string>("|Lights|",Wheeltro_name,Xerox_name);
            IceMach_name=new binary_tree_node<std::string>("|Ice Machine|",Thermad_name,LargeRef_name);
            MohaLift_name=new binary_tree_node<std::string>("|Mohawk Lifts|",Microwaves_name,Flowtron_name);
            // level 1
            AirCond_name=new binary_tree_node<std::string>("|Air Conditioners|",Lights_name,AHU_name);
            Desktop_name=new binary_tree_node<std::string>("|Desktop Computers|",MohaLift_name,IceMach_name);
            // level 0
            HVAC_name=new binary_tree_node<std::string>("HVAC",Desktop_name,AirCond_name);
            appliancenames=new bintoarray<std::string>(HVAC_name);
            std::cout<<"\n\nThe below binary tree has the appliance names that correspond to the"<<std::endl;
            std::cout<<"same positions as the last tree. Its to be read in the same way."<<std::endl;
            appliancenames->printInfo();
            std::cout<<"\nPress Enter to continue.";
            eat_line();
      };

      void NetZeroEnergy::play()
      {
            std::cout<<"\n1. The previous information relates to the numbers for an average day in summer."<<std::endl;
            std::cout<<"Each appliance name corresponds with an energy value, or rather, a Wattage"<<std::endl;
            std::cout<<"per hour (Wh). Adding all the numbers, the total energy consumption of the"<<std::endl;
            std::cout<<"building is 214963 Watts per hour for an average day in summer. In an hour, the solar"<<std::endl;
            std::cout<<"panels will provide 30142 Wh to cover for the energy consumed. As a result, solar"<<std::endl;
            std::cout<<"energy can cover for 14% of energy used. This scenario is default. All of the"<<std::endl;
            std::cout<<"next scenarios change something from here."<<std::endl;
            std::cout<<"\nPress enter to continue: "<<std::endl;
            eat_line();

            std::cout<<"2. It is now Winter. There is no air conditioning nor is the ice machine in use."<<std::endl;
            std::cout<<"There is heating but that uses oil/gas instead of electricity so its not applicable."<<std::endl;
            std::cout<<"The rate the solar panels gain energy is the same. What percent of energy consumed"<<std::endl;
            std::cout<<"is covered by solar power? (Write the number, no percent sign required.)"<<std::endl;
            feedback();
            std::cout<<"Press enter to continue: "<<std::endl;
            eat_line();
            // Answer: 137413 Wh, therefore, solar panels cover for 21.93% of energy per hour.
            // getline blah blah blah

            std::cout<<"3. It is summer but there are 25% more solar panels on the roof. This results in"<<std::endl;
            std::cout<<"a 25% increase in the amount of solar power gained. What percent of energy use"<<std::endl;
            std::cout<<"is covered by renewable energy?"<<std::endl;
            // Answer: A 25% increase from 30142 Wh is 37677.5 Wh. This means solar that panels now cover for 17.52% of energy per hour.
            // getline blah blah blah
            feedback();
            std::cout<<"Press enter to continue: "<<std::endl;
            eat_line();

            std::cout<<"4. A project in the garage requires 5* the average use of the mohawk and"<<std::endl;
            std::cout<<"wheeltronic lifts. What percent of energy consumption is covered by renewable?"<<std::endl;
            // Answer: The average use is 1368 W and 920 W. A 5* increase is now 6840 W and 4600 W.
            //         Subtract original values from total: 214963W-1368W-920W=212675 W.
            //         Add the new value: 212675W+6840W+4600W=224115 W.
            //         Solar energy can cover for 13.44% of energy.
            // getline blah blah blah
            feedback();
            std::cout<<"Press enter to continue: "<<std::endl;
            eat_line();

            std::cout<<"5. All 10 golf carts batteries are used from previous workdays. All 10 are"<<std::endl;
            std::cout<<"currently charging. What percent of energy consumed is covered by renewable?"<<std::endl;
            // Answer: Default golf cart wattage is 1300 assuming only 2 golf carts charging and only need to
            //         be charged for an hour. In this scenario a golf cart would charge to its capacity of 
            //         5 hours for the day, something that would take 32500 W to accomplish. Dividing this by
            //         the 10 hours in a workday means an average wattage of 3250 Wh for a single cart. Since
            //         there are 10 carts, 32500 Wh. The new total energy consumption per hour in the building 
            //         is 246163 Wh. The amount solar energy covers is 12.24%.
            // getline blah blah blah
            feedback();
            std::cout<<"Press enter to continue: "<<std::endl;
            eat_line();

            std::cout<<"6. All of the Xerox Printers are removed from the office space. Employees are"<<std::endl;
            std::cout<<"expected to print from home. All microwaves and toaster ovens are also removed."<<std::endl;
            std::cout<<"What percent is covered by solar?"<<std::endl;
            // Answer: 975W+150W+120W= 1245 W. Subtracting 1245 W from 214963 W is 213,718. Solar covers for
            //         14.1% of energy.
            // getline blah blah blah
            feedback();
            std::cout<<"Press enter to continue: "<<std::endl;
            eat_line();

            std::cout<<"7. All of the lights at 5-Boro are broken. To continue with a regular workday,"<<std::endl;
            std::cout<<"employees are expected to work near windows where sunlight enters the building."<<std::endl;
            std::cout<<"If employees pass through any dark spaces they are to use the flashlight on "<<std::endl;
            std::cout<<"their phone. What percent of energy consumed is covered by renewables?"<<std::endl;
            // Answer: The total energy usage is now 214963W-15200W=199763 W. This means that solar now
            //         covers for 15.08% of energy.
            feedback();
            std::cout<<"Press enter to continue: "<<std::endl;
            eat_line();

            std::cout<<"8. The installation of more efficient lights that use occupancy sensors will"<<std::endl;
            std::cout<<"turn off the lights in a room if nobody is in it. A more efficient ventilation"<<std::endl;
            std::cout<<"system will conserve heat better to heat incoming air. The energy savings"<<std::endl;
            std::cout<<"for such systems is 40% and 25% respectively. What percent of energy is covered"<<std::endl;
            std::cout<<"by solar?"<<std::endl;
            // Answer: The wattage for lights is 15200 Wh. A 40% reduction brings it to 9120 Wh.
            //         The wattage for HVAC is 70840 Wh. A 25% reduction brings it to 53130 Wh.
            //         Subtract original numbers from total: 214963W-15200W-70840W=128923 Wh.
            //         Add the new numbers: 128923W+9120W+53130=191173 Wh.
            //         Solar energy covers for 15.76% of energy use.
            feedback();
            std::cout<<"Press enter to continue: "<<std::endl;
            eat_line();

            std::cout<<"9. Assume the solar panels worked on the weekend. There is now 240000 W for"<<std::endl;
            std::cout<<"use on Monday. The building is in use for two hours where 60284 W was gained"<<std::endl;
            std::cout<<"from the solar panels. If 300284 W of energy is stored for the two hours and"<<std::endl;
            std::cout<<"assuming that in each hour all the appliances in use were from categories"<<std::endl;
            std::cout<<"|Exhaust Fans, Heating, and Ventilation Units|, |Lighting|,"<<std::endl;
            std::cout<<"|Electronics, Computers, and Servers|, and |General Power and General Equipment|,"<<std::endl;
            std::cout<<"what percent of energy use was covered by renewables?"<<std::endl;
            // Answer: 100%! Each category respectively uses 86380 W, 15440 W, 30475 W, and 12668 W. The total is 144963 W.  
            //         In two hours, this is 289926 W. There is 10358 W of energy left over. This is a negligible amount of energy.
            //         Overall, the building went Net Zero for the day. Net Zero scenarios are possible but it is not without restriction.
            feedback();
            std::cout<<"Press enter to continue: "<<std::endl;
            eat_line();
            assesment();

      };
}