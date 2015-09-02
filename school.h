#include <string>
using namespace std;

class School{

public:

	//CONSTRUCTOR
	School(string& school_name, int num_slots){school_name_ = school_name; num_slots_ = num_slots;}
	
	//ACCESSORS
	string GetName() const {return school_name_;}
	int MaxAcceptedStudents(){return num_slots_;}
	int NumAcceptedStudents(){return NumAcceptedStudents_;}
	list<string> Get(){return Enrollment_;}
	
	//MODIFIERS
	void AddStudent(string& student_name);
	void InsertStudent(string new_student_name, string insert_before_student_name);
	void Set(list<string> a){Enrollment_.clear(); Enrollment_ = a;}

	//PRINT FUNCTION
	void PrintSchoolPreference(ostream& ostr) const;
	void PrintSchoolEnrollment(ofstream& ostr);

	//OTHERS
	void PrepareToMakeOffers(){NumAcceptedStudents_ = 0; count_ = 0;}
	string MakeNextOffer();
	void StudentDeclinesTentativeAcceptance(string student);
	void StudentTentativelyAcceptsOffer(string student);

private:

	//REPRESENTATIVES
	string school_name_;
	int num_slots_;
	list <string> preference_;
	int NumAcceptedStudents_;
	int count_;
	list <string> Enrollment_;
};

// add a student into school's preference and test whether that student is already in the list
void School::AddStudent(string& student_name){
  bool test = true;
  for (list<string>::iterator ite = preference_.begin(); ite != preference_.end(); ite++)
	  test = test && (*ite != student_name);
  if (test)
	preference_.push_back(student_name);
  else
	  cerr<<"WARNING: could not add "<<student_name<<" into school preference list, this student is already in the list"<<endl;
}

// insert a student into school's preference, test whether that student already in the list
void School::InsertStudent(string new_student_name, string insert_before_student_name){
	 
	bool test = false;
	for (list<string>::iterator ite = preference_.begin(); ite != preference_.end(); ite++)
		test = test || (*ite == insert_before_student_name);
	if (test){

		list<string>::iterator ite = preference_.begin();
	while (*ite != insert_before_student_name)
		ite++;
		preference_.insert(ite, new_student_name);}
	else
		cerr<<"WARNING: could not insert new student into school preference list before "<<insert_before_student_name<<", this student is not in the list"<<endl;
}

//print the school's preference list
void School::PrintSchoolPreference(ostream& ostr) const{
	int n = 0;
	for (list<string>::const_iterator itr = preference_.begin(); itr != preference_.end(); itr++){
	    n++;
		ostr.width(3);
		ostr<<right<<n<<"."<<" "<<*itr<<endl;
	}
}

//print the enrollment list after all rounds
void School::PrintSchoolEnrollment(ofstream& ostr){
	ostr<<"student(s) who will be attending "<<school_name_<<":"<<endl;
	

	for (list<string>::iterator ite = Enrollment_.begin(); ite != Enrollment_.end(); ite++) 
		ostr<<"  "<<*ite<<endl;
	if (num_slots_-NumAcceptedStudents_ !=0)
	ostr<<"  ["<<num_slots_-NumAcceptedStudents_<<" remaining slot(s) in enrollment]"<<endl;



}

// for sorting purpose
bool alpha_by_school_name(const School school1, const School school2){
	return school1.GetName() < school2.GetName();
}

// every time called, return a student name
// that student is going to recieve the offer
string School::MakeNextOffer(){
	list<string>::iterator ite = preference_.begin();
	
	if (NumAcceptedStudents_ == num_slots_ || count_ == preference_.size())
    {  return "";
	}
	else{
		if (count_ != 0){ 
		for (int i = 0; i<count_; i++)
			ite++;}
		
		count_++;
		
		
	  return *ite;
	  
}

}

// when the tentative acceptance is declined, call this fucntion and make changes to representatives
void School::StudentDeclinesTentativeAcceptance(string student){
	if (NumAcceptedStudents_==0)
		NumAcceptedStudents_ = 0;
	else
		NumAcceptedStudents_--;
    for (list<string>::iterator ite = Enrollment_.begin(); ite != Enrollment_.end(); ite++) 
	if (*ite == student)
		ite =  Enrollment_.erase(ite);}

//when student tentatively accept that offer, call this function
void School::StudentTentativelyAcceptsOffer(string student){
	NumAcceptedStudents_++;
	Enrollment_.push_back(student);
}

//for sorting purpose
bool alpha(const string student1,const string student2){
	return student1 < student2;
}
