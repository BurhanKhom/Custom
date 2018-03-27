#include<iostream>
using namespace std;

char grades[5][1] = {'A', 'B', 'C', 'D', 'F'};
int count=0, grade[5] = {90, 80, 70, 60, 0};

class Student
{
	private:
		int roll, year, sem, marks[5], total=0;
		float percent;
		char name[20], subjects[5][20], branch[20], coll[20];
	public:
		void getData()
		{
			cout << "Enter name : ";
			cin << name;
			cout << "Enter Roll, year and sem : ";
			cin >> roll >> year >> sem;
			cout << "Enter Branch and College : ";
			cin >> branch >> College;
			cout << "Enter subjects : "
			for(int i=0; i<5; i++)
				cin >> subjects[i];
			cout << "Enter marks : "
			for(int i=0; i<5; i++)
			{
				cin >> marks[i];
				total+=marks[i];
			}
			percent = total/5.0;
		}
		void display()
		{
			cout << "\t\tName        : " << name      << endl;
			cout << "\t\tRoll        : " << roll      << endl;
			cout << "\t\tYear        : " << year      << endl;
			cout << "\t\tSem         : " << sem       << endl;
			cout << "\t\tBranch      : " << branch    << endl;
			cout << "\t\tCollege     : " << coll      << endl;
			cout << "\t\tTotal Marks : " << total     << endl;
			cout << "\t\tPercentage  : " << percent   << endl;
			cout << "\t\tGrade       : ";
			for(int x = 0; x < 5; x++)
				if(total >= grade[x])
				{
					cout << grades[x] << endl;
					break;
				}
			if(!x)
				count++;
		}
};
int main()
{
	int n;
	cout << "Enter number of Students : ";
	cin >> n;
	Student s[n];
	for(int i=1; i<=n; i++)
	{
		cout << "Enter details of student " << i << endl;
		s[i].getData();
	}
	cout << "Student details are : "
	s[i].display();
	cout << "\nTotal students with Grade A = " << count << endl;
}