#include <iostream>
#include <string>
using namespace std;
int cycle = 0;// making a global variable cycle because i needed it measure how many cycles have passed
class Process // This class stores process details
{
public:
    string Process_id;
    int execution_time;
    int remaining_time;
    Process()
    {
    }
    Process(string id, int time) // constructor of process class taking process_id and remaining time 
    {
        this->Process_id = id;
        this->remaining_time = time;
        this->execution_time = 0; // because at initial stage there is no execution time
    }
    void print() // print function to display the process_id and its remaining time
    {
        // the if-else is useful when we are executing the processes
        if (remaining_time>0){
        cout << " [ " << Process_id << " , " << remaining_time << " ] ";
    }
    else{
        cout<< " [ " << Process_id << " , (Completed) ]" ;
    }
    }
};
// node class
class Node
{
public:
    Process data; // each node store details of process
    Node *next;
    Node()
    {
    }
    Node(Process data) // constructor of node
    {
        this->data = data;
        this->next = NULL;
    }
};
// circular linked list
class Circular_linked_list
{
public:
    Node *start;
    int length;
    Circular_linked_list() // default constructor
    {
        start = NULL;
        length = 0;
    }
    bool isEmpty() // checking whether the list is empty or not
    {
        return start == NULL;
    }
    void insert(Process data) // inserting the nodes in the circular linked list
    {
        Node *node = new Node(data);
        if (isEmpty())
        {
            start = node;
            node->next = start;
            length++;
        }
        else
        {
            Node *temp = start;
            while (temp->next != start)
            {

                temp = temp->next;
            }
            node->next = start;
            temp->next = node;
            length++;
        }
    }
    void del(string process_id) // deleting the nodes if needed
    {
        if (isEmpty())
        {
            cout << "The list is empty\n";
            return;
        }
        if (start->data.Process_id == process_id)
        {

            if (start->next == start)
            {

                delete start;

                start = NULL;

                return;
            }

            Node *temp = start;

            while (temp->next != start)
            {

                temp = temp->next;
            }

            temp->next = start->next;

            delete start;

            start = temp->next;

            return;
        }
        Node *temp = start;
        Node *prev = NULL;
        while (temp->next != start)
        {
            prev = temp;
            temp = temp->next;
            if (temp->data.Process_id == process_id)
            {
                break;
            }
        }
        if (temp->data.Process_id != process_id)
        {
            cout << "This process is not present in this Circular linked list\n";
        }
        else
        {

            prev->next = temp->next;
            free(temp);
        }
    }

    void print() // printing the nodes of circular linked list
    {
        if (isEmpty())
        {
            cout << "The list is empty\n";
        }
        else
        {
            Node *temp = start;
            do
            {
                Process P_temp = temp->data;
                P_temp.print();

                temp = temp->next;
            } while (temp->next != start->next);
            cout << endl;
        }
    }
};
void Cycles(Circular_linked_list list, int Time) // this function takes circular linked list and CPU processing time for execution of proccesses stroed in CLL
{
    cycle++; // incrementing the global variable cycle whenever the Cycles() is called
    
    if (list.isEmpty())
    {
        cout << "The list is empty\n";
    }
    else
    {
        Node *temp = list.start;
        Node *prev = NULL;
        while (temp->next != list.start)
        {
            temp->data.remaining_time = temp->data.remaining_time - 3;
            temp->data.execution_time = temp->data.execution_time + 3;
            temp->data.print(); // printing the process
            prev = temp; // the reason of storing the is to check if its remaining time is equal or less than 0 than del it
            temp = temp->next;
            if (prev->data.remaining_time <= 0)//  deleting the process whose remaining time is less than or equal to 0
            {
                
                list.del(prev->data.Process_id);
            }
        }
        // this part of code is for the last node because we can't access it throught while loop
        temp->data.remaining_time = temp->data.remaining_time - 3;
        temp->data.execution_time = temp->data.execution_time + 3;
        temp->data.print();
        if (temp->data.remaining_time <= 0)
        {
            
            list.del(temp->data.Process_id);
        }
        cout<<endl; // as we are printing the proccesses so we have to seperate them form other cycles when it is completed
    }
}
int main() // main function
{
    Circular_linked_list L1;
    Process P1("P 1", 10), P2("P 2", 5), P3("P 3", 8);
    L1.insert(P1);
    L1.insert(P2);
    L1.insert(P3);
    cout << "Initial Processes: ";
    L1.print();
    int CPU_TIME;
    cout << "CPU Time per Process per Cycle: ";
    cin >> CPU_TIME;
    cout << "Cycle 1 :";
    Cycles(L1, CPU_TIME);
    cout << "Cycle 2 :";
    Cycles(L1, CPU_TIME);
    Process P4("P 4", 9);
    cout << "New process arrives: ('P 4',9)\n";
    L1.insert(P4);
    cout << "Cycle 3 :";
    Cycles(L1, CPU_TIME);
    return 0;
}