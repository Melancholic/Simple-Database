#ifndef DATA_H
#define DATA_H
#include<fstream>
#include<iostream>
#include<string>
#include<vector>
enum TypeCall {ID,AGE,FIRSTNAME,SECONDNAME,SALARY};
struct rec{
	long int ID;	
	std::string FirstName;
	std::string SecondName;
	int Age;
	long int Salary;
	rec(long int id, std::string fname,std::string sname,int age, long int salary);
	rec(const rec& a);
	rec();
	void operator=(const rec& a);
	bool operator<(const rec a)const;
};
class base{
	std::vector<rec>records;
	std::ofstream file;
	bool read_from_file();
	bool write_to_file(rec &a);
public:
	base();
	void add_new_rec(std::string fname,std::string sname,int age, long int salary);
	long int get_id(rec &a);
	std::string get_fname(rec &a);
	std::string get_sname(rec &a);
	long int get_salary(rec &a);
	int get_age(rec &a);
	rec get_rec(long int a);	
	void sort(TypeCall val);
//	void resort(TypeCell val);
	void delete_rec(long int a);
	long int get_ind_rec(long int a);
	long int get_id_rec(std::string fname,std::string sname);	
	void save_as(char *fname);
	~base();
};

bool sort_fname(rec a, rec b);
bool sort_sname(rec a, rec b);
bool sort_age(rec a, rec b);
bool sort_salary(rec a, rec b);
/*bool resort_fname(rec &a, rec &b);
bool resort_sname(rec &a, rec &b);
bool resort_age(rec &a, rec &b);
bool  resort_salary(rec &a, rec &b);
*/
long int string_to_int(std::string s);
std::string int_to_string(long int a);
	
	
	
	
#endif 
