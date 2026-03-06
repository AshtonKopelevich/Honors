#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <limits>

using std::vector;
using std::string;
using std::cout;
using std::cin;
//This program is simple and reads a csv file before sorting the data and printing the min and max. 
//WHAT COULD GO WRONG?!!

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
            for(size_t i = 0; i < line.size(); i++)
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
            if(line.at(line.size()-1) != ',')
            {
               int num = string_to_int(str_num);
               values.push_back(num);
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

//This algorithm sorts numbers using insertion sort
vector<int> sort_numbers(vector<int> numbers){
    vector<int> numbers_sorted{};
    bool is_inserted = false; // checks if the number has already been inserted into the sorted vector

    for(unsigned int i = 0; i< numbers.size(); i++){// iterate through list one
        is_inserted = false;

        for(unsigned int j = 0; j< numbers_sorted.size(); j++){// iterate through list two per value in list one
            if(numbers.at(i) < numbers_sorted.at(j)){
                numbers_sorted.insert(numbers_sorted.begin()+j, numbers.at(i));
                is_inserted = true;
                break;//breaks out when found
            }
        }

        if(!is_inserted){
            numbers_sorted.push_back(numbers.at(i));
        }
    }
    return numbers_sorted;
} 

//This prints the minimum, maximimum, as well as the sorted form of the vector
void print_vector(vector<int> numbers)
{
    numbers = sort_numbers(numbers);
    cout << "Minimum: " << numbers.at(0) << std::endl;
    cout << "Maximum: " << numbers.at(numbers.size()-1) << std::endl;
    cout << "Sorted vector: [";
    for(size_t i = 0; i < numbers.size()-1; i++)
    {
        cout << numbers.at(i) << ",";
    }
    cout << numbers.at(numbers.size()-1) << "]" << std::endl;
}

int main()
{
    string fileName = "";
    cout << "Enter a filename" << std::endl;
    cin >> fileName;
    vector<int> nums = process_csv(fileName);
    if(nums.size() == 0)
    {
        cout << "An error occured, exiting" << std::endl;
        return 1;
    }
    print_vector(nums);
    return 0;
}