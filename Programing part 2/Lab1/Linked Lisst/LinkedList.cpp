#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <list>
using namespace std;

const int n = 5; // Colums

struct Node {
    int data;
    Node* next;
};
void addNode(Node** head_ref, int new_data);
void deleteNode(Node** head_ref, int key);
void printList(Node* node);
void deleteList(Node** head_ref);


int main(void) {
    
    Node* head = NULL;
    ifstream in("input.txt");
    int d;
    int num_count;
    int row_count;
    for (int i = 0; in >> d; i++){
        addNode(&head, d);
        num_count = i;
    }
    printList(head);


    int remainder = num_count % n;
    while (remainder != 0)
    {
        ++num_count;
        remainder = num_count % n;
    }
    cout << "count is: " << num_count << endl;
    row_count = num_count / n; 
    cout << "row_count is: " << row_count << endl;
    const int m = row_count;

    int **arr = new int*[n]; // create an array of pointers to int

    for (int i = 0; i < m; i++) {
        arr[i] = new int[m]; // allocate memory for each row
    }


    int index = 0;
    Node* curr = head;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (curr != NULL) {
                arr[i][j] = curr->data;
                curr = curr->next;
            }
            else {
                arr[i][j] = 0;
            }
        }
    } 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        } 
        cout << endl;
    }

///////////////////////////

    int randomRow[n];
    int randomColumn[m];
    cout << "ARRAY";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << "\t" << arr[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] % 2 != 0)
            {
                int num;
                num = arr[i][j];
                num *= 2;
                arr[i][j] = num;
            }
        }
    }
    cout << endl << "Individual task: \n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << '\t' << arr[i][j];
        }
        cout << endl;
    }

    ofstream out("output.txt");

    if (!out.is_open()) {
        cerr << "Failed to open output.txt for writing" << endl;
        return 1;
    }

    out << "Individual task array: " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            out << '\t' << arr[i][j];
        }
        out << endl;
    }

out.close();
    /////////////////////// 2
    // const int p = n;
    // double randomArr[n];
    // for (int i = 0; i < p; i++)
    // {
    //     randomArr[i] = rand() % 20;
    // }
    // cout << "\n 1D Array \n";
    // for (int i = 0; i < p; i++)
    // {
    //     cout << randomArr[i] << " ";
    // }
    // double min = randomArr[0];
    // for (int i = 0; i < p; i++)
    // {
    //     if (randomArr[i] > 0)
    //     {
    //         if (randomArr[i] < min)
    //         {
    //             min = randomArr[i];
    //         }
    //     }
    // }
    // cout << sqrt(min) << endl;
    // cout << "\nDone 1D Array \n";
    // for (int i = 0; i < p; i++)
    // {
    //     cout << randomArr[i] << " ";
    // }

    ///////////////////////
    deleteList(&head);

    // deallocate memory
    for (int i = 0; i < n; i++) {
        delete[] arr[i]; // free memory for each row
    }
    delete[] arr; // free memory for the array of pointers

    return 0;
}



// Define a function to add a node to the end of the list
void addNode(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    Node* last = *head_ref;
    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node;
    return;
}

// Define a function to delete a node from the list
void deleteNode(Node** head_ref, int key) {
    Node* temp = *head_ref;
    Node* prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        delete temp;
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return;
    }

    prev->next = temp->next;
    delete temp;
}

// Define a function to print the contents of the list
void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void deleteList(Node** head_ref) {
    Node* current = *head_ref;
    Node* next;
    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    *head_ref = NULL;
}
