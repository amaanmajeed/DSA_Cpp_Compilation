#include <iostream>
#include <iterator>
#include <map>

using namespace std;
int main()
{
	// empty map container
	map<int, string> Students;
	// insert elements in random order
	Students.insert(pair<int, string>(1, "Ahmad"));
	Students.insert(pair<int, string>(2, "Rizwan"));
	Students.insert(pair<int, string>(3, "Zamir"));
	Students.insert(pair<int, string>(4, "Shahid"));
	Students.insert(pair<int, string>(5, "Sadia"));
	Students.insert(pair<int, string>(6, "Mirha"));
	Students.insert(pair<int, string>(7, "Khalil"));
	Students.insert(pair<int, string>(8, "Shaista"));

	// printing map Students
	map<int, string>::iterator itr;
	cout << "\nThe map Students is : \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = Students.begin(); itr != Students.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
	cout << endl;

	// Delete the record containing roll no. 2
	int num;
	cout << "Enter the roll: ";cin >> num;
	cout << "Delete the record containing roll no. "<< num << endl;

	num = Students.erase(num);
	cout << num+1 << " removed \n";
	cout << "\tKEY\tELEMENT\n";
	for (itr = Students.begin(); itr != Students.end(); ++itr) {
		cout << '\t' << itr->first << '\t' << itr->second << '\n';
	}
	cout << endl;

	//Search the student enter by user
	int roll_num;
	cout << "Search the student enter by user" << endl;
	cout << "Enter the roll : ";cin >> roll_num;
    cout << "Output:" << endl;

    for (itr = Students.begin(); itr != Students.end(); ++itr) {
        if(itr->first == roll_num){
            cout << "Name : \t" << itr->second <<endl<< "Roll Number : \t" << itr->first << '\n';
            }
	}


    // assigning the elements from gquiz1 to gquiz2
    map<int, int> Copy_Students(Students.begin(), Students.end());

    //Remove all the students having even roll no.
    for (itr = Students.begin(); itr != Students.end(); itr++) {
        	itr = Students.erase(itr);
    }

}
