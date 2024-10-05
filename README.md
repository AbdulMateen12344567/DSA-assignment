
# Problem # 01 

## Simple Process Scheduling Algorithm
Design and Implement a CPU Process Scheduling Algorithm using a Linked List. Processes will be represented as nodes in the list, and the scheduling algorithm should cycle through the processes, assigning CPU time to each process until all processes have completed their execution. 

### Task
-> Each process should have the following attributes: process_id, execution_time, and remaining_time.

-> The scheduler assigns a fixed amount of CPU time to each process in each cycle. After the time is assigned, the process's remaining_time will be reduced by that amount.

-> If a process completes its execution (i.e., remaining_time becomes 0), it should be removed from the circular linked list.

-> The system should display the state of processes after each cycle, indicating which process is running and its remaining time.

-> Show the state of the system after each cycle.

### Assumptions

#### Overview:

→ We implemented a simple process scheduling algorithm using a circular linked list. Each process is represented as a node in the list, with attributes such as process_id, execution_time, and remaining_time. The CPU allocates a fixed time slice to each process in each cycle, reducing its remaining time. If the process completes (remaining time becomes zero), it is removed from the list.
#### Steps:
-> Step 1: Each process is represented by a Process class containing the process ID, execution time, and remaining time. The Process class also 
includes a print() function to display the process's current state.
-> Step 2: A Node class is used to create the circular linked list. Each node contains a process and a pointer to the next node.

-> Step 3: The Circular_linked_list class is responsible for inserting processes into the list, deleting them when their execution is complete
, and printing the state of the list.
-> Step 4: The Cycles() function simulates each cycle of the CPU scheduling. In each cycle, the CPU reduces the remaining time of each process by the fixe
d amount, prints the state of each process, and deletes processes that have completed execution.
-> Step 5: In the main() function, processes are inserted into the list and CPU cycles are simulated. The state of the system is printed after each cycl
e. New processes can be added dynamically during the simulation.
#### Key Features:
-> A circular linked list is used to simulate the cyclical nature of CPU process scheduling.

-> The Cycles() function efficiently handles process execution by reducing the remaining time of each process, displaying its current state, and removing 
completed processes from the list.
#### Technologies Used:
-> The solution is implemented in C++ using basic object-oriented programming concepts such as classes and linked lists.

#### Challenges:
-> A major challenge was managing the circular nature of the linked list and ensuring that the last node is handled properly outside the main loop.

-> Another challenge was dynamically deleting processes from the list when their remaining time reached zero.




### Approach

#### Process and CPU Time:

-> The CPU allocates a fixed time slice (e.g., 3 units of time) to each process per cycle. This time slice is assumed to be the same for all processes.

-> It is assumed that all processes have positive initial remaining time, and they will complete after being assigned enough CPU time.


#### Process Arrival and Deletion:

-> New processes can arrive and be inserted into the list at any point in the scheduling cycle.

-> A process is removed from the list as soon as its remaining_time reaches zero or less.


#### Circular Linked List:

-> The circular linked list is assumed to represent an ongoing, cyclical process scheduling system, where the list never fully terminates unless all processes are completed.

-> If the list is empty, it is assumed that no processes are available to run.


#### Process Attributes:

-> Each process is assumed to have unique process_id values, and the execution_time is only used to track the total time the process has spent on the CPU.

-> The remaining_time attribute is the main attribute used to determine when a process should be deleted.

#### CPU Time Slice:

-> It is assumed that the CPU can only allocate one fixed time slice to each process per cycle, and that this time slice is sufficient to make progress on reducing the remaining time for all processes.



### Challenges Faced 

#### Challenge 1: Managing Circular Linked List Traversal

##### Description: 
Since we used a circular linked list, traversing it while maintaining the circular structure without breaking the list was tricky. The problem arises when the last node needs to point back to the start node, and we also need to ensure that the circular nature is preserved when deleting or inserting nodes.
##### Solution: 
A proper traversal mechanism was implemented, ensuring that the last node always points back to the start node. To handle this, the while loop in the Cycles() function checks if the current node’s next pointer is pointing to the start of the list. Additionally, we handle the case of the last node separately after the main loop to avoid bypassing it.

