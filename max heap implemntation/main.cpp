#include <iostream>
using namespace std;
class Student {
public:
    int id;
    string name;
    float gpa;
    string department;
    Student() {
        id = 0;
        name = "";
        gpa = 0.0;
        department = "";
    }

    Student(int id, string name, float gpa, string department) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        this->department = department;
    }
    bool operator<(const Student& other) const {
        return gpa < other.gpa;
    }

    bool operator>(const Student& other) const {
        return gpa > other.gpa;
    }

    bool operator==(const Student& other) const {
        return gpa == other.gpa;
    }
    friend std::ostream& operator<<(std::ostream& os, const Student& student) {
        os << "ID: " << student.id << "\n";
        os << "Name: " << student.name << "\n";
        os << "GPA: " << student.gpa << "\n";
        os << "Department: " << student.department << "\n";
        return os;
    }
};



void heapify(Student arr[], int size, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && arr[left].gpa > arr[largest].gpa) {
        largest = left;
    }

    if (right < size && arr[right].gpa > arr[largest].gpa) {
        largest = right;
    }

    if (largest != index) {
        swap(arr[index].gpa, arr[largest].gpa);
        heapify(arr, size, largest);
    }
}


void buildHeap(Student arr[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(arr, size, i);
    }
}

void addStudent(Student arr[], int& size, Student newStudent) {
    arr[size] = newStudent;
    size++;
    int i = size - 1;
    while (i > 0 && arr[(i - 1) / 2] < arr[i]) {
        swap(arr[(i - 1) / 2], arr[i]);
        i = (i - 1) / 2;
    }
}

void printStudents(Student arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "ID: " << arr[i].id << "\n";
        cout << "Name: " << arr[i].name << "\n";
        cout << "GPA: " << arr[i].gpa << "\n";
        cout << "Department: " << arr[i].department << "\n\n";
    }
}

int main() {
    const int MAX_SIZE = 100;
    Student arr[MAX_SIZE] = {
            Student(1,"mohamed ali",3.4,"cs"),
            Student(2,"mona samir",3.2,"it"),
            Student(3,"ola maher",1.2,"cs"),
            Student(4,"magy magdy",2.3,"ds"),
            Student(5,"omnia osama",3.6,"is"),
            Student(6,"ahmed omar",3.9,"cs"),
            Student(7,"mai adel",3.1,"is"),
            Student(8,"mohamed saleh",2.4,"cs"),
            Student(9,"hany mohsen",1.8,"ds"),
            Student(10,"mohamed bahaa",2.9,"it"),
    };
    int size = 10;
    buildHeap(arr, size);

    int choice = 0;
    while (choice != 3) {
        buildHeap(arr, size);
        cout << "Enter 1 to add a new student\n";
        cout << "Enter 2 to print the current list of students\n";
        cout << "Enter 3 to exit\n";
        cin >> choice;
        switch (choice) {
            case 1: {
                int id;
                string name, department;
                float gpa;
                cout << "Enter the ID of the new student: ";
                cin >> id;
                cout << "Enter the name of the new student: ";
                cin >> name;
                cout << "Enter the GPA of the new student: ";
                cin >> gpa;
                cout << "Enter the department of the new student: ";
                cin >> department;
                Student newStudent(id, name, gpa, department);
                addStudent(arr, size, newStudent);
                buildHeap(arr, size);
                break;
            }
            case 2: {
                buildHeap(arr, size);
                printStudents(arr, size);
                break;
            }
            case 3: {
                cout << "Exiting program...\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n";
                break;
            }
        }
    }
    return 0;
}

