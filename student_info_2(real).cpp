#include <iostream>
#include <fstream>
using namespace std;
class Student
    {
    public:
        int roll;
        char name[20];
        char div;
        char address[20];
    void input()
    {
        cout << "Enter roll no. "; cin >> roll;
        cout << "Enter name "; cin >>name;
        cout << "Enter div "; cin >>div;
        cout << "Enter address "; cin >>address;
    }
    void output()
    {
        cout << endl<<"Roll no. is " << roll << endl; cout <<
        "Name is " << name << endl; cout << "Div is "
        << div << endl;
        cout << "Address is " << address << endl; cout <<
        "\n";
    }
    void write()
    {
        ofstream File;
        File.open("File.dat", ios::binary | ios::app);
        Student obj;
        obj.input();
        File.write((char *)&obj, sizeof(obj));
        File.close();
    }
    void display()
    {
        ifstream File; 
        File.open("File.dat", ios::binary);
        Student obj;
        while (File.read((char *)&obj, sizeof(obj)))
            {
            obj.output();
            }
        File.close();
    }
    void search(int n)
    {
        ifstream File; 
        File.open("File.dat",ios::binary); 
        int fl = 0;
        Student obj;
        while (File.read((char*)&obj, sizeof(obj)))
            {
            if (obj.roll == n)
                {
                obj.output();
                fl = 1;
                break;
                }
            }
        if (fl == 0)
        cout << "No records";
        File.close();
    }
    void Delete(int n)
    {
    Student obj; 
    ifstream File;
    File.open("File.dat", ios::binary);
    ofstream Temp; 
    Temp.open("TempFile.dat",ios::binary);
    while (File.read((char *)&obj, sizeof(obj)))
        {
        if (obj.roll != n)
            {
            Temp.write((char *)&obj, sizeof(obj));
            }
        }
    File.close();
    Temp.close();
    remove("File.dat"); 
    rename("TempFile.dat","File.dat");
    }
    };
int main()
    {
    int choice;
    char ch;
    int n, rollno, search;
    Student obj;
    do
        {
        cout << "1.Add records\n2.Display records\n3.Search record\n4.Delete record" << endl;
        cin >> choice;
        switch (choice)
            {
            case 1:
                cout << "enter how many records? ";
                cin >> n;
                for (int i = 0; i < n; i++)
                {
                obj.write();
                cout << endl;
                }
                break;
            case 2:
                obj.display();
                cout << endl;
                break;
            case 3:
                cout<<"enter roll no. to search "; 
                cin>>search;
                obj.search(search); cout << endl;
                break;
            case 4:
                cout << "\nEnter the rollno. to delete"; 
                cin >> rollno;
                obj.Delete(rollno); cout << endl;
                break;
            default:
                cout << "invalid choice"; 
                break;
            }
        cout << "Do you want to continue? press y else n "; cin >>
        ch;
        } while (ch == 'y');
        return 0;
    }