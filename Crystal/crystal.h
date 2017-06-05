#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>

using namespace std;

//寻找crystal的地址
string find_add()
{
    string add,lc_script;
    ifstream ini,script;                 //定义处理输入的ifstream类对象 
    ini.open("crystal.ini");             //读取配置文件
    if(ini.fail())
    {
           ofstream out_ini;             //定义处理输出的ofstream类对象 
           out_ini.open("crystal.ini");  //关联配置文件 
           out_ini<<"script\\crystal.lc";//修改配置信息 
           add = "script\\crystal.lc";   //代入crystal的地址 
           out_ini.close();              //close关联 
    }
    else
    {
        ini>>add;
    };
    ini.close();
    script.open("script\\crystal.lc");
    //script.open(add);
    while(script.eof()!=true)
    {
         if(lc_script!="")
             lc_script += "\n";
         script>>add;
         lc_script += add;
    };
    script.close();
    return lc_script;
}

//处理脚本
void change_txt(string & script)
{
    /*
    //string &replace(删除开始,删除字符数,插入次数,插入字符);
    //string &replace(删除开始,删除字符数,插入字符串);
    
    //<if>=33 
    while(txt.find("<if>")!=string::npos){int num=txt.find("<if>"); txt.replace(num,4,1,33);};
    //<end>=34
    while(txt.find("<end>")!=string::npos){int num=txt.find("<end>"); txt.replace(num,5,1,34);}; 
    //回车=35
    while(txt.find("\n")!=string::npos){int num=txt.find("\n"); txt.replace(num,1,1,35);}; 
    //分号；=36
    while(txt.find("；")!=string::npos){int num=txt.find("；"); txt.replace(num,1,1,36);}; 
    //局部变量@=37，结尾标记=38 
    int bianliang = 0;  //变量个数 
    while(txt.find("@")!=string::npos)
    {
           bianliang += 1;
           int num=txt.find("@");
           txt.replace(num,1,1,37);
           int find_num = num;
           //命名空间：ASCII：48-57,65-90,95,97-122 &&  0-9,A-Z,_,a-z
           while((txt[find_num]>=48&&txt[find_num]<=57)||(txt[find_num]>=65&&txt[find_num]<=90)||
                 (txt[find_num]>=95)||(txt[find_num]>=97&&txt[find_num]<=122)){find_num+=1;};
           string find_name = txt.substr(num+1,find_num-num+1);
           string bianliang_num;
           stringstream int_to_string;
           
           cout<<find_name<<endl; 
           cout<<txt[find_num]<<endl;
           
           int_to_string<<bianliang;
           int_to_string>>bianliang_num;
           txt.replace(num+1,find_name.size(),bianliang_num+"&");  //%为37，&为38 
           while(txt.find("@"+find_name)!=string::npos){num=txt.find("@"+find_name);
                 txt.replace(num,find_name.size()+1,"%"+bianliang_num+"&");};
    }; 
    return txt;
    */
    int i = 0;
    while(i<script.length())
    {
        switch(script[i])
        {
            case LC_DOING_START:
            {
                 int n = script.find(LC_DOING_END,i);
                 string s;
                 s.assign(script,i,n-i+1);
                 if(s==LC_IF)
                     script.replace(i,L_IF,1,N_IF);
                 else if(s==LC_PRINT)
                     script.replace(i,L_PRINT,1,N_PRINT);
                 else
                     cout<<"error!!!"<<endl;
                 i+=1;
                 break;
            }
            case '\"':
            {
                 int n = script.find('\"',i+1);
                 i=n+1;
                 break;
            }
            case LC_ENDL:
            {
                script.replace(i,L_ENDL,1,N_ENDL);
                i+=1;
                break;
            }
        };
    };
    return;
}

//脚本执行 
void run(string & script)
{
     int i=0;
     sign:switch(script[i])
     {
         case N_PRINT:
         {
              switch(script[i+1])
              {
                  case '\"':
                  {
                       int n = script.find('\"',i+2);
                       string s;
                       s.assign(script,i+2,n-i-2);
                       cout<<s;
                       i=n+1;
                       goto sign; 
                  }
              };
         }
         case N_ENDL:
         {
              i++;
              goto sign;
         }
     };
     return;
}



//处理函数
int crystal()
{
    string lc_script = find_add();
    change_txt(lc_script);
    
    cout<<"下面是经处理的脚本：\n"; 
    cout<<lc_script<<endl<<endl;
    cout<<"下面是脚本执行：\n"; 
    
    run(lc_script);
    
    return 0;
} 

