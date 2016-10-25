//Edward Bates emb160030 Project 3
//BINARY SEARCH LINES 350 - 378, CALL LINE 470 && 500
//INPUT VALIDATION


#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int convertToArabic(string rom) {
	int sum = 0;
	//Checks every character in the roman numeral
	//Looks for each value in the tens place and for 4s and 9s checks after C, X or I
	for (int i = 0; i < rom.length(); i++)
	{
		if (rom[i] == 'M')
			sum += 1000;
		else if (rom[i] == 'D')
			sum += 500;
		else if (rom[i] == 'C' && (rom[i + 1] == 'M' || rom[i + 1] == 'D'))
			sum -= 100;
		else if (rom[i] == 'C')
			sum += 100;
		else if (rom[i] == 'L')
			sum += 50;
		else if (rom[i] == 'X' && (rom[i + 1] == 'L' || rom[i + 1] == 'C'))
			sum -= 10;
		else if (rom[i] == 'X')
			sum += 10;
		else if (rom[i] == 'V')
			sum += 5;
		else if (rom[i] == 'I' && (rom[i + 1] == 'V' || rom[i + 1] == 'X'))
			sum -= 1;
		else if (rom[i] == 'I')
			sum += 1;
	}
	return sum;

}

string convertToRoman(int num) {
    //Gets the number in the thousands, hundreds, tens and ones place
	string output = "";
	int thou = num / 1000;
	int hun = (num % 1000) / 100;
	int tens = ((num % 1000) % 100) / 10;
	int ones = (((num % 1000) % 100) % 10);

	//looks first for places that are less than 4
	//then checks for 4 and 5 nad adds those values
	//then adds any values greater than 5

	if (thou > 0 && thou <= 4)
	{
		for (int i = 0; i < thou; i++)
		{
			output += "M";
		}
	}
	if (hun > 0 && hun < 4)
	{
		for (int i = 0; i < hun; i++)
		{
			output += "C";
		}
	}
	else if (hun == 4) {
		output += "CD";
	}
	else if (hun == 5) {
		output += "D";
	}
	else if (hun > 5 && hun < 9)
	{
	    output += "D";
		for (int i = 5; i < hun; i++)
		{
			output += "C";
		}
	}
	else if (hun == 9)
		output += "CM";

	if (tens > 0 && tens < 4) {
		for (int i = 0; i < tens; i++)
		{
			output += "X";
		}
	}
	else if (tens == 4)
	{
		output += "XL";
	}
	else if (tens == 5)
	{
		output += "L";
	}
	else if (tens > 5 && tens < 9)
	{
	    output += "L";
		for (int i = 5; i < tens; i++)
		{
			output += "X";
		}
	}
	else if(tens == 9){
		output += "XC";
	}
	if (ones > 0 && ones < 4) {
		for (int i = 0; i < ones; i++) {
			output += "I";
		}
	}
	else if (ones == 4)
	{
		output += "IV";
	}
	else if (ones == 5) {
		output += "V";
	}
	else if (ones > 5 && ones < 9) {
        output += "V";
		for (int i = 5; i < ones; i++)
		{
			output += "I";
		}
	}
	else if(ones == 9){
		output += "IX";
	}
	return output;
}

bool decInvalid(string str){
    //Converts input from string to int
    stringstream myStream(str);
    int i;
    myStream >> i;
    //Checks if input is in the right range, also checks the conversion worked
    if(i > 0 && i < 4999){
        return false;
    }
    return true;
}

bool romInvalid(string str){
    //Checks if string contains an characters other than the ROman ones
    for(int i = 0;i < str.length();i++){
        if(str[i] != ' ' && str[i] != 'I' && str[i] != 'V' && str[i] != 'X' && str[i] != 'L' && str[i] != 'C' && str[i] != 'D' && str[i] != 'M'){
            return true;
        }
    }
    //Checks if I is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'I'){
            for(int j = i;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != ' '){
                    return true;
                }
            }
        }
    }

    //Checks if V is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'V'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != ' '){
                    return true;
                }
            }
        }
    }

    //Checks if X is followed by any characters it shouldn't be

    for(int i = 0;i < str.length();i++){
        if(str[i] == 'X'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X' && str[j] != ' ')
                    return true;
            }
        }
    }

    //Checks if L is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'L'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X' && str[j] != ' ')
                    return true;
            }
        }
    }

    //Checks if C is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'C'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X' && str[j] != 'C' && str[j] != 'L' && str[j] != ' ')
                    return true;
            }
        }
    }

    //Checks if D is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'D'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X'&& str[j] != 'C'&& str[j] != 'L' && str[j] != ' ')
                    return true;
            }
        }
    }

    //Checks if M is followed by any characters it shouldn't be
    for(int i = 0;i < str.length();i++){
        if(str[i] == 'M'){
            for(int j = i+1;j < str.length();j++){
                if(str[j] != 'I' && str[j] != 'V' && str[j] != 'X'&& str[j] != 'C'&& str[j] != 'L'&& str[j] != 'D' && str[j] != 'M' && str[j] != ' ')
                    return true;
            }
        }
    }

    return false;
}

