#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;
using std::cout; using std::ofstream;
using std::endl; using std::string;


class Student
{
    int timestamp;
    char stockname[50];
public:
    void setData()
    {
        cout << "\nEnter timestamp. ";
        cin >> timestamp;
        cout << "Enter name of stock ";
        cin >> stockname;
    }

    void showData()
    {
        string filename("student.txt");
        ofstream file_out;

        file_out.open(filename, std::ios_base::app);
        file_out << stockname <<" "<< timestamp << endl;
        cout << "Done !" << endl;
        cout << "\nAdmission no. : " << timestamp;
        cout << "\nStudent Name : " << stockname;
    }
	 
    int retAdmno()
    {
        return timestamp;
    }
};

void display()
{
    ifstream inFile;
    inFile.open("student.bin", ios::binary);
    ofstream outFile;
    outFile.open("student.txt", ios::out);

    Student obj;

    // string filename("student.txt");
    // ofstream file_out;

    // file_out.open(filename, std::ios_base::app);
    // file_out << "Some random text to append." << endl;
    // cout << "Done !" << endl;

    while(inFile.read((char*)&obj, sizeof(obj)))
    {
        obj.showData();
        // file_out << "Some random text to append." << endl;
    }        
    
    inFile.close();
    outFile.close();
}


bool sortbysec(const pair<string,int> &a,
              const pair<string,int> &b)
{
    return (a.second < b.second);
}
  

vector<string> split(string str, string token){
    vector<string>result;
    while(str.size()){
        int index = str.find(token);
        if(index!=string::npos){
            result.push_back(str.substr(0,index));
            str = str.substr(index+token.size());
            if(str.size()==0)result.push_back(str);
        }else{
            result.push_back(str);
            str = "";
        }
    }
    return result;
}

int main()
{
  fstream f1,f2,f3; 
  string str1,str2; //str1 for fetching string line from file 1 and str2 for fetching string from file2
  
   cout << "\nList of records";
    display();
  f1.open("file1.txt",ios::in);//opening file in reading mode
  f2.open("student.txt",ios::in);
  f3.open("file3.txt",ios::out);//opening file in writing mode

   while(getline(f1, str1)){ //read lines from file object and put it into string and push back to file 3.
         f3<<str1; // inserting the fetched string inside file3
         f3<<endl;
      }

   while(getline(f2, str2)){ //Same step for file 2 to file 3 fetching
         f3<<str2;
         f3<<endl;
      }

   f1.close();
   f2.close();
   f3.close();


   fstream newfile;
   vector< pair<string,int>> sent;
 newfile.open("file3.txt",ios::in); //open a file to perform read operation using file object
   if (newfile.is_open()){   //checking whether the file is open
      string tp;
      while(getline(newfile, tp)){ //read data from file object and put it into string.
         cout << tp << "\n"; //print the data of the string
         sent.push_back(make_pair(split(tp," ")[0],stoi(split(tp," ")[1]))); //push back the string to vector
      }
      newfile.close(); //close the file object.
   }
   // cout << sent[0][1]<<endl; //
   // sort(sent[0].begin(), sent[0].end());
   // cout << "--------------------: "<< endl;
   // for(int i=0;i<sent.size();i++){
   //    for(int j=0;j<sent[i].size();j++){
   //       cout<<sent[i][j]<<endl;
   //    }
   //    cout<<endl;
   // }

   sort(sent.begin(), sent.end(), sortbysec);
  
    // Printing the sorted vector(after using sort())
    cout << "The vector after sort operation is:\n" ;
    for (int i=0; i<sent.size(); i++){
        cout << sent[i].first << " " << sent[i].second << endl;
    }
 
    return 0;
   // return 0;
}