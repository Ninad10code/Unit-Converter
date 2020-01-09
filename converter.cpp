#include<iostream>
#include<fstream>
#include <bits/stdc++.h> 
using namespace std;
int q1,q2;
float value;
float km_to_m(float value,int flag){
    //kilometer to meter and vice-versa function
    if(flag==1)
    {
        value=value*1000;
    }
    else
    {
        value=value/1000;
    }
    return value;
    cout<<value<<"\n";
}
float m_to_cm(float value,int flag)
{
    //meter to centimeter & vice-versa function
    if(flag==1)
    {
        value=value*100;
    }
    else
    {
        value=value/100;
    }
    return value;
}
float ft_to_cm(float value, int flag)
{
    //feet to centimeter & vice-versa function
    if(flag==1)
    {
        value=value*30;
    }
    else
    {
        value=value/30;
    }
    return value;
}
float in_to_cm(float value, int flag)
{
    //inches to centimeter & vice-versa function
    if(flag==1)
    {
        value=value*2.5;
    }
    else
    {
        value=value/2.5;
    }
    return value;
}
float hr_to_min(float value,int flag,int i)
{
    if(flag==1)
    {
       if(i==0 || i==1)
       {
           value=value*60;
       }
       else
       {
            float deno=1;
            value=(value/(deno*60));
            
       }
       
    }
    else
    {
        if (i==0 || i==1)
        {
            value=value/60;
            
        }
        else
        {
            float deno=1;
            value=(value/(deno/60));
            
        }
        
        
    }
    return value;
}
float min_to_sec(float value, int flag,int i)
{
    if(flag==1)
    {
        if(i==0 || i==1)
       {
           value=value*60;
           
       }
       else
       {
           float deno=1;
            value=(value/(deno*60)); 
       }
    }
    else
    {
        if (i==0 || i==1)
        {
            value=value/60;
        }
        else
        {
            
            float deno=1;
            value=(value/(deno/60));
            
        }
    }
    return value;
}

int main()
{
    int flag,l=1,count=1,l_pin,pin[28][10];
    int trace,l_odd=1,l_even=0,p_count=0,index,arr_size[112];
    float container;
    string  units[10];
    string u[2];
    cout<<"CONVERTER\n";
    cout<<"Enter the value you want to convert\n";
    cin>>value;
    container=value;
    cout<<"Enter the units you want to convert from\n";
    cin>>u[0]>>u[1];
    cout<<u[0]<<"/t"<<u[1]<<"\n";
    ifstream unit;
    unit.open("units.txt");
    for (int i = 0; i < 10; i++)
    {
        unit >> units[i];
    }
    unit.close();

    string b[112][12];
    string d[30][2];
    string a[112];
    string c[30];
    fstream file;
    fstream allocate; 
    string word, t, q, filename; 
    string path,assign;
    int i=0,stop_count=0,length_count=0,word_count=0;
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
    for (int j = 0; j < 112; j++)
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
    if(found!=1)
    {
        cout<<"The following type of conversion is not possible\n";
    }
    else
    {
        while (p_count<arr_size[index]-1)
        {
            
            if(b[index][i]=="km" && b[index][i+1]=="m")
            {
                
                flag=1;
                value=km_to_m(value,flag);
               
            }
            else if (b[index][i]=="m" && b[index][i+1]=="km")
            {
                
                flag=0;
                value=km_to_m(value,flag);
                
                
            }
            else if (b[index][i]=="m" && b[index][i+1]=="cm")
            {
                
                flag=1;
                value=m_to_cm(value,flag);
               
            }
            else if (b[index][i]=="cm" && b[index][i+1]=="m")
            {
                
                flag=0;
                value=m_to_cm(value,flag);
                
            }
            else if (b[index][i]=="ft" && b[index][i+1]=="cm")
            {
                
                flag=1;
                value=ft_to_cm(value,flag);
               
            }
            else if (b[index][i]=="cm" && b[index][i+1]=="ft")
            {
                
                flag=0;
                value=ft_to_cm(value,flag);
               
            }
            else if (b[index][i]=="in" && b[index][i+1]=="cm")
            {
                
                flag=1;
                value=in_to_cm(value,flag);
            }
            else if (b[index][i]=="cm" && b[index][i+1]=="in")
            {
                
                flag=0;
                value=in_to_cm(value,flag);
            }
            else if (b[index][i]=="hr" && b[index][i+1]=="min")
            {
                
                flag=1;
                value=hr_to_min(value,flag,i);
                
            }
            else if (b[index][i]=="min" && b[index][i+1]=="hr")
            {
                
                flag=0;
                value=hr_to_min(value,flag,i);
              
            }
            else if (b[index][i]=="min" && b[index][i+1]=="s")
            {
                
                flag=1;
                value=min_to_sec(value,flag,i);
                
            }
            else if (b[index][i]=="s" && b[index][i+1]=="min")
            {
                
                flag=0;
                value=min_to_sec(value,flag,i);
                
            }
            else
            {
                i=i; 
            }
            i++;
            p_count++;
            
        }
        cout<<"Result: "<<container<<u[0]<<" = "<<value<<u[1]<<"\n";
    }
   

    
}
