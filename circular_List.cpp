#include <iostream>
using namespace std;



#define ERR_NUMS        "The number of nodes is out of range !"
#define ERR_EMPTY       "List is empty !"
#define ERR_POS         "Position is out of range !"
#define ERR_DUPLICATED  "No conversion !"



struct node {
    int data;
    node *next;
};

struct cirList {
    int numOfNodes;
    node *head;
};



node *createNode(int data) {
    node *temp = new node;
    temp->data = data;
    temp->next = temp;
    return temp;
}



cirList *addTail(cirList *list, int data) {
    node *p = list->head;
	while (p->next != list->head)  // last node
		p = p->next;
	
	node *temp = new node;
	temp->data = data;
	temp->next = list->head;
	p->next = temp;

	return list;
}



cirList *addHead(cirList *list, int data) {
    list = addTail(list, data);

    node *p = list->head;
    while (p->next != list->head)  // last node
		p = p->next;
    list->head = p;

	return list;
}



cirList *createList(int n) {
    cirList *list = new cirList; 
    list->numOfNodes = n;

    try {
        if (n < 1)
            throw ERR_NUMS;

        node *p;   
        int data;

        for (int i = 0; i < n; i++) {
            cout << "Enter data of node: ";
            cin >> data;
            if (i == 0) {
                list->head = createNode(data);
                p = list->head;
            }
            else
                list = addTail(list, data);
        }  
    }

    catch (char const *exc) {
        cout << exc << endl;
        list->head = NULL;
    }

    return list;
}



void printList(cirList *list, int pos) {
	node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;
        
        cout << "List includes " << list->numOfNodes;
        if (list->numOfNodes == 1)
            cout << " node: ";
        else
            cout << " nodes: ";

        for (int i = 0; i < pos; i++)
            p = p->next;
        node *start = p;

        do {
            cout << p->data << " ";
            p = p->next;
        } while (start != p);
        cout << endl;
    }

    catch (char const *exc) {
        cout << exc << endl;
    }
}



cirList *insertAt(cirList *list, int pos, int data) {
    node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;

        if (pos < 0 || pos > list->numOfNodes)
            throw ERR_POS;

        if (pos == 0) 
            list = addHead(list, data);
        else if (pos == list->numOfNodes)
            list = addTail(list, data);
        else {
            for (int i = 1; i < pos; i++)   // previous node of inserted node
                p = p->next; 

            node *temp = new node;          // inserted node
            temp->data = data;  
            temp->next = p->next;
            p->next = temp;
        } 

        list->numOfNodes++;
    }

    catch (char const *exc) {
        cout << exc << endl;
    }

    return list;
}



cirList *deleteAt(cirList *list, int pos) {
    node *p = list->head;

    try {
        if (p == NULL)
            throw ERR_EMPTY;

        if (pos < 0 || pos >= list->numOfNodes)
            throw ERR_POS;

        if (pos == 0) {
            node *oldHead = list->head;
            while (p->next != oldHead)  // last node
		        p = p->next;
            p->next = oldHead->next;
            list->head = oldHead->next;
            delete(oldHead);
        }
        else {
            for (int i = 1; i < pos; i++)
                p = p->next;
            node *temp = p->next;       // node will be deleted
            p->next = temp->next;
            delete(temp); 
        } 

        list->numOfNodes--; 
    }

    catch (char const *exc) {
        cout << exc << endl;
    }     

    return list;
}



int main() {
    cirList *list;
    int n, pos, data, opt;

    while (1) {
        cout << " -------------- MENU ------------- " << endl;
        cout << "0. Quit" << endl;
        cout << "1. Create list" << endl;
        cout << "2. Display list" << endl;
        cout << "3. Insert node" << endl;
        cout << "4. Delete node" << endl;
        cout << "Enter your option: ";
        cin >> opt;

        switch (opt)
        {
            case 0:
                return 0;
            case 1:
                cout << "Enter the number of nodes: ";
                cin >> n;
                list = createList(n);
                break;
            case 2:
                cout << "Enter the start position: ";
                cin >> pos;
                printList(list, pos);
                break;
            case 3:
                cout << "Enter the position: ";
                cin >> pos;
                cout << "Enter data: ";
                cin >> data;
                list = insertAt(list, pos, data);
                break;
            case 4:
                cout << "Enter the position: ";
                cin >> pos;
                list = deleteAt(list, pos);
                break;
            default:
                cout << "Invalid option !" << endl;
                break;
        }
    }
    
    return 0;
}