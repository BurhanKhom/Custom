/**************************************
* Program to display Employee Records *
* in ascending order of their salary. *
***************************************
* Author : burhankhom009	      *
* Date   : Sun, 25 March 2018         *
* Time   : 4:58 PM                    *
***************************************/
#include<stdio.h>
#include<string.h>
typedef struct emp
{
	int id, salary;
	long long phone;
	char name[20], company[20], city[20], desg[50];
}emp;
void swap(emp a[], int i, int j)
{
	emp temp;
	temp.id = a[i].id;
	temp.salary = a[i].salary;
	temp.phone = a[i].phone;
	strcpy(temp.name, a[i].name);
	strcpy(temp.company, a[i].company);
	strcpy(temp.city, a[i].city);
	strcpy(temp.desg, a[i].desg);

	a[i].id = a[j].id;
	a[i].salary = a[j].salary;
	a[i].phone = a[j].phone;
	strcpy(a[i].name, a[j].name);
	strcpy(a[i].company, a[j].company);
	strcpy(a[i].city, a[j].city);
	strcpy(a[i].desg, a[j].desg);

	a[j].id = temp.id;
	a[j].salary = temp.salary;
	a[j].phone = temp.phone;
	strcpy(a[j].name, temp.name);
	strcpy(a[j].company, temp.company);
	strcpy(a[j].city, temp.city);
	strcpy(a[j].desg, temp.desg);

}
void sortSal(emp a[], int n)
{
	//Sorting Algorithm used : Bubble Sort
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=i; j<n-1; j++)
		{
			if(a[i].salary > a[j+1].salary)
				swap(a, i, j+1);
		}
	}
}
void display(emp a[], int n)
{
	printf("\n\n");
	printf("___________________________________________________________________________________________________\n");
	printf("|                             DETAILS OF EMPLOYEES ORDER BY SALARY ASC                            |\n");
	printf("|_________________________________________________________________________________________________|\n");
	printf("%-16s%-11s%-16s%-16s%-16s%-11s%-12s|\n", "|Name", "|ID", "|Company", "|City", "|Designation", "|Salary", "|Mobile");
	printf("|_______________|__________|_______________|_______________|_______________|__________|___________|\n");
	for(int i=0; i<n; i++)
	{
		printf("|%-15s", a[i].name);
		printf("|%-10d", a[i].id);
		printf("|%-15s", a[i].company);
		printf("|%-15s", a[i].city);
		printf("|%-15s", a[i].desg);
		printf("|%-10d", a[i].salary);
		printf("|%-11lld|\n", a[i].phone);
	}
	printf("|_______________|__________|_______________|_______________|_______________|__________|___________|\n");
}
int main()
{
	int i, n;
	printf("Enter the number of employees : ");
	scanf("%d", &n);
	emp a[n];
	printf("\n%50s", "Enter the details of each employee\n");
	for(i=0; i<n; i++)
	{
		printf("Employee %d:\n", i+1);
		printf("\tName        : ");
		scanf("\n%[^\n]s", a[i].name);
		printf("\tEmployee ID : ");
		scanf("%d", &a[i].id);
		printf("\tCompany     : ");
		scanf("\n%[^\n]s", a[i].company);
		printf("\tCity        : ");
		scanf("\n%[^\n]s", a[i].city);
		printf("\tDesignation : ");
		scanf("\n%[^\n]s", a[i].desg);
		printf("\tSalary      : ");
		scanf("\n%d", &a[i].salary);
		printf("\tMobile No.  : ");
		scanf("%lld", &a[i].phone);
	}
	sortSal(a, n);
	display(a, n);
}