#### Challenge 2: Deleting a Process Node After Completion

##### Description: 
In a circular linked list, deleting a node requires careful management of pointers, especially when the node to be deleted is the start node or the only node in the list. Ensuring that the circular structure remains intact after deletion was a challenge, especially when deleting nodes dynamically while the list is being traversed.
##### Solution: 
In the del() function, we implemented special handling for deleting the start node, which involves updating the last node’s next pointer to point to the new start. When there’s only one node left, we ensure the list is properly emptied by setting the start pointer to NULL. For deleting other nodes, the previous node’s next pointer is updated to bypass the node being deleted.

#### Challenge 3: Dynamically Adding Processes During Execution

##### Description: 
Dynamically adding new processes while cycles are being executed posed a challenge because the circular linked list could be modified between cycles. Ensuring that newly added processes are scheduled correctly without disturbing the ongoing execution cycle was complex.
##### Solution: 
The insert() function was designed to allow insertion at any point, including during execution cycles. After a new process is added, it is automatically included in the next cycle without interfering with the ongoing scheduling process. This was achieved by ensuring that the start and next pointers are updated correctly after every insertion.

#### Challenge 4: Handling Processes with Varying Remaining Time

##### Description: 
Some processes might have small remaining time values that could become negative or zero during the cycle. This needed careful handling to avoid running processes with negative remaining times or printing incorrect results.
##### Solution: 
In the Cycles() function, after reducing the remaining time of each process, a check is performed to see if the remaining_time is less than or equal to zero. If so, the process is immediately deleted using the del() function. This ensures that no processes with negative remaining time continue to occupy the list.

#### Challenge 5: Displaying the State of Processes After Each Cycle

##### Description: 
Tracking the state of each process and displaying its remaining time or completion status after every cycle was challenging, especially in a dynamic list where processes are added or removed.
##### Solution: 
The print() method for each process and the linked list was carefully designed to display the current state after each cycle. The processes were printed in the order they appeared in the list, with completed processes marked as "Completed" instead of showing negative remaining times.

#### Challenge 6: Fixed CPU Time Slice for Processes

##### Description: 
The fixed CPU time slice for each process per cycle meant that some processes would complete sooner than others, and ensuring fairness while updating all process times within a single cycle posed a challenge.
##### Solution: 
The time slice was uniformly applied to each process during a cycle. If the remaining time of a process was less than the time slice, the remaining time was reduced to zero and the process was deleted after that cycle. This maintained fairness while ensuring that no process was over-processed beyond its remaining time.

### Output
![alt text](/home/abdulmateen/Nust/3rd_Semister/DSA_LAB/DSA_Assignment_01/Problem1ss.png)
<img src="/home/abdulmateen/Nust/3rd_Semister/DSA_LAB/DSA_Assignment_01/Problem1ss.png" alt="alt text">

# Problem # 02

## Very large Prime Number Calculation

When it comes to storing very large numbers, one possible way is to use a linked list. For example, if you want to store a 1024-bit random number, you can store 32-bit integers in each node of the lined list. The linked list as a whole, then contains the 1024-bit number. Or you can take the digits of the big number, which can be fitted inside each node, and using a linked list can represent the number (e.g. to represent 1234567890123456789, you may keep 12345 in node1, 67890 in node 2 and so on so forth). This was the easy part. You are required to evaluate and determine, probabilistically or deterministically, whether a 1024-bit random number is prime or not. Since primitive data types cannot store a 1024-bit number, the number will be split across multiple linked list nodes. You can use any methodology to split the number and store it in the linked list, however pay special attention to memory usage and primality test.

## Task
-> Store a 1024-bit (309 digits) random number in a linked list.


-> Each node of the linked list can contain up to 64 bit numbers.


-> Implement any method to check for primality of this number.


-> Make sure your chosen method, operates across multiple nodes in the linked 

list (No partial primality tests).

### Approach
#### Data Representation Using Linked List:
-> The task requires storing a 1024-bit number, which is too large for primitive data types. Hence, a linked list is used to break the large number into 64-bit segments, with each segment stored in a node.
-> A Node class stores each 64-bit integer, and a LinkedList class manages the linked list. Each node points to the next, forming a chain representing the entire 1024-bit number.

