#include"data.h"
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
rec::rec(long int id, std::string fname,std::string sname,int age, long int salary){
	ID=id;
	FirstName=fname;
	SecondName=sname;
	Age=age;
	Salary=salary;
}
bool rec::operator<(const rec a)const{
	return ID<=a.ID;
}
rec::rec(){
	ID=0;
	FirstName=" ";
	SecondName=" ";
	Age=0;
	Salary=0;
}

rec::rec(const rec& a){
	ID=a.ID;
	FirstName=a.FirstName;
	SecondName=a.SecondName;
	Age=a.Age;
	Salary=a.Salary;
}
void rec::operator=(const rec& a){
         ID=a.ID;
         FirstName=a.FirstName;
         SecondName=a.SecondName;
         Age=a.Age;
         Salary=a.Salary;
}
	
base::base(){
	file.open("data.db", std::ios_base::app);
	std::cout<<"\nThe base found, loaded...\n";
	if(read_from_file()){
	
		std::cout<<"\n The base loaded. You can work with base. \n";
	}else{
		std::cout<<"\n The base is  not found, a created new";
	}
}
bool base::read_from_file(){
	std::ifstream file_read("data.db");
//	int StrLen=1024;
	long int id,salary;
	int age;
	std::string sname,fname;
	std::string tmp;
	std::getline(file_read,tmp);
	//std::cout<<"tmp: "<<tmp1;
	if(tmp.size()){
		while(tmp.size()){
	//		std::cout<<"\nStr: "<<tmp<<"\n";
	//	char* tmp1;
	//	file_read.getline(tmp1,StrLen);
		int ind=0;
		std::string strtmp=tmp.substr(ind,tmp.find(" ",ind));
		
			id=string_to_int(strtmp);
		tmp.erase(0,strtmp.size()+4);
               strtmp=tmp.substr(0,tmp.find(" "));
                	fname=strtmp;
                tmp.erase(0,strtmp.size()+1);
		
                strtmp=tmp.substr(0,tmp.find(" "));
                	sname=strtmp;
                tmp.erase(0,strtmp.size()+1);
                strtmp=tmp.substr(0,tmp.find(" "));
              //  std::cout<<"\n"<<tmp<<"\n"

			age=string_to_int(strtmp);
                tmp.erase(0,strtmp.size()+1);
                strtmp=tmp.substr(0,tmp.find(" "));
		//std::cout<<"\n"<<strtmp<<"\n";
                	salary=string_to_int(strtmp);
                tmp.erase(0,strtmp.size()+1);
//			std::cout<<" "<<sname<<" "<<age<<" "<< salary<<"\n";
		records.push_back(rec(id,fname,sname,age,salary));
		std::getline(file_read,tmp);
		}
	return 1;
	}else{
		return 0;
	}	
}

 void base::add_new_rec(std::string fname,std::string sname,int age, long int salary){
	long int id;
	if(records.size()){
		sort(ID);
		id=records[records.size()-1].ID+1;
	}else{
		id =0;
	}
	records.push_back(rec(id,fname,sname,age,salary));
//	records.push_back();
}
bool base::write_to_file(rec &a){
//	if(file.is_open()){
//		file.close();}
//	file.open("data.db");
	return file<<a.ID<<"    "<<a.FirstName<<" "<<a.SecondName<<" "<<a.Age<<" "<<a.Salary<<"\n";
}

long int base::get_id(rec &a){
	return a.ID;
}
std::string base::get_fname(rec &a){
	return a.FirstName;
}

std::string base::get_sname(rec &a){
	return a.SecondName;
}

long int base::get_salary(rec &a){
	return a.Salary;
}

int base::get_age(rec &a){
	return a.Age;
}
rec base::get_rec(long int a){
	for(int i=0;i!=records.size();++i){
		if(records[i].ID==a)return records[i];
	}
}

void base::sort(TypeCall val){
	switch(val){
		case AGE: std::sort(records.begin(),records.end(),sort_age);break;
		case ID: std::sort(records.begin(), records.end());break;
		case FIRSTNAME: std::sort(records.begin(), records.end(), sort_fname);break;
		case SECONDNAME: std::sort(records.begin(), records.end(),sort_sname);break;
		case SALARY: std::sort(records.begin(), records.end(),sort_salary);break;
		default: std::cout<<"\nBad Request!\n";
	}
}

void base::delete_rec(long int a){
	std::vector<rec>::iterator i;
	for(i=records.begin();i!=records.end();++i){	
		if (records[i-records.begin()].ID==a){
			records.erase(i,i+1);
			return;	
		}
	}
}

long int base::get_ind_rec(long int a){
        for(long int i=0;i!=records.size();++i){    
                if (records[i].ID=a){
                        return i; 
                }
        }   
}

long int base::get_id_rec(std::string fname,std::string sname){
        for(long int i=0;i!=records.size();++i){
                if (records[i].FirstName==fname && records[i].SecondName==sname){
                        return records[i].ID;
                }
        } 
}

void base::save_as(char  *fname){
	std::ofstream NewFile;
	NewFile.open(fname);
	for(long int i=0;i!=records.size();++i){
		NewFile<<"\n"<<records[i].ID<<"    "<<records[i].FirstName<<" "<<records[i].SecondName<<" "<<records[i].Age<<records[i].Salary;
	}
	NewFile.close();
}

base::~base(){
	std::vector<rec>::iterator i;
	std::cout<<records.size();
        if(file.is_open()){
		file.close();}
	file.open("data.db");

	for(i=records.begin();i!=records.end();++i){
		write_to_file(*i);
	}
	file.close();
}
		
bool sort_fname(rec a, rec b){
	return a.FirstName[0]<b.FirstName[0];
}
bool sort_sname(rec a, rec b){
	return a.SecondName[0]<b.SecondName[0];
}
bool sort_age(rec a, rec b){
	return a.Age>b.Age;
}
bool sort_salary(rec a, rec b){
	return a.Salary>b.Salary;
}

/*bool resort_fname(rec &a, rec &b){
	return a.FirstName[0]<b.FirstName[0];
}
bool resort_sname(rec &a, rec &b);
bool resort_age(rec &a, rec &b);
bool  resort_salary(rec &a, rec &b){
*/	

std::string int_to_string(long int a){ 
        std::string tmp;
        if(a==0) tmp="0";
        if (a<10&&a>0) tmp=(a+'0');
        if (a>10 &&a<100){ 
                std::string tmp1;
                tmp1=a/10+'0';
                long int tmp2=a-(a/10)*10;
                tmp=tmp2+'0';
                tmp=tmp1+tmp;
	}    
	return tmp;

}

long int string_to_int(std::string s){ 
	long int n;
        std::istringstream ist(s);
  ist >> n;
        return n;
}


