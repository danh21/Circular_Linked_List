#include <bits/stdc++.h>

using namespace std;





/* --------------------------------------------------------- MACROES - START --------------------------------------------------------- */
#define ERR_EMPTY       "List is empty !"
#define ERR_VAL         "Value is invalid !"
#define ERR_DUPLICATED  "No conversion !"

/* --------------------------------------------------------- MACROES - END ----------------------------------------------------------- */





/* ----------------------------------------------------- DATA STRUCTS - START -------------------------------------------------------- */
struct node {
    int data;
    node *next;

    node(int value = 0) {
        data = value;
        next = this;
    }
};



struct cirList {
    int numOfNodes;
    node *head;
};
/* ----------------------------------------------------- DATA STRUCTS - END ---------------------------------------------------------- */





/* ------------------------------------------------------ PROTOTYPE - START ---------------------------------------------------------- */
/**
 * @brief add a new node at the tail of the list
 * 
 * @param list 
 * @param data 
 */
void addTail(cirList *&list, int data);



/**
 * @brief add a new node at the head of the list
 * 
 * @param list 
 * @param data 
 */
void addHead(cirList *&list, int data);



/**
 * @brief Create a Circular Linked List object
 * 
 * @param list 
 * @param nums 
 * @param opt 
 */
void createList(cirList *&list, int nums, int opt);



/**
 * @brief print all nodes of the list
 * 
 * @param list 
 * @param pos 
 */
void printList(cirList *list, int pos);



/**
 * @brief insert a new node at any position in the list
 * 
 * @param list 
 * @param pos 
 * @param data 
 */
void insertAt(cirList *&list, int pos, int data);



/**
 * @brief delete node at any position in the list
 * 
 * @param list 
 * @param pos 
 */
void deleteAt(cirList *list, int pos);
/* ------------------------------------------------------- PROTOTYPE - END ----------------------------------------------------------- */





/* --------------------------------------------------------- FUNCTIONS - START ------------------------------------------------------- */
void addTail(cirList *&list, int data) 
{
    node *p = list->head;
	while (p->next != list->head)   // not last node
		p = p->next;
	
	node *temp = new node(data);
	temp->next = list->head;
	p->next = temp;
}



void addHead(cirList *&list, int data) 
{
    addTail(list, data);

    node *p = list->head;
    while (p->next != list->head)  // not last node
		p = p->next;
    list->head = p;
}



void createList(cirList *&list, int nums, int opt)
{
    try {
        if (nums < 1)
            throw ERR_VAL;

        if (opt != 0 && opt != 1)
            throw ERR_VAL;
        
        list = new cirList; 
        list->numOfNodes = nums;   
        int data;

        for (int i = 0; i < nums; i++) {
            cout << "Enter data of node: ";
            cin >> data;

            if (i == 0)
                list->head = new node(data);
            else
                if (opt)
                    addTail(list, data);
                else
                    addHead(list, data);
        }  
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



void printList(cirList *list, int pos) 
{
    try {
        if (list == NULL)
            throw ERR_EMPTY;
        
        node *p = list->head;

        cout << "List includes " << list->numOfNodes << (list->numOfNodes == 1 ? " node: " : " nodes: ");

        for (int i = 0; i < pos; i++)
            p = p->next;
        node *start = p;

        do {
            cout << p->data << " ";
            p = p->next;
        } while (p != start);
        cout << endl;
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



void insertAt(cirList *&list, int pos, int data) 
{
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        if (pos < 0 || pos > list->numOfNodes)
            throw ERR_VAL;

        node *p = list->head;

        if (pos == 0) 
            addHead(list, data);
        else if (pos == list->numOfNodes)
            addTail(list, data);
        else {
            for (int i = 1; i < pos; i++)   // previous node of inserted node
                p = p->next; 
            node *temp = new node(data);    // inserted node  
            temp->next = p->next;
            p->next = temp;
        } 

        list->numOfNodes++;
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



void deleteAt(cirList *list, int pos) 
{
    try {
        if (list == NULL)
            throw ERR_EMPTY;

        if (pos < 0 || pos >= list->numOfNodes)
            throw ERR_VAL;

        node *p = list->head;

        if (pos == 0) {
            node *oldHead = list->head;
            while (p->next != oldHead)  // not last node
		        p = p->next;
            p->next = oldHead->next;
            list->head = oldHead->next;
            delete oldHead;
        }
        else {
            for (int i = 1; i < pos; i++)
                p = p->next;
            node *temp = p->next;       // node will be deleted
            p->next = temp->next;
            delete temp; 
        } 

        list->numOfNodes--; 
    }

    catch (char const *exc) {
        cout << exc << endl;
    }     
}
/* --------------------------------------------------------- FUNCTIONS - END ------------------------------------------------------- */