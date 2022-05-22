//TODO: if rollno already exist warn the user
//TODO: Add semester and Email ID
#include <iostream>
#include <string>
#include <vector>

class Student{
    private:
    std::string rollno, name, course,eID;
    int fees,sem; //semester
    std::string usrnme="admin";
    std::string pswd="admin"; // password
    std::vector<std::string> key{}, nameList{}, courseList{}, eIDList{}; //roll no is key
    std::vector<int> feesList{}, semList{};



    public:
    bool verfication(std::string str){
        if(str==pswd) return true;
        else return false;
    }

    void setName(std::string nm){   name= nm;   }

    std::string getName(){  return name;    }

    bool loginMenu(){
        std::string username, pass; 
        while(1){
            std::cout<<"Enter your username: \n";
        std::cin>>username;
        std::cout<<"Enter your password: \n";
        std::cin>>pass;

        if(username==usrnme && pass==pswd){
            std::cout<<"\n\t***Access granted!***\n";
            return true;
        } 
        else return false;
        }
    }
    void mainMenu(){
        int choice;
        bool breakOrNot=false;
        while(1){
        if(breakOrNot) break;
        std::cout<<"\n\nSelect any one option: \n\n";
        std::cout<<"1. View student's details\n2. Edit student's details\n3. Add a new student\n4. Exit\n\nchoice:";
        std::cin>>choice;

        if(choice==1){ //View student's details
            std::cout<<"Enter student's roll no to view its details:\n";
            std::cin>>rollno;
            int i;
            for(i=0;i<key.size();i++) if(key[i]==rollno) break;

            
            std::cout<<"\nRoll no: "<<key[i]<<"\nName: "<<nameList[i]<<"\nCourse: "<<courseList[i]<<"\nSemester: "<<semList[i]<<"\nFees: "<<feesList[i]<<"\nEmail ID: "<<eIDList[i]<<"\n\n";
            // std::cout<<<<"\t\t"<<<<"\t\t"<<<<'\t'<<<<'\n';
            // breakOrNot= true;
            
        }
        else if(choice==2){ //Edit student's detail
            std::cout<<"Enter student's roll no:\n";
            std::cin>>rollno;
            int i;
            for(i=0;i<key.size();i++){
              if(key[i]==rollno){
                std::cout<<"\t***Match found!***\n\nStudent name: "<<nameList[i]<<"\n\nSelect which detail you want to edit.\n\n";
                std::cout<<"\n1. Roll no\n2. name\n3. Course\n4. Email Id\n5. Semester\n6. Fees\n";
                }
            }
        }
        
        else if(choice==3){ //Add a new student
            std::cout<<"Enter student roll no\n";
            std::cin>>rollno;
            key.push_back(rollno);
            
            std::cout<<"Enter student name:\n";
            std::getline(std::cin>>std::ws, name);
            // std::cin>>name;
            nameList.push_back(name);

            std::cout<<"Enter student's course:\n";
            std::cin>>course;
            courseList.push_back(course);

            std::cout<<"Enter student's semester:\n";
            std::cin>>sem;
            semList.push_back(sem);

            std::cout<<"Enter student's fee:\n";
            std::cin>>fees;
            feesList.push_back(fees);
            
            std::cout<<"Enter student's email ID:\n";
            std::cin>>eID;
            eIDList.push_back(eID);
             
            // breakOrNot= true;
        }
        else if(choice==4) breakOrNot= true;

        else std::cout<<"\n\nPlease enter a valid choice! \n\n";
        
        }
        
        
      }


};

int main(){
    int choice;
    Student sdt;
    std::cout<<"\n\t***Version: 2.0***\n\n";
    std::cout<<"Press 1 for menu or 0 exit\n";
    std::cin>>choice;

    if(choice==1){
        if(sdt.loginMenu()==true){
            sdt.mainMenu();
        }
        else{
            std::cout<<"Wrong username or password. Please try again!\n";
            sdt.loginMenu();
        }
    }
    return 0;
}