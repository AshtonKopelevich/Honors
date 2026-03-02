#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using std::vector;
using std::string;
//This program is simple and find the minimum and maximum numbers from a csv file, and prints it. WHAT COULD GO WRONG?!!
//cast string to int safely
int string_to_int(string str)
{
    int number = 0;
    try 
    {
        number = std::stoi(str);
    } 
    catch (const std::invalid_argument& e) 
    {
        std::cerr << "Invalid argument: " << e.what() << std::endl;
    } 
    catch (const std::out_of_range& e) 
    {
        std::cerr << "Out of range: " << e.what() << std::endl;
    }
    return number;
}


//Process the csv file
vector<int> process_csv(string file_name)
{
    std::ifstream read_text(file_name);
    vector<int> values {};
    if(read_text)
    {
        while(!read_text.eof() && !read_text.eof())
        {
            string line = "";
            read_text >> line;
            
            //split a csv line into separate values
            string str_num = ""; //each unique number, but gotten raw from the string
            for(int i = 0; i < line.size(); i++)
            {
                if(line.at(i) == ',')
                {
                    int num = string_to_int(str_num);
                    values.push_back(num);
                    str_num = "";
                    continue;
                }
                str_num += line.at(i);
            }
        }
    }
    else
    {
        std::cerr << "Failed to open file" << std::endl;
    }
    read_text.close();
    return(values);
}


int main()
{
    return 0;
}
