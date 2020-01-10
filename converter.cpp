#include<iostream>
#include<fstream>
#include <bits/stdc++.h> 
using namespace std;
int q1,q2;
float value;
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
    int flag,l=1,count=1,l_pin,pin[28][10],calls=0,trig=0;
    int trace,l_odd=1,l_even=0,p_count=0,index,arr_size[120];
    float container;
    string  units[10],lib[40];
    string u[6],lib_str;
    cout<<"CONVERTER\n";
    cout<<"Enter the value you want to convert\n";
    cin>>value;
    container=value;
    cout<<"Enter the units you want to convert from\n";
    cin>>u[0]>>u[1];
    
    ifstream unit;
    unit.open("units.txt");
    for (int i = 0; i < 10; i++)
    {
        unit >> units[i];
    }
    unit.close();

    string b[120][12];
    string d[30][2];
    string a[120];
    string c[30];
    fstream file;
    fstream allocate;
    fstream data;
    string library_file,library_path; 
    string word, t, q, filename; 
    string path,assign;
    int i=0,stop_count=0,length_count=0,word_count=0;
    library_file = "library.txt";
    data.open(library_file.c_str());
    while (data >> library_path)
    {
        lib[i]=library_path;
      
        i++;
    }
    file.close();
    

    i=0;
    assign = "path_assign.txt";
    allocate.open(assign.c_str());
    while (allocate >> path)
    {
        c[i]=path;
        
        i++;
        word_count++;
        
    }
    file.close();
    int k=0;
    for (int i = 0; i < word_count/2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            d[i][j]=c[k];
            
            k++;
        }
      
        
        
    }
    
    i=0;
    // filename of the file 
    filename = "path_follow.txt"; 
  
    // opening file 
    file.open(filename.c_str()); 
  
    // extracting words from the file 
    while (file >> word) 
    { 
        
        
        a[i]=word;
       
        i++;
    } 
    file.close();
    
    i=0;
     k=0;
    for (int j = 0; j < 120; j++)
    {
       if  (a[j]!="STOP")
       {
           b[i][k]=a[j];
      
       k++;
       length_count++;
       arr_size[i]=length_count;

       }
       else
       {
           b[i][k]=a[j];
           i++;
           k=0;
           stop_count++;
           length_count=0;
       }
       
       
       
       
    }
    
    int j=0;  
    
    int found;
    for (int i = 0; i < word_count/2 && found!=1; i++)
    {
        if(d[i][0]==u[0] &&  d[i][1]==u[1])
        {
            index=i;
            found=1;
        }
        
    }
    
    i=0;
    int reset=0;
    if(found!=1)
    {
        cout<<"The following type of conversion is not possible\n";
    }
    else
    {
        
        calls=0;
        while (calls<arr_size[index]-1)
        {
            
            j=1;
            k=4;
            trace=0;
            
            while (trace!=1)
            {
                if (b[index][i]==lib[j] && b[index][i+1]==lib[k])
                {
                    
                    lib_str=lib[k-1];
                    
                    flag=1;
                    trace=1;
                }
                else if (b[index][i]==lib[k] && b[index][i+1]==lib[j])
                {
                    trace=1;
                    lib_str=lib[k-1];
                    flag=0;
                }
                
                else if(k>39 && reset<1)
                {
                   
                    trig=1;
                    
                    i++;
                    calls++;
                    j=-4;
                    k=-1;
                    reset++;
                }
                j=j+5;
                k=k+5;
                
                
                
                
            }
            i++;
            stringstream num (lib_str);
            float lib_int;
            num >> lib_int;
            value = universal(value,flag,lib_int,trig);
            calls++;
            
            
            
        }
        cout<<"Result: "<<container<<u[0]<<" = "<<value<<u[1]<<"\n";
    }
    
    

    
}