//  this is the code if we want to sort by id عاااااااااااااااااااااا
/*
void heapif (Student arr[], Student n , Student i)
{
    int left = 2*i.id+1;
    int right = 2*i.id+2;
    Student max;
    max.id = i.id ;
    if (left<n.id&& arr[left]>arr[max.id])
        max.id = left;
    if (right<n.gpa and arr[right]>arr [ max.id])
        max.id=right;
    if (max.id!= i.id )
    {
        swap(arr[i.id],arr[max.id]);
        heapif(arr,n,max);
    }}
    void buildHeap(Student arr[], Student n )
    {
        Student i;
        for (i.id = n.id/2 ; i.id >=0; i.id--)
        {
            heapif(arr,n,i);
        }
    }
    void heapSprt(Student arr[],Student n )
    {
        buildHeap(arr,n);
        Student i,l;
        l.id=0;
        for (i.id = n.id-1;i.id>=0;i.id--)
        {
            swap(arr[0],arr[i.id]);
            heapif(arr,i,l);
        }
    }

void addStudent(Student arr[], Student& size, Student newStudent) {
    arr[size.id] = newStudent;
    size.id++;
}

void print(Student arr[], Student n)
{
    for ( int i = 0; i < n.id; i++)
    {
        cout << arr[i].id << " "<<endl;
        cout << arr[i].name << " "<<endl;
        cout << arr[i].gpa << " "<<endl;
        cout << arr[i].department << " "<<endl
        ;
    }
    cout << endl;

}

int main() {
    int choice =0;


    const int MAX_SIZE = 100;
    Student arr[MAX_SIZE] = {
            Student(123, "John Doe", 3.7, "Computer Science"),
            Student(456, "Jane Smith", 3.9, "Electrical Engineering"),
            Student(789, "Bob Johnson", 3.2, "Mechanical Engineering")
    };
    Student size;
    size.id = 3;
   // print(arr, size);
    while (choice!= 3)
    {
        cout <<"welcome in Max Heap "<<endl;
        cout <<"if you want to add new student press 1 "<<endl;
        cout <<"if you want to print all the students press 2  "<<endl;
        cout <<"if you want to EXit press 3 "<<endl;
        cin >>choice;

    switch (choice) {
        case 1: {
            Student add;
            cout << "enter student id : ";
            cin >> add.id;
            cout << "enter student name : ";
            cin >> add.name;
            cout << "enter student GPA : ";
            cin >> add.gpa;
            cout << "enter student department : ";
            cin >> add.department;
            addStudent(arr, size, add);
            heapSprt(arr, size);
            cout << endl << "the student is added\n";
            break;
        }
        case 2:
            cout << "here is all the students" << endl;
            print(arr, size);
            break;
        case 3:
            cout << "Exiting program.\n";
            break;

    }
    }
    return 0;








//    int cid;
//    Student mmm(cid,"JDFKKFKD",9.5,"FGFGGF");
//
//    Student arr[]= {{2,"ahmed",3.5,"CS"} ,{3,"ahmed",3.5,"CS"},{4,"ahmed",3.5,"CS"},{1,"ahmed",3.5,"CS"},{5,"ahmed",3.5,"CS"},mmm};
//    Student n  (5,"ahmed",3.5,"CS" );
//
//     n.id = sizeof (arr)/sizeof (arr[0]);
//    heapSprt(arr,n);
//    print(arr,n.id);
//
//    return 0;
}



*/






/*
  #include <iostream>
using namespace std;
class Student {
public:
    int id;
    string name;
    float gpa;
    string department;
    Student() {
        id = 0;
        name = "";
        gpa = 0.0;
        department = "";
    }

    Student(int id, string name, float gpa, string department) {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        this->department = department;
    }
    bool operator<(const Student& other) const {
        return id < other.id;
    }

    bool operator>(const Student& other) const {
        return id > other.id;
    }

    bool operator==(const Student& other) const {
        return id == other.id;
    }

};

void heapif (int arr[], int n , int i)
{
    int left = 2*i+1;
    int right = 2*i+2;
    int max = i ;
    if (left<n&& arr[left]>arr[max])
        max = left;
    if (right<n and arr[ right]>arr [ max])
        max=right;
    if (max!= i )
    {
        swap(arr[i],arr[max]);
        heapif(arr,n,max);
    }}
    void buildHeap(int arr[], int n )
    {
        for(int i = n/2 ; i >=0; i--)
        {
            heapif(arr,n,i);
        }
    }
    void heapSprt(int arr[],int n )
    {
        buildHeap(arr,n);
        for (int i = n-1;i>=0;i--)
        {
            swap(arr[0],arr[i]);
            heapif(arr,i,0);
        }
    }
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

}



int main() {

    int arr[]= {90,10,40,70,5};
    int n = sizeof (arr)/sizeof (arr[0]);
    heapSprt(arr,n);
    print(arr,n);

    return 0;
}
*/