#### Random 1024-bit Number Generation:
-> The random number is generated by creating 16 random 64-bit integers using the mt19937_64 generator. Each 64-bit integer is stored in a node of the linked list.
-> The linked list is constructed dynamically by appending each 64-bit integer to it. The complete number is also represented as a string for further operations (like primality testing).

#### Primality Test Using Miller-Rabin Algorithm:
-> The number stored across the linked list is converted into a string for processing.
-> The Miller-Rabin primality test is used to check whether the generated number is prime. This is a probabilistic algorithm that tests multiple bases (2, 3, 5, 7) for the number’s primality.
-> The algorithm runs multiple rounds, improving the accuracy of the result. If the number passes all tests, it is considered probably prime.

#### Modular Arithmetic for Large Numbers:
-> Since numbers are stored across multiple nodes, modular arithmetic operations (like power modulo and checking divisibility) are performed directly on the large number. The algorithm works efficiently even with the large size of the number.



### Assumptions
#### Uniform Distribution for Random Number Generation:

-> It is assumed that the uniform_int_distribution is sufficient to generate a uniformly distributed 1024-bit number, with no bias toward any specific number range.

#### 64-bit Node Storage:

-> Each node can store exactly a 64-bit number, and the number is divided into 16 nodes (64 bits × 16 = 1024 bits). This partitioning is assumed to fit within memory constraints and be efficient for manipulation.

#### Probabilistic Primality Test (Miller-Rabin):

-> The Miller-Rabin algorithm is a probabilistic test. This means there is a very small chance the algorithm could incorrectly identify a composite number as prime. For practical purposes, the assumption is that the test is reliable with small error probability after multiple rounds.

#### String Conversion for Primality Test:

-> For simplicity, the number stored in the linked list is converted into a string for primality testing. This assumes that the string can handle the size of the number without performance degradation or memory issues.


### Challenges Faced 
#### Challenge 1: Efficient Storage of Large Numbers:

-> Problem: Primitive data types cannot store 1024-bit numbers directly, and managing memory effectively when breaking the number into smaller chunks was critical.

-> Solution: The linked list was used to store the number in 64-bit segments, with each segment represented as a node. This allowed for modular storage and dynamic memory allocation, making it easier to handle large numbers.

#### Challenge 2: Primality Testing for Extremely Large Numbers:

-> Problem: A direct primality test for a 1024-bit number is computationally intensive and requires efficient algorithms.

-> Solution: The Miller-Rabin test, which is probabilistic and operates efficiently for large numbers, was chosen. This reduces computational overhead while maintaining high accuracy. Additionally, the test was adapted to work on the number stored across multiple nodes.

#### Challenge 3: Modular Arithmetic Across Multiple Nodes:

-> Problem: Operations like modular exponentiation required for primality tests are complicated when the number is stored across multiple nodes in a linked list.

-> Solution: The number was converted into a string, and modular arithmetic was applied on the string representation. This simplified operations like division, exponentiation, and modulo checks without needing to process each node individually during the test.

#### Challenge 4: Handling Memory Constraints:

-> Problem: The task of storing a 1024-bit number in memory-efficient data structures without causing memory overflow was a challenge.

-> Solution: By dividing the large number into 64-bit segments and storing each in a node of the linked list, memory consumption was controlled. Additionally, the use of a linked list allowed dynamic memory allocation, which grows as needed without reserving excessive memory upfront.

#### Challenge 5: Random Number Generation:

-> Problem: Generating a truly random 1024-bit number that is uniformly distributed is non-trivial, and ensuring randomness for cryptographic purposes or secure computation can be complex.

-> Solution: The random_device and mt19937_64 random number generator were used, ensuring high-quality random numbers. The numbers were split into 64-bit chunks and inserted into the linked list to form a complete 1024-bit number.

### Output

![alt text](/home/abdulmateen/Nust/3rd_Semister/DSA_LAB/DSA_Assignment_01/Problem2ss.png)
<img src="/home/abdulmateen/Nust/3rd_Semister/DSA_LAB/DSA_Assignment_01/Problem2ss.png" alt="alt text">

### Git Hub Link
https://github.com/AbdulMateen12344567/DSA-assignment