//Creates node
struct node{
    string roman;
    int arabic;
    node*next;
};

//Creates a dynamic node and puts it at the end of the linked list
void EnQueue(node *&head,string rom,int arabic)
{
    node *newNode = new node;
    newNode->roman = rom;
    newNode->arabic = arabic;
    newNode->next = nullptr;

    //If the list is empty sets head to the first node
    if(head == nullptr){
        head = newNode;
        return;
    }

    //Loops though list and adds node at the end
    node *cur = head;
    while(cur->next != nullptr){
        cur = cur->next;
    }
    cur->next = newNode;
    return;
}

//Linear search no longer used because of binary search
void lSearch(node*head,int num){
    node* cur = head;
    while(cur){
        if(cur->arabic == num){
            cout << endl << num << " Was found.";
        }
        cur = cur->next;
    }
}

//Roman numeral sort
void SortR(node*&head){
    node * prev;
    node*cur;
    node*after;
    bool swapped;

    cur = head;
    swapped = true;
    //Continues while values have been swapped
    while(swapped){
        swapped = false;
        cur = head;
        prev = nullptr;
        //loops until end of list
        while(cur->next != nullptr){
            after = cur->next;
            //If values are out of order they are swapped
            if(cur->roman > cur->next->roman){
                if(prev == nullptr){
                    head = after;
                    cur->next = after->next;
                    after->next = cur;
                }
                else{
                prev->next = cur->next;
                cur->next = after->next;
                after->next = cur;
                }
                swapped = true;

            }
            prev = cur;
            cur = after;
        }
    }
}

//Sorts by arabic value
void SortD(node*&head){
    node * prev;
    node*cur;
    node*after;
    bool swapped;

    cur = head;
    swapped = true;
    //Continues while values have been swapped
    while(swapped){
        swapped = false;
        cur = head;
        prev = nullptr;
        //loops until end of list
        while(cur->next != nullptr){
            after = cur->next;
            //If values are out of order they are swapped
            if(cur->arabic > cur->next->arabic){
                if(prev == nullptr){
                    head = after;
                    cur->next = after->next;
                    after->next = cur;
                }
                else{
                prev->next = cur->next;
                cur->next = after->next;
                after->next = cur;
                }
                swapped = true;

            }
            prev = cur;
            cur = after;
        }
    }
}

//Binary search on list uses recursion
bool binSearch(node*head,int length,int target){
    node*cur = head;
    int count = 0;
    //Goes to middle of list
    while(cur->next && count < (length / 2)){
        count++;
        cur = cur->next;
    }
            //If only 1 value remains it is checked, base case
            if(length == 1){
                if(cur->arabic == target){
                    return true;
                }
                return false;
            }

            //If value is found true is returned and it stops searching
            if(cur->arabic == target){
                return true;
            }
            //If the middle value is greater than what is being searched for, the search is called recursively on the first half of the list
            else if(cur->arabic > target){
                return binSearch(head, length / 2, target );
            }
            //If the middle value is less than what is being searched for, the search is called recursively on the second half of the list
            else if(cur->arabic < target){
                return binSearch(cur,(length / 2) + 1,target);
            }
}

//Used to copy list, so it can be sorted for binary search
node* copy(node*head){
    node*head2;
    node*cur = head2;

    //Loops original and adds each node to a new list
    while(head){
        cur->next = new node{head->roman,head->arabic,nullptr};
        head=head->next;
        cur = cur->next;
    }
    return head2;
}


