/*********************************************************************** 
3-2
Add a read_from and a write_to function to Listing 3-6. 
These functions should read or write to upper or lower as appropriate. 
Perform bounds checking to prevent buffer overflows 
***********************************************************************/
 
#include <cstdio>
#include <cstring> 

/*
void read_from(const char* source, char* destination, size_t size, size_t index) {
    // Perform bounds checking to prevent buffer overflows
    if (index < size) destination[0] = source[index];
    
    else printf("Error: Index out of bounds.\n");
}

void write_to(char* destination, size_t size, size_t index, char value) {
    // Perform bounds checking to prevent buffer overflows
    if (index < size) destination[index] = value;
    
    else printf("Error: Index out of bounds.\n");
}

int main() {
    char lower[] = "abc?e";

    char upper[] = "ABC?E";

    char letter_d, letter_D;

    write_to(upper, sizeof(upper), 3, 'D'); // Write 'D' to upper

    write_to(lower, sizeof(lower), 3, 'd'); // Write 'd' to lower

    read_from(lower, &letter_d, sizeof(lower), 3); // Read 'd' from lower

    read_from(upper, &letter_D, sizeof(upper), 3); 

    printf("letter_D: %c\n", letter_D); 

    printf("letter_d: %c\n", letter_d);
  
    printf("upper: %s\n", upper);

    printf("lower: %s\n", lower);

    // Perform bounds checking to prevent buffer overflows
    write_to(lower, sizeof(lower), 7, 'g'); // This will trigger an error message

    printf("Address of letter_D: 0x%x",letter_D); 
}
*/



/********************************************************************************************* 
3-3
Add an Element* previous to Listing 3-9 to make a doubly linked list. 
Add an insert_before method to Element. 
Traverse the list from front to back, then from back to front, using two separate for loops. 
Print the operating_number inside each loop.
***********************************************************************************************/

 
struct Element {
    Element* next{};

    Element* previous{}; 

    void insert_after(Element* new_element) {
        new_element->next = next;

        next = new_element;

        new_element->previous = this;
    }

    void insert_before(Element* new_element) {
        new_element->previous = previous; 

        previous = new_element; 

        new_element->next = this; 
    }

    char prefix[2];

    short operating_number;
};

int main() {
    Element trooper1, trooper2, trooper3, trooper4;

    trooper1.prefix[0] = 'T';
    trooper1.prefix[1] = 'K';
    trooper1.operating_number = 421;
    
    trooper2.prefix[0] = 'F';
    trooper2.prefix[1] = 'N';
    trooper2.operating_number = 2187;
    trooper2.insert_after(&trooper3);
    trooper2.insert_before(&trooper1); 

    trooper3.prefix[0] = 'L';
    trooper3.prefix[1] = 'S';
    trooper3.operating_number = 005;
    trooper3.insert_after(&trooper4);

    trooper4.prefix[0] = 'M'; 
    trooper4.prefix[1] = 'B'; 
    trooper4.operating_number = 223; 

    printf("From Front to Back:\n"); 
    for(Element* cursor=&trooper1; cursor; cursor=cursor->next) {
        printf("Storm Trooper %c%c-%03hd\n", 
            cursor->prefix[0], 
            cursor->prefix[1], 
            cursor->operating_number
        );
    }

    printf("\nFrom Back to Front:\n"); 
    for (Element* cursor = &trooper4; cursor; cursor = cursor -> previous) {
        printf("Storm Trooper %c%c-%03hd\n", 
            cursor->prefix[0], 
            cursor->prefix[1], 
            cursor->operating_number
        );
    }
}