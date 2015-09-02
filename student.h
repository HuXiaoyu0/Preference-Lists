#include <string>
using namespace std;

class Student{

public:

	//CONSTRUCTOR
	Student(string student_name){student_name_ = student_name;}

	//MODIFIERS
	void AddSchool(string school_name);
	void RemoveSchool(string school_name);
	
	//ACCESSORS
	string GetName() const {return student_name_;}
	bool HasOffer(){return HasOffer_;}
	string GetBestOffer(){return BestOffer_;}
	
	//OTHERS
	void PrintStudentPreference(ostream& ostr) const;
	void PrintStudentDecision(ofstream& ostr) const;
	void PrepareToReceiveOffers(){HasOffer_ = false; BestOffer_ = "";}
	bool IsOfferTentativelyAccepted(string school_name);


private:

	//REPRESENTATIVES
	string student_name_;
	list <string> preference_;
	bool HasOffer_;
	string BestOffer_;
};

//add school into student's preference list and test whether the schoold already exists
void Student::AddSchool(string school_name){
  bool test = true;
  for (list<string>::iterator ite = preference_.begin(); ite != preference_.end(); ite++)
	  test = test && (*ite != school_name);
  if (test)
	preference_.push_back(school_name);
  else
	  cerr<<"WARNING: could not add "<<school_name<<" into student preference list, this school is already in the list"<<endl;
}

//remove the school from a school's preference list
void Student::RemoveSchool(string school_name){
	bool test = false;
  for (list<string>::iterator ite = preference_.begin(); ite != preference_.end(); ite++)
	  test = test || (*ite != school_name);
  if (test){
	list<string>::iterator ite = preference_.begin(); 
	while (*ite != school_name)
		ite++;
	preference_.erase(ite);}
  else
	  cerr<<"WARNING: could not remove "<<school_name<<" from student preference list, this school is not in the list"<<endl;
}

//print the student's preference list
void Student::PrintStudentPreference(ostream& ostr) const{
	int n = 0;
	for (list<string>::const_iterator itr = preference_.begin(); itr != preference_.end(); itr++){
	    n++;
		
		ostr<<"  "<<n<<"."<<" "<<*itr<<endl;
	}
}

//print the student's decision after all rounds
void Student::PrintStudentDecision(ofstream& ostr) const {
	if (BestOffer_ != "")
	ostr<<student_name_<<" will be attending "<<BestOffer_<<endl;
	else
	ostr<<student_name_<<" has not received an acceptable offer"<<endl;
}

//for sorting purpose
bool alpha_by_student_name(const Student student1, const Student student2){
	return student1.GetName() < student2.GetName();
}

//when a offer given to a student, call this function to see
// whether student has had a offer
//if yes, also to see whether the new offer is better than the old one
bool Student::IsOfferTentativelyAccepted(string school_name){
	bool IsPref = false;
	for (list <string>::iterator ite0 = preference_.begin(); ite0 != preference_.end(); ite0++)
		IsPref = IsPref || (*ite0 == school_name) ;

	
	if (IsPref && BestOffer_ == "")
	{BestOffer_ = school_name; HasOffer_ = true;return true; }

	else if (IsPref){
		int i = 0; int j = 0;
		for (list <string>::iterator ite1 = preference_.begin(); *ite1 != school_name; ite1++)
			i++;
		for (list <string>::iterator ite2 = preference_.begin(); *ite2 != BestOffer_; ite2++)
			j++;
		{if (i < j)
		{BestOffer_ = school_name; return true; }
		else
		return false;
		}
		}
	else
		return false;
	}
