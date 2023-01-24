#include <fstream>
#include <iostream>
#include <string>
#include <locale.h>
#include <windows.h> 


using namespace std;



void clean() {

    string line;

    ifstream in;       // поток для чтения
    ofstream out;

    out.open("C://mygame//Russian-Nouns-main//dist//russian_nouns_with_definition_edited.txt");
    in.open("C://mygame//Russian-Nouns-main//dist//russian_nouns_with_definition_hand_edited.txt");

    char two = '2';

    while (getline(in, line))
    {
        int length = line.length();
        int j = 0;
        string temp;
        bool flag = true;
        if (line.find("F") != string::npos)
            continue;
        out << endl;
        while (line[j] != '\0') {
            if (line[j] == two) {
                if(temp.length() > 3)
                    out << temp;
                flag = false;
                break;
            }
            else {
                if (line[j] != ',' && line[j] != ';' && line[j] != '(' && line[j] != ')' && line[j] != '"')
                    temp += line[j];
                if (line[j] == '"')
                    temp += "^";
                j++;
            }

        }
        if (flag)
            out << temp;
    }

    in.close();
    out.close();
}

void makeMas() {


    string line;

    ifstream in;       // поток для чтения
    ofstream out;

    in.open("C://mygame//Russian-Nouns-main//dist//russian_nouns_with_definition_edited.txt");
    out.open("C://mygame//Russian-Nouns-main//dist//russian_nouns_with_definition_ready.txt");

    char two = '2';
    out << "[" << endl;
    while (getline(in, line))
    {
        int length = line.length();
        int j = 0;
        string temp, name, description;
        bool flag = true;

        int index = line.find(":");
        while (line[j] != '\0') {
            if (j < index) {
                name += line[j];
                if (j + 1 == index)
                    j+=2;
            }
            else {
                description += line[j];
            }
            j++;
        }
        out << "{" << endl << "000" << "name" << "000:" << "000" << name << "000" << "," << endl << "000" << "description" << "000:" << "000" << description << "000"  << endl << "}" << ",";
    }
    out << "]" << endl;
    in.close();
    out.close();
}

int main()
{
    setlocale(LC_ALL, "");
    /*clean();
    makeMas();*/
}