int main()
{
    string fileName = "numbers.txt";
    ifstream file(fileName);
    string line;
    int i;
    node * hold = new node;
    node * head;
    head = nullptr;
    hold->next = nullptr;
    node * noConflict;

    //Reads each line of file
    while(file.good())
    {
        getline(file,line);
        //If the line is arabic
        if(line.substr(0,1) == " ")
        {
            //If it's invalid, it skips the line
            if(decInvalid(line.substr(16,20))){
                continue;
            }

            //converts to roman and adds it to the linked list
            stringstream myStream(line.substr(16,20));
            myStream >> i;
            EnQueue(head,convertToRoman(i), i);
        }
        else{
            //checks if its a roman numeral, if not its skipped
            if(romInvalid(line.substr(0,16))){
                continue;
            }
            //If it is a roman numeral it is converted to arabic and added to the list
            EnQueue(head,line.substr(0,16), convertToArabic(line.substr(0,16)));
        }

    }


    //interface
    int choice = 0;
    string target;
    bool stage1 = true;
    //Keeps the menu up until exit is selected
    while(stage1){
        cout << endl << "Enter 1,2, or three to chose"<< endl;
        cout << "\t1\tSearch" << endl;
        cout << "\t2\tSort" << endl;
        cout << "\t3\tExit" << endl;
        choice = 0;
        cin >> choice;
        //Checks if input is valid
        switch(choice){
        case 1:
            cout << "What would you like to search for" << endl;
            cin >> target;

            //checks if search target is a roman numeral
            if(!romInvalid(target)){
                //Don't remove
                cout << "";
                node*head2 = copy(head);
                SortD(head2);

                //Roman is converted to arabic for the search
                i = convertToArabic(target);

                node*countP = head2;
                //Counts the length of the list
                int count = 1;
                while(countP->next){
                    count++;
                    countP = countP->next;
                }
                //Runs binary search
                if(binSearch(head2,count,i)){
                    cout << endl << i << " Was found";
                }
                else{
                    cout << endl << i << " Wasn't found";
                }
                delete head2;
                break;
            }

            //If the target is in arabic
            if(!decInvalid(target)){
                //Don't remove
                cout << "";
                node*head2 = copy(head);
                SortD(head2);

                //Convert into an int for the search
                stringstream myStream(target);
                int i;
                myStream >> i;

                node*countP = head2;
                //Length is determined by counting values
                int count = 1;
                while(countP->next){
                    count++;
                    countP = countP->next;
                }
                //Runs binary search
                if(binSearch(head2,count,i)){
                    cout << endl << i << " Was found";
                }
                else{
                    cout << endl << i << " Wasn't found";
                }
                delete head2;
            }
            else{
                cout << "Invalid Input" << endl;
            }
            break;
        //Sort
        case 2:{
            bool stage2 = true;
            //Stays in menu until a valid search is picked
            while(stage2){
                cout << endl << "\t1\tby Romman" << endl;
                cout << "\t2\tby Arabic" << endl;
                int choice2;
                cin >> choice2;
                cin.clear();
                //determines the search to be preformed
                switch(choice2){
                case 1:
                    SortR(head);
                    noConflict = head;
                    while(noConflict){
                        cout << noConflict->roman << endl;
                        noConflict = noConflict->next;
                    }
                    stage2 = false;break;
                case 2:
                    SortD(head);
                    noConflict = head;
                    while(noConflict){
                        cout << noConflict->arabic << endl;
                        noConflict = noConflict->next;
                    }
                    stage2 = false;break;
                default:
                    cout << "Invalid Input" << endl;
                    choice2 = 0;
                    cin.clear();
                    cin.ignore(256, '\n');
                    break;
                }
            }
            break;
        }
        //Ends menu and program
        case 3:
            stage1 = false;
            break;
        default:
            cout << "Invalid Choice";
            choice = 0;
            cin.clear();
            cin.ignore(256, '\n');
            //break;

        }
    }


    //output to file
    file.close();
    //Opens file in output mode
    ofstream fileO(fileName);
    node*ptr = head;
    //Prints each node from list on a line into the file
    while(ptr != nullptr){
        fileO << ptr->roman;
        for(int i = 0; i + ptr->roman.length() < 20;i++){
            fileO << " ";
        }
        fileO << ptr->arabic << endl;
        ptr = ptr->next;
    }

    delete head;
    return 0;
}
