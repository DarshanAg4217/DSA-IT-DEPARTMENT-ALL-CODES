#include<iostream>
#include<string.h>
using namespace std;

typedef struct {
    int roll_num;
    char name[20];
    float marks;
} stud;

void create(stud s[20], int n);
void display(stud s[20], int n);
void bubble_sort(stud s[20], int n);
void insertionSort(stud s[20], int n);
void quick_sort(stud s[20], int, int);
int partition(stud s[20], int, int);
void search(stud s[20], int n, int key);
int bsearch(stud s[20], char x[20], int low, int high);

int main() {
    stud s[20];
    int ch, n, key, result;
    char x[20];
    
    do {
        cout << "\n 1) Create Student Database \n 2) Display Student Records \n 3) Bubble Sort \n 4) Insertion Sort \n 5) Quick Sort \n 6) Linear search \n 7) Binary search \n 8) Exit \n Enter Your Choice:=";
        cin >> ch;
        
        switch(ch) {
            case 1: 
          //  cout<<"\n Enter the Number of Records:=";
          //  cin>>n;
            create(s, n); break;
            case 2: display(s, n); break;
            case 3: bubble_sort(s, n); break;
            case 4: insertionSort(s, n); break;
            case 5: quick_sort(s, 0, n - 1);
                    cout << "\n\tRoll No\tName\tMarks";
                    for (int i = n - 1; i >= n - 10; i--)
                        cout << "\n\t" << s[i].roll_num << "\t" << s[i].name << "\t" << s[i].marks;
                    break;
            case 6: cout << "\n Enter the marks to search:="; cin >> key; search(s, n, key); break;
            case 7: cout << "\n Enter the name to search:="; cin >> x;
                    insertionSort(s, n);
                    result = bsearch(s, x, 0, n - 1);
                    (result == -1) ? cout << "\n Student not present!\n" : cout << "\n Student is present:\t" << s[result].name;
                    break;
            case 8: return 0;
            default: cout << "\n Invalid choice! Please enter your choice again.\n";
        }
    } while (ch != 8);
}

void create(stud s[20], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\n Roll number:="; cin >> s[i].roll_num;
        cout << "\n Name:="; cin >> s[i].name;
        cout << "\n Marks:="; cin >> s[i].marks;
    }
}

void display(stud s[20], int n) {
    cout << "\n\tRoll No\tName\tMarks";
    for (int i = 0; i < n; i++)
        cout << "\n\t" << s[i].roll_num << "\t" << s[i].name << "\t" << s[i].marks;
}

void bubble_sort(stud s[20], int n) {
    for (int i = 1; i < n; i++)
        for (int j = 0; j < n - i; j++)
            if (s[j].roll_num > s[j + 1].roll_num)
                swap(s[j], s[j + 1]);
}

void insertionSort(stud s[20], int n) {
    for (int i = 1, j; i < n; i++) {
        stud key = s[i];
        for (j = i - 1; j >= 0 && strcmp(s[j].name, key.name) > 0; j--)
            s[j + 1] = s[j];
        s[j + 1] = key;
    }
}

void quick_sort(stud s[20], int l, int u) {
    if (l < u) {
        int j = partition(s, l, u);
        quick_sort(s, l, j - 1);
        quick_sort(s, j + 1, u);
    }
}

int partition(stud s[20], int l, int u) {
    stud temp, v = s[l];
    int i = l, j = u + 1;
    do {
        do i++; while (s[i].marks < v.marks && i <= u);
        do j--; while (v.marks < s[j].marks);
        if (i < j) swap(s[i], s[j]);
    } while (i < j);
    swap(s[l], s[j]);
    return j;
}

void search(stud s[20], int n, int key) {
    cout << "\n\tRoll No\tName\tMarks";
    for (int i = 0; i < n; i++)
        if (key == s[i].marks)
            cout << "\n\t" << s[i].roll_num << "\t" << s[i].name << "\t" << s[i].marks;
}

int bsearch(stud s[20], char x[20], int low, int high) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (strcmp(x, s[mid].name) == 0) return mid;
        else if (strcmp(x, s[mid].name) < 0) high = mid - 1;
        else low = mid + 1;
    }
    return -1;
}