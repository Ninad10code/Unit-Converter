#include<iostream>
#include<fstream>
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
float hr_to_min(float value,int flag)
{
    if(flag==1)
    {
       if(q1==9 || q2==9)
       {
           float deno=1;
            value=(value/(deno*60));
       }
       else
       {
            value=value*60;
       }
       
    }
    else
    {
        if (q1==9 || q2==9)
        {
            float deno=1;
            value=(value/(deno/60));
        }
        else
        {
            value=value/60;
        }
        
        
    }
    return value;
}
float min_to_sec(float value, int flag)
{
    if(flag==1)
    {
        if(q1==9 || q2==9)
       {
           float deno=1;
            value=(value/(deno*60));
       }
       else
       {
            value=value*60;
       }
    }
    else
    {
        if (q1==9 || q2==9)
        {
            float deno=1;
            value=(value/(deno/60));
        }
        else
        {
            value=value/60;
        }
    }
    return value;
}

int main()
{
    int flag,l=1,count=1,l_pin,pin[28][10];
    int trace,l_odd=1,l_even=0,p_count=0;
    float container;
    string  units[10];
    string u1,u2;
    cout<<"CONVERTER\n";
    cout<<"Enter the value you want to convert\n";
    cin>>value;
    container=value;
    cout<<"Enter the units you want to convert from\n";
    cin>>u1>>u2;
    ifstream unit;
    unit.open("units.txt");
    for (int i = 0; i < 10; i++)
    {
        unit >> units[i];
    }
    unit.close();
    for (int i = 0; i < 10; i++)
    {
        if(u1==units[i])
        {
            q1=i+1;
            
        }
        else if (u2==units[i])
        {
            q2=i+1;
            
        }
        
    }
    
    ifstream fin;
    fin.open("path.txt");
    for (int  i = 0; i < 12; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            fin >> pin[i][j];
            
        }
        
        
    }
    for (int  i = 12; i < 22; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            fin >> pin[i][j];
            
            
        }
        
    }
    for (int  i = 22; i < 26; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            fin >> pin[i][j];
            
            
        }
       
    }
    for (int  i = 26; i < 28; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            fin >> pin[i][j];
            
            
        }
        
    }
    
    fin.close();

    int A[28],B[28],C[28],index,found=0;
    ifstream allocate;
    allocate.open("path_allocate.txt");
    for (int i = 0; i < 28; i++)
    {
        allocate >> A[i];
        allocate >> B[i];
        allocate >> C[i];
        

    }
    allocate.close();

    for (int i = 0; (i < 28) && found!=1; i++)
    {
        if(A[i]==q1 && B[i]==q2)
        {
            index=C[i];
            trace=pin[index][0];
            found=1;
            
            
            if (index<12)
            {
                count=1;
            }
            else if (index>=12 && index<22)
            {
                count=2;
            }
            
            else if(index>=22 && index<26)
            {
                count=3;
            }
            else
            {
                count=5;
            }
            
        }
        
    }

    if(found!=1)
    {
        cout<<"The following type of conversion is not possible\n";
    }
    else
    {
        while (p_count<count)
        {
            switch (trace)
            {   
                case 1:
                    
                    flag=pin[index][l_odd];
                    l_odd=l_odd+2;
                    
                
                    
                    value=km_to_m(value,flag);
                    break;
                case 2:
                    
                    
                    flag=pin[index][l_odd];
                    l_odd=l_odd+2;
                    
                
                    
                    value=m_to_cm(value,flag);
                    break;
                case 3:
                    
                    flag=pin[index][l_odd];
                    l_odd=l_odd+2;
                    
                
                    
                    value=ft_to_cm(value,flag);
                    
                    break;
                case 4:
                    
                    flag=pin[index][l_odd];
                    l_odd=l_odd+2;
                    
                
                     
                    value=in_to_cm(value,flag);
                    break;
                case 5:
                    flag=pin[index][l_odd];
                    l_odd=l_odd+2;
                    value=hr_to_min(value,flag);
                    break;
                case 6:
                    flag=pin[index][l_odd];
                    l_odd=l_odd+2;
                    value=min_to_sec(value,flag);
                    break;
                default:
                    break;
            }
            l_even=l_even+2;
            
            trace=pin[index][l_even];
            
            p_count++;
            
        }
        cout<<"Result: "<<container<<units[q1-1]<<" = "<<value<<units[q2-1]<<"\n";
    }
    
}
