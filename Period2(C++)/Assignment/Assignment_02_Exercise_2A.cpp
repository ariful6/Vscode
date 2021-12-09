// Exercise 2A

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string find_field(const string &xml, string tag_name);

int main() {
	string page, line, location, temperature;
	ifstream inputFile("weather.xml");
	
	while (getline (inputFile, line)) {
 	    page.append(line);
 	    line.erase();
	}
    
    location = find_field(page, "location");
    temperature = find_field(page, "temp_c");
	
	cout << "Location: " << location << endl;
	cout << "Temperature: " << temperature << endl;
	
}

string find_field(const string &xml, string tag_name)
{
    string start_tag = "<" + tag_name + ">";
    string end_tag = "</" + tag_name + ">";
    string inner;

    size_t pos1 = xml.find(start_tag);
    size_t pos2 = xml.find(end_tag);
    if (pos1 != string::npos && pos2 != string::npos) {
        pos1 += start_tag.size();                       // position after start_tag
        pos2 -= pos1;                                   // length of the string between tags
        inner = xml.substr(pos1, pos2);                  //string between tags
    }
    if (pos1 == string::npos || pos2 == string::npos){   //returning not found if either start and end tag not found
        return "not found";
    }
    return inner;

}
