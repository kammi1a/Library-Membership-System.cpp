# Features   
                                                                         

                                                                         
## 1. Member Management                                                                         

#### Register Member
Description: Allows the user to add a new member to the library.
Input:
Name (string)
Address (string)
Contact (string)
Output:
Confirmation message: "Member [Name] registered successfully!"

#### Renew Membership

Description: Enables the user to renew the membership of an existing member.
Input:
Contact (string)
Qantity (integer)
Duration (string: "days" or "years")
Output:
If successful: "Membership renewed for [Name] for [Quantity] [Duration]"
If member not found: "Member not found!"
If invalid unit: "Membership renewal failed."

#### Cancel Membership

Description: Allows the user to cancel the membership of an existing member.
Input:
Contact (string)
Output:
If successful: "Membership canceled for [Name]"
If member not found: "Member not found!"

#### Display All Members

Description: Displays a list of all registered members.
Output:
List of members with their details: "Name: [Name], Address: [Address], Contact: [Contact]"




## 2. Data Management
#### Save History to File

Description: Saves the current list of members to a file.
Output:
"History saved to data.txt"

#### Load History from File

Description: Loads the list of members from a file when the program starts.



## 3. User Interaction

#### Main Menu

Description: Provides a menu for the user to choose an action.
Options:
Register member
Renew membership
Cancel membership
Display all members
Save history to file
Exit
Output:
Prompts user to select an option by entering a number.



## 4. Error Handling
#### Input Validation

Description: Ensures that user inputs are valid.
Cases:
Non-empty strings for name, address, and contact








