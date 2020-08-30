#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char *argv[])
{
    using namespace std;
    if(argc != 3)
    {
        return 0;
    }
    fstream f(argv[1], ios::in);
    fstream out(argv[2], ios::out | ios::trunc);
    string str, strout;
    while (!f.eof())
    {
        std::getline(f,str);
        if (str.compare("\n") == 0)
            continue;
      	if(!str.empty())		
      	{
            int len = str.size();
            int count = 1;
            for (int i = 0; i < len;)
            {
                switch (str[i])
                {
                case '/':
                    if (str[i+1] == '/')
                        i = len;
                    else
                    {
                        strout += str[i++];
                    }
                    break;
                case ' ':
                    
                    while (str[++i] == ' ')
                    {    ++count;
                    } 
                    if(count == 4)
                    {
                        count = 1;
                        strout += "    ";
                    }   
                    else
                    {
                        if (str[i] >= 'a' && str[i] <= 'z' || str[i] >= 'A' && str[i] <= 'Z')
                            strout += ' ';
                        else if(str[i] >= '0' && str[i] <= '9')
                            strout += ' ';
                    }
                    break;
                case ',':
                case '=':
                case ';':
                case '>':
                case '<':
                case '!':
                    strout += str[i];
                    while (str[++i] == ' ')
                        ;
                    break;
                default:
                    strout += str[i++];
                }
            }
            out << strout.c_str() << "\n";
            strout.clear();
            str.clear();
        }
   	}
    f.close();
    out.close();
    return 0;
}
