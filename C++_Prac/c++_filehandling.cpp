#include <iostream>
#include <fstream>

using namespace std;
string str;

int main(int argc, char *argv[])
{
    ofstream filestream("test.txt");
    if (filestream.is_open())
    {
        filestream << "Inserting the data in a new file\n";
        filestream.close();
    }
    else
    {
        cout << "File is closed" << endl;
    }
    ifstream file("test.txt");
    if (file.is_open())
    {   
        while (getline(file, str))
        {
            cout << str << endl;
        }
        filestream.close();
    }
    else{
        cout << "File is closed" << endl;
    }

    return 0;
}