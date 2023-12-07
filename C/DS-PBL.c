#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 1000

typedef struct Node{
    int employeeID;
    char first_name[20];
    char last_name[20];
    int salary;
    char position[20];
    struct Node* next;
} Node;

typedef struct Hashtable{
    Node* table[TABLE_SIZE];
} Hashtable;

void initializeHashtable(Hashtable* hashtable){
    for (int i = 0; i < TABLE_SIZE; i++){
        hashtable->table[i] = NULL;
    }
}

int hashFunction(int key){
    return key % TABLE_SIZE;
}

Node* insertEmployee(int EmployeeIDS[]) {
    Node* Employee = (Node*)malloc(sizeof(Node));

    int EId, i = 0;
    printf("Enter the unique employeeID: ");
    scanf("%d", &EId);

    // Checking to make sure the employeeID is unique before proceeding
    while (EmployeeIDS[i] != -1) {
        if (EmployeeIDS[i] == EId) {
            printf("An employee with this ID already exists! Employee Ids must be unique. \n");
            free(Employee);
            return NULL;
        }
        i += 1;
    }

    EmployeeIDS[i] = EId;
    EmployeeIDS[i + 1] = -1;
    Employee->employeeID = EId;

    printf("Enter employee's first name, last name, salary and postition: ");
    scanf("%s %s %d %s", &Employee->first_name, &Employee->last_name, &Employee->salary, &Employee->position);

    return Employee;
}

void insertHash(Hashtable* hashtable,  Node* employee) {
    int hashValue = hashFunction(employee->employeeID);

    if (hashtable->table[hashValue] == NULL){
        hashtable->table[hashValue] = employee;
        employee->next = NULL;
    } else {
        employee->next = hashtable->table[hashValue];
        hashtable->table[hashValue] = employee;
    }
}

Node* searchEmployee(Hashtable* hashtable, int EmployeeID){
    int hashValue = hashFunction(EmployeeID);
    Node* current = hashtable->table[hashValue];

    while (current->employeeID != EmployeeID){
        current = current -> next;
    }
    return current;
}

void deleteEmployee(Hashtable* hashtable, int EmployeeID){
    int hashValue = hashFunction(EmployeeID);
    Node* current = hashtable->table[hashValue];
    Node* prev = NULL;

    while (current!=NULL && current -> employeeID != EmployeeID) {
        prev = current;
        current = current -> next;
    }

    if (current == NULL) {
        printf("Employee not found for deletion. \n");
        return;
    }

    if (prev == NULL) {
        hashtable -> table[hashValue] = current -> next;
    } else {
        prev -> next = current -> next;
    }

    free(current);
    printf("Employee deleted sucessfully. ");
}

int main() {
    int EmployeeIDS[TABLE_SIZE];
    EmployeeIDS[0] = -1;
    Hashtable employeeTable;
    initializeHashtable(&employeeTable);
    int choice;

    printf("\n---------------------Employee Management System--------------------------\n");

    while (true) {
        printf("1. Insert Employee\n");
        printf("2. Search Employee\n");
        printf("3. Delete Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                Node* newEmployee = insertEmployee(EmployeeIDS);
                if (newEmployee != NULL) {
                    insertHash(&employeeTable, newEmployee);
                    printf("Employee inserted successfully.\n");
                }
                break;
            }
            case 2: {
                int searchID;
                printf("Enter the Employee ID to search: ");
                scanf("%d", &searchID);

                Node* searchedEmployee = searchEmployee(&employeeTable, searchID);
                if (searchedEmployee != NULL) {
                    printf("Employee ID %d found.\n", searchedEmployee->employeeID);
                    printf("First name: %s \nLast name: %s \nSalary: %d Rs. \nPosition: %s \n", searchedEmployee->first_name,
                    searchedEmployee ->last_name, searchedEmployee->salary, searchedEmployee->position);
                } else {
                    printf("Employee not found.\n");
                }
                break;
            }
            case 3: {
                int deleteID;
                printf("Enter the Employee ID to delete: ");
                scanf("%d", &deleteID);

                deleteEmployee(&employeeTable, deleteID);
                break;
            }
            case 4: {
                printf("Exiting the Employee Management System.\n");
                return 0;
            }
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
