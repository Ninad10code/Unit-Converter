#include<iostream>
#include<fstream>
#include <bits/stdc++.h> 
using namespace std;

float value;

//Structure created for each unit as a node
struct units
{
    float value[5],result[5];
    string converted_to[5];
    int child_node;
} link[100];

//Function named universal created to execute unit conversion
float universal(float value,int flag,float lib_int,int trig)
{
    if(flag==1)
    {
        if (trig==0)
        {
            value=value*lib_int;
            
        }
        else
        {
            float deno=1;
            value=value/(deno*lib_int);
            
        }
        
        
    }
    else
    {
        if (trig==0)
        {
            value=value/lib_int;
            
        }
        else
        {
            float deno=1;
            value=value/(deno/lib_int);
           
        }
        
        
    }
    return value;
    
}

//Main function
int main()
{
    int flag,l=1,count=0,trig=0;
    int trace;
    float container;
    string lib[40];//To store the library.txt file
    string u[6],lib_str,initial;
    cout<<"CONVERTER\n";
    cout<<"Enter the value you want to convert\n";
    cin>>value;
    container=value;
    cout<<"Enter the units you want to convert from\n";
    cin>>u[0]>>u[1];//Source unit and target unit
    initial=u[0];
    

    //Reading library.txt file
   
    
    fstream data;
    
    string library_file,library_path; 
     
    
    int i=0;
    library_file = "library.txt";
    data.open(library_file.c_str());
    while (data >> library_path)
    {
        lib[i]=library_path;
        
        i++;
        count++;
    }
    data.close();
    //library.txt closed
    

    int found=0,unfound=0;
    
    
    i=0;
    int j=1,k=4,track=0,check_count=0,execute=1,m=0,n=0,p=0,z=0,q=0,o=1;
    float lib_int;
    string check[10];

    //If source unit and target unit are found in library.txt it gets executed in the for loop
    for (int i = 0; i < (count/5) && track!=1; i++)
    {
        if(u[0]==lib[j] && u[1]==lib[k])
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
            link[0].result[0]=universal(value,flag,lib_int,trig);
            /*link[0].result[0] stores the converted value after
             calling the universal function*/
            cout<<container<<initial<<" = "<<link[0].result[0]<<u[1]<<"\n";
            
        }
        else if (u[0]==lib[k] && u[1]==lib[j])
        {
            /*flag is set to 0 when the lower unit is converted to higher unit
            eg To convert m to km flag will set to 0 as m<km*/
            track=1;
            flag=0;
            lib_str=lib[k-1];
            
            stringstream num (lib_str);
            num >> lib_int;
          
            link[0].result[0]=universal(value,flag,lib_int,trig);
            cout<<container<<initial<<" = "<<link[0].result[0]<<u[1]<<"\n";
       
        }
        else
        {
            j=j+5;
            k=k+5;
        }
        
        
    }
    //If no direct conversion of units exists in library.txt then track=0
    
    /*check[] string is used to check whether the unit was already converted to some unit before
    which prevents the unit getting converted to the previous unit*/

    check[0]=u[0];
    
    check_count++;
   
    /*link[].child_node states the number of possible conversion from a particular unit
    eg: cm can be converted to m, ft and in. Therefore the nodes for cm will be 3*/
    link[0].child_node=0;
  
    if(track==0)
    {
        while(found!=1)
        {
          //While loop executes untill found is not equal to 1  
            j=1;k=4;
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
                        if(check[i]==lib[j+3])
                        {
                            execute=0;
                         /*This is used to backtrack that whether the unit was converted earlier
                         to prevent the converted unit from getting converted to previous units*/   
                            
                        }
                    }

                    //If the unit has not been converted before then it gets executed
                    if (execute==1)
                    {
                        flag=1;
                        lib_str=lib[j+2];
                        stringstream num (lib_str);
                        num >> lib_int;
                        
                        link[m].result[n]=universal(value,flag,lib_int,trig);
                        
                        link[m].converted_to[n]=lib[j+3];
                       
                        check[o]=lib[j+3];
                       //Every new converted unit gets added into check[o]
                        check_count++;
                       
                        o++;
                        
                        link[m].child_node++;
                       
                        if (lib[j+3]==u[1])
                        {
                            trace=1;
                            found=1;
                            
                            cout<<container<<initial<<" = "<<link[m].result[n]<<u[1]<<"\n";
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
                       
                        link[m].result[n]=universal(value,flag,lib_int,trig);
                       
                        link[m].converted_to[n]=lib[k-3];
                        
                        check[o]=lib[k-3];
                        
                        check_count++;
                        
                        o++;
                       
                        link[m].child_node++;
                      
                        if (lib[k-3]==u[1])
                        {
                            trace=1;
                            found=1;
                            cout<<container<<initial<<" = "<<link[m].result[n]<<u[1]<<"\n";
                            
                        }
                    }
                    
                }
                j=j+5;
                k=k+5;
                execute=1;
                
            }
            m++;
            n=0;
            

            link[m].child_node=0;
            if (p<link[z].child_node)
            {
                
                if (value==0)
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
                
                q++;

                p++;
              
            }
            
            
            else
            {
                if (value==0)
                {
                    cout<<"Cannot be calculated\n";
                    found=1;
                }

                /*When all child nodes are used a new parent node is created
                eg: km has one child node that was m
                then m has one child node that was cm
                here m became a parent node for cm*/
                q=0;
                p=0;
                u[0]=link[z].converted_to[q];
                z++;
              
            }
            /*For every new node new structure gets generated*/
            
        
        }
    }
    
    
    
}
    
    
    
