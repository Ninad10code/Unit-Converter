#include<iostream>
#include<fstream>
#include <bits/stdc++.h> 
using namespace std;
int q1,q2;
float value;
struct units
{
    float value[5],result[5];
    string converted_to[5];
    int child_node;
} link[100];
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

int main()
{
    int flag,l=1,count=0,l_pin,pin[28][10],calls=0,trig=0;
    int trace,l_odd=1,l_even=0,p_count=0,index,arr_size[120];
    float container;
    string  units[10],lib[40];
    string u[6],lib_str,initial;
    cout<<"CONVERTER\n";
    cout<<"Enter the value you want to convert\n";
    cin>>value;
    container=value;
    cout<<"Enter the units you want to convert from\n";
    cin>>u[0]>>u[1];
    initial=u[0];
    

    string b[120][12];
    string d[30][2];
    string a[120];
    string c[30];
    fstream file;
    fstream allocate;
    fstream data;
    string library_file,library_path; 
    string word, t, filename; 
    string path,assign;
    int i=0,stop_count=0,length_count=0,word_count=0;
    library_file = "library.txt";
    data.open(library_file.c_str());
    while (data >> library_path)
    {
        lib[i]=library_path;
        
        i++;
        count++;
    }
    file.close();
    
    

    int found=0,unfound=0;
    
    
    i=0;
    int reset=0,j=1,k=4,counter=0,search[30][2],track=0,check_count=0,execute=1,m=0,n=0,p=0,z=0,q=0,o=1;
    float lib_int;
    string check[10];
    for (int i = 0; i < (count/5) && track!=1; i++)
    {
        if(u[0]==lib[j] && u[1]==lib[k])
        {
            track=1;
            flag=1;
            lib_str=lib[k-1];
            stringstream num (lib_str);
            num >> lib_int;
           
            link[0].result[0]=universal(value,flag,lib_int,trig);
            cout<<container<<initial<<" = "<<link[0].result[0]<<u[1]<<"\n";
            
        }
        else if (u[0]==lib[k] && u[1]==lib[j])
        {
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
    check[0]=u[0];
    
    check_count++;
   
    
    link[0].child_node=0;
  
    if(track==0)
    {
        while(found!=1)
        {
            
            j=1;k=4;
            for (int i = 0; i < (count/5) && trace!=1; i++)
            {
                
                if (u[0]==lib[j])
                {
                    
                    for (int i = 0; i < check_count && execute!=0; i++)
                    {
                        if(check[i]==lib[j+3])
                        {
                            execute=0;
                            
                            
                        }
                    }
                  
                    if (execute==1)
                    {
                        flag=1;
                        lib_str=lib[j+2];
                        stringstream num (lib_str);
                        num >> lib_int;
                        
                        link[m].result[n]=universal(value,flag,lib_int,trig);
                        
                        link[m].converted_to[n]=lib[j+3];
                       
                        check[o]=lib[j+3];
                       
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
                q=0;
                p=0;
                u[0]=link[z].converted_to[q];
                z++;
              
            }
            
            
        
        }
    }
    
    
    
}
    
    
    
