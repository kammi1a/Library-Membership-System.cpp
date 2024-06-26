### 1. Project's purpose : 

- The Library Membership Management System is designed to streamline the process of managing library memberships. 
It allows users to register new members, renew existing memberships, cancel memberships, and display all members' details. 
- The system ensures data integrity, provides a user-friendly command-line interface, and offers functionalities for data persistence and report generation.




### 2. Design Decisions : 

- Struct Definition: A LibraryMember struct is used to encapsulate the details of a library member, including name, address, and contact information.
- Global Vector: A global vector named members is employed to store instances of LibraryMember struct, ensuring easy access and management of member records.
- Input Validation: Basic input validation is implemented to prevent invalid data entry and maintain data integrity.
- Command-Line Interface: Interaction with the application occurs through a command-line interface, offering simplicity and ease of use.
- Modular Design: Functions are logically divided to perform specific tasks such as member registration, membership renewal, membership cancellation, and displaying all members' details, enhancing code organization and reusability.
- Data Persistence: Membership data is stored persistently in memory throughout the program's execution and saved to files for long-term storage between sessions.




### 3. Algorithms Used :

- Search Algorithm: Linear search algorithm is used to find a library member by name when renewing or canceling membership.




### 4. Data Structures Employed :

- Struct: The LibraryMember struct is employed to encapsulate member details.
- Vector: A vector named members is used to store instances of LibraryMember, providing dynamic storage for member records.




### 5. Functions/Modules Created : 

- RegisterMember: Registers a new library member by adding their details to the members vector.
- RenewMembership: Renews the membership of an existing library member by searching for their name in the members vector and displaying a success message if found.
- CancelMembership: Cancels the membership of an existing library member by searching for their name in the members vector, removing them from the vector if found, and displaying a success message.
- DisplayAllMembers: Displays details of all library members stored in the members vector.




### 6. How to Use the Software : 

- Installation: No installation required. Simply compile the provided code using a C++ compiler.
- Setup Instructions: Compile the code and run the executable. 
Follow the on-screen prompts to perform various operations such as registering members, renewing memberships, canceling memberships, and displaying all members' details.


### 7. Screenshots :
![Example Image](https://github.com/kammi1a/Library-Membership-System.cpp/blob/main/CC9EEC0A-DEE0-4233-9584-22FAD7F7435E_1_201_a.jpeg)
