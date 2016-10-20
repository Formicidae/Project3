//Edward Bates emb160030 Project 3
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
    return false;
}

bool romInvalid(string str){
    for(int i = 0;i < str.length();i++){
        if(str[i] != ' ' && str[i] != 'I' && str[i] != 'V' && str[i] != 'X' && str[i] != 'L' && str[i] != 'C' && str[i] != 'D' && str[i] != 'M'){
            cout<< endl << "problem char:" << str[i] << ":" << endl;
            return true;
        }
    }

    return false;
}

struct node{
    string roman;
    int arabic;
    node*next;
};

void EnQueue(node *&head,string rom,int arabic)
{
    cout << endl << "EnQueue" << endl;
    node *newNode = new node;
    newNode->roman = rom;
    newNode->arabic = arabic;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        return;
    }

    node *cur = head;
    while(cur->next != nullptr){
        cout<< "EnQueue loop" <<endl;
        cur = cur->next;
    }
    cur->next = newNode;
    cout << endl << "EnQueue" << endl;
    cout<< endl<< head->roman << endl<< endl;
    return;
}

void lSearch(node*head,int num){
    //cout << "Method isn't finsihed";
    node* cur = head;
    while(cur){
        if(cur->arabic == num){
            cout << endl << num << " Was found.";
        }
        cur = cur->next;
    }
}

void SortR(node*&head){
    node * prev;
    node*cur;
    node*after;
    bool swapped;

    cur = head;
    swapped = true;
    while(swapped){
        swapped = false;
        cur = head;
        prev = nullptr;
        while(cur->next != nullptr){
            after = cur->next;
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

void SortD(node*&head){
    node * prev;
    node*cur;
    node*after;
    bool swapped;

    cur = head;
    swapped = true;
    while(swapped){
        swapped = false;
        cur = head;
        prev = nullptr;
        while(cur->next != nullptr){
            after = cur->next;
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

bool binSearch(node*head,int length,int target){
    node*cur = head;
    int count = 0;
    while(cur->next && count < (length / 2)){
            count++;
            //cout << cur->arabic << " ";
                cur = cur->next;
    }
    //cout << "Finished while";
            if(length == 1){
                if(cur->arabic == target){
                    return true;
                }
                return false;
            }

            if(cur->arabic == target){
                return true;
            }
            else if(cur->arabic > target){
                return binSearch(head, length / 2, target );
            }
            else if(cur->arabic < target){
                return binSearch(cur,(length / 2) + 1,target);
            }
}

node* copy(node*head){
    node*head2;

    node*cur = head2;
    //cur = new node{head->roman,head->arabic,nullptr};

    while(head){
        cur->next = new node{head->roman,head->arabic,nullptr};
        head=head->next;
        cur = cur->next;
    }

    return head2;


}


int main()
{
    ifstream file("numbers.txt");
    string line;
    int i;
    //getline(file,line);
    node * hold = new node;
    node * head;
    head = nullptr;
    hold->next = nullptr;

    while(file.good())
    {
        getline(file,line);
        cout << line;
        if(line.substr(0,1) == " ")
        {

            if(decInvalid(line.substr(16,20))){
                continue;
            }

            stringstream myStream(line.substr(16,20));
            myStream >> i;
            cout << line.substr(16,20);
            cout << i;
            EnQueue(head,convertToRoman(i), i);
        }
        else{
            cout << "else";
            if(romInvalid(line.substr(0,16))){
                continue;
            }
            EnQueue(head,line.substr(0,16), convertToArabic(line.substr(0,16)));
        }

    }


    //interface
    int choice = 0;
    string target;
    bool stage1 = true;
    while(stage1){
        cout << endl << "Enter 1,2, or three to chose"<< endl;
        cout << "\t1\tSearch" << endl;
        cout << "\t2\tSort" << endl;
        cout << "\t3\tExit" << endl;
        cin >> choice;
        switch(choice){
        case 1:
            cout << "What would you like to search for" << endl;
            cin >> target;


            if(!romInvalid(target)){
                //Don't remove
                cout << "";
                node*head2 = copy(head);
                SortD(head2);

                i = convertToArabic(target);

                node*countP = head2;
                int count = 1;
                while(countP->next){
                    count++;
                    countP = countP->next;
                }
                cout << "\n List is " << count << " \nElements long";
                //lSearch(head,i);
                if(binSearch(head2,count,i)){
                    cout << endl << i << " Was found";
                }
                else{
                    cout << endl << i << " Wasn't found";
                }
                break;
            }


            if(!decInvalid(target)){
                //Don't remove
                cout << "";
                node*head2 = copy(head);
                SortD(head2);

                stringstream myStream(target);
                int i;
                myStream >> i;

                node*countP = head2;
                int count = 1;
                while(countP->next){
                    count++;
                    countP = countP->next;
                }
                cout << "\n List is " << count << " \nElements long";
                //lSearch(head,i);
                if(binSearch(head2,count,i)){
                    cout << endl << i << " Was found";
                }
                else{
                    cout << endl << i << " Wasn't found";
                }
            }
            else{
                cout << "Invalid Input" << endl;
            }
            break;
        case 2:{
            bool stage2 = true;
            while(stage2){
                cout << endl << "\t1\tby Romman" << endl;
                cout << "\t2\tby Arabic" << endl;
                int choice2;
                cin >> choice2;
                cin.clear();
                switch(choice2){
                case 1:
                    SortR(head);stage2 = false;break;
                case 2:
                    SortD(head);stage2 = false;break;
                default:
                    cout << "Invalid Input" << endl;break;
                }
            }
            break;
        }
        case 3:
            stage1 = false;
            break;

    }
    }


    //output to file
    file.close();
    ofstream fileO("numbers.txt");
    node*ptr = head;
    while(ptr != nullptr){
            //cout<< "print";
        fileO << ptr->roman;
        for(int i = 0; i + ptr->roman.length() < 20;i++){
            fileO << " ";
        }
        fileO << ptr->arabic << endl;
        ptr = ptr->next;
    }


    return 0;
}
