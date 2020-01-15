#include<iostream>
#include<fstream>
#include <bits/stdc++.h> 
using namespace std;

float value;

//Structure created for each unit as a node
struct units
{
    float result[5];
    string converted_to[5];
    int child_node;
} link[100];
//link[i] represents members of structure
//Function named universal created to execute unit conversion
float universal(float value,int flag,float lib_int)
{
    if(flag==1)
    {
        value=value*lib_int;
        
    }
    else
    {
        value=value/lib_int;
        
    }
    return value;
    
}

//Main function
int main()
{
    int flag,count=0,trig=0;
    int trace;
    float container;
    string lib[40]; //To store the library.txt file
    string u[6],lib_str,initial;
    cout<<"CONVERTER\n";
    cout<<"Enter the value you want to convert\n";
    cin>>value;
    container=value;
    cout<<"Enter the units you want to convert from\n";
    cin>>u[0]>>u[1];//u[0]{Source unit} and u[1]{target unit}
    initial=u[0];//copying source unit into initial variable
    

    //Reading library.txt file
   
    
    fstream file;
    string file_name,library_data; 
     
    int i=0;
    file_name = "library.txt";
    file.open(file_name.c_str());
    while (file >> library_data)
    {
        lib[i]=library_data; 
        
        i++;
        count++;  //count is used to count the total number of string copied
    }
    file.close();
    //library.txt closed
    

    int found=0;
    
    
    
    int j=1,k=4;
    /*In library.txt data is present as
        1 km = 1000 m
        here j points to the indexing of km and k points to the indexing of 4*/
    int track=0,check_count=0,execute=1,m=0,n=0,node=0,z=0,q=0,o=1;
    float lib_int;//To store the conversion factor 
    string check[10];//To keep track of already converted units

    //If source unit and target unit are found in library.txt it gets executed in the for loop
    for (int i = 0; i < (count/5) && track!=1; i++)
    {
        /*The written format in library.txt is given as
        1 km = 1000 m
        1 m = 100 cm
        1 ft = 30 cm
        lib[j] contains following string {km, m, ft} at indexings {1, 6, 11}
        lib[k] contains following string {m, cm, cm} at indexing {4, 9, 14}
        */
        
        if(u[0]==lib[j] && u[1]==lib[k])
        /*suppose u[0]=m and u[1]=cm
        The written format in library.txt is given as
        1 km = 1000 m
        1 m = 100 cm
        1 ft = 30 cm
        lib[j] contains following string {km, m, ft} at indexings j={1, 6, 11}
        lib[k] contains following string {m, cm, cm} at indexing k={4, 9, 14}
            as mentioned above u[0]=m=lib[j=6] and u[1]=cm=lib[k=9]
        */
        {
            /*flag is set to 1 when the higher unit is converted to lower unit
            eg To convert km to m flag will set to 1 as km>m*/
            track=1;
            flag=1;
            /*lib_str stores the conversion factor from lib[k-1]
             which was read from library.txt file*/
            lib_str=lib[k-1];
            stringstream num (lib_str);
            num >> lib_int;
            /*The lib_int stores the lib_str value as a floating number
            after converting the string value into floating value*/
            link[0].result[0]=universal(value,flag,lib_int);
            /*link[0].result[0] stores the converted value after
             calling the universal function*/
            cout<<container<<initial<<" = "<<link[0].result[0]<<u[1]<<"\n";
            
        }
        else if (u[0]==lib[k] && u[1]==lib[j])
        /*suppose u[0]=cm and u[1]=m
        The written format in library.txt is given as
        1 km = 1000 m
        1 m = 100 cm
        1 ft = 30 cm
        lib[j] contains following string {km, m, ft} at indexings j={1, 6, 11}
        lib[k] contains following string {m, cm, cm} at indexing k={4, 9, 14}
            as mentioned above u[0]=cm=lib[k=9] and u[1]=m=lib[j=6]
        */
        {
            /*flag is set to 0 when the lower unit is converted to higher unit
            eg To convert m to km flag will set to 0 as m<km*/
            track=1;//states that the conversion path is found
            flag=0;
            lib_str=lib[k-1];
            
            stringstream num (lib_str);
            num >> lib_int;
          
            link[0].result[0]=universal(value,flag,lib_int);
            cout<<container<<initial<<" = "<<link[0].result[0]<<u[1]<<"\n";
       
        }
        else
        {
            j=j+5;//increments the indexing of j by 5
            k=k+5;//increments the indexing of k by 5
            /*
            The written format in library.txt is given as
            1 km = 1000 m
            1 m = 100 cm
            1 ft = 30 cm
            lib[j] contains following string {km, m, ft} at indexings j={1, 6, 11}
            lib[k] contains following string {m, cm, cm} at indexing k={4, 9, 14}

            */
        }
        
        
    }
    //If no direct conversion of units exists in library.txt then track=0
    
    /*check[] string is used to check whether the unit was already converted to some unit before
    which prevents the unit getting converted to the previous unit*/

    check[0]=u[0];//assigning the source unit to check[0] so that ahead it won't get converted back to source unit
    
    check_count++;//as one unit is assigned in check[] therefore incrementing the check_count
   
    /*link[].child_node states the number of possible conversion from a particular unit
    eg: cm can be converted to m, ft and in. Therefore the nodes for cm will be 3*/
    link[0].child_node=0;//initialising to 0 as at the start there are no child_node
  
    if(track==0)
    {
        while(found!=1)
        {
          //While loop executes untill found is not equal to 1  
            j=1;k=4;
            /*
            The written format in library.txt is given as
            1 km = 1000 m
            1 m = 100 cm
            1 ft = 30 cm
            lib[j=0]=1; lib[j=1]=km; lib[j=2]==; lib[j=3]=1000; lib[j=4]=m
            lib[j=5]=1; lib[j=6]=m; lib[j=7]==; lib[j=8]=100; lib[j=9]=cm
            lib[j] contains following string {km, m, ft} at indexings j={1, 6, 11}
            lib[k] contains following string {m, cm, cm} at indexing k={4, 9, 14}
            
            */
            for (int i = 0; i < (count/5) && trace!=1; i++)
            {
                /*The for loop executes to find all possible path of conversion
                 eg suppose in library.txt it is given that cm can be converted
                 to m, ft and in then the for loop finds all such possible conversion*/
           
                /*As in library.txt it is given that
                 1 km = 1000 m
                 here lib[j] represent km*/
                if (u[0]==lib[j])
                {
                    
                    for (int i = 0; i < check_count && execute!=0; i++)
                    {
                        if(check[i]==lib[j+3])//checks whether the lib[j+3] has been already converte with the data in check[i]
                        {
                            execute=0;
                         /*This is used to backtrack that whether the unit was converted earlier
                         to prevent the converted unit from getting converted to previous units.
                         if the unit was already converted then execute becomes equal to 0
                         */   
                            
                        }
                    }

                    //If the unit has not been converted before then it gets executed
                    if (execute==1)
                    {
                        flag=1;
                        lib_str=lib[j+2];
                        stringstream num (lib_str);
                        num >> lib_int;
                        /*
                        link[m] represent structure with indexing m
                        */
                        link[m].result[n]=universal(value,flag,lib_int);
                        //for a particular structure of index m with result for particular child node index n
                        link[m].converted_to[n]=lib[j+3];
                        //it stores the converted value name 
                        n++;
                        check[o]=lib[j+3];
                       //Every new converted unit gets added into check[o]
                        check_count++;//as new unit gets added check-count also gets added
                       
                        o++;//incrementing the indexing of o
                        
                        link[m].child_node++;
                        // as a child_node gets created therefore it gets incremented for a particular structure of index m
                       
                        if (lib[j+3]==u[1])//checks whether the converted unit{lib[j+3]} is equal to target unit{u[1]}
                        {
                            trace=1;//trace=1 is made to exit the for loop
                            found=1;//found=1 is made to exit the while loop
                            
                            cout<<container<<initial<<" = "<<link[m].result[n-1]<<u[1]<<"\n";
                        }
                    }
                    
                    
                    
                }
                /*As in library.txt it is given that
                 1 km = 1000 m
                 here lib[k] represent m*/
                else if (u[0]==lib[k])
                {
                 
                    for (int i = 0; i < check_count; i++)
                    {
                        if(check[i]==lib[k-3])
                        {
                            
                            execute=0;
                            
                        }
                    }
                    
                    if (execute==1)
                    {
                        flag=0;
                        lib_str=lib[k-1];
                        stringstream num (lib_str);
                        num >> lib_int;
                       
                        link[m].result[n]=universal(value,flag,lib_int);
                       
                        link[m].converted_to[n]=lib[k-3];
                        n++;
                        check[o]=lib[k-3];
                        
                        check_count++;
                        
                        o++;
                       
                        link[m].child_node++;
                      
                        if (lib[k-3]==u[1])
                        {
                            trace=1;
                            found=1;
                            cout<<container<<initial<<" = "<<link[m].result[n-1]<<u[1]<<"\n";
                            
                        }
                    }
                    
                }
                j=j+5;
                k=k+5;
                execute=1;//reseting the value of execute to 1
                
            }
            m++;//to make new structure for every unit the indexing of m is incremented
            n=0;//as for new unit a new structure is made therefor the child_node index n is made equal to 0
            

            link[m].child_node=0;
            if (node<link[z].child_node)
            /*
            checks the value of {node} is less than the structure of index z value {link[z].child_node}
            */
            {
                
                if (z>10)//if the indexing value of z exceeds 10 then the target unit is not found
                {
                    cout<<"Cannot be calculated\n";
                    found=1;
                }

                /*u[0] is updated to the value of child node
                eg earlier u[0] was km and then it was converted
                to m which is its child node hence then the new 
                u[0] value will be set to m*/

                u[0]=link[z].converted_to[q];
                
                value=link[z].result[q];
                
                q++;//increamenting child node indexing

                node++;
              
            }
            
            
            else
            {
                if (z>10)
                {
                    cout<<"Cannot be calculated\n";
                    found=1;
                }

                /*When all child nodes are used a new parent node is created
                eg: km has one child node that was m
                then m has one child node that was cm
                here m became a parent node for cm*/
                q=0;
                node=0;
                u[0]=link[z].converted_to[q];
                z++;
              
            }
            /*For every new node new structure gets generated*/
            
        
        }
    }
    
    
    
}
    
    
    
