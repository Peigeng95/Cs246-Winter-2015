#include <iostream>
using namespace std;

struct IntArray {
  int size;
  int capacity;
  int *contents;
};

IntArray readIntArray(){
	IntArray arr;
	arr.size = 0;
	arr.capacity = 0;
	arr.contents = NULL;//need to avoid delete nothing if call r on empty
	int x;
	while(true){
		cin >> x;
		if(cin.fail()){//read isn't a int
			cin.clear();
			cin.ignore();
			break;
		}
		if(arr.capacity == 0){//first read
			arr.capacity = 5;
			int *numarr = new int[5];
			arr.contents = numarr;
			arr.contents[0] = x;
			arr.size++;
		}
		else{//not first read
			if(arr.size == arr.capacity){//if reach the max
				arr.capacity = arr.capacity * 2;
				int *numarrlarge = new int[arr.capacity];
				for(int i=0; i<arr.size ; i++){
					numarrlarge[i] = arr.contents[i];
				}
				delete [] arr.contents;
				arr.contents = numarrlarge;
				arr.contents[arr.size] = x;
				arr.size++;
			}
			else if(arr.size < arr.capacity){//normal stuitation
                        	arr.contents[arr.size] = x;
                        	arr.size++;
                	}
		}
	}
	return arr;
}

void addToIntArray(IntArray& ia){
        int x;
        while(true){
                cin >> x;
                if(cin.fail()){//read not a int
                        cin.clear();
                        cin.ignore();
                        break;
		}
                if(ia.capacity == 0){//first read
                        ia.capacity = 5;
                        int *numarr = new int[5];
                        ia.contents = numarr;
                        ia.contents[0] = x;
                        ia.size++;
                }
		else{
                	if(ia.size == ia.capacity){//reach the max
                        	ia.capacity = ia.capacity * 2;
                        	int *numarrlarge = new int[ia.capacity];
                        	for(int i=0; i<ia.size ; i++){
                                	numarrlarge[i] = ia.contents[i];
                        	}
                        	delete [] ia.contents;
                        	ia.contents = numarrlarge;
                        	ia.contents[ia.size] = x;
				ia.size++;
                	}
			else if(ia.size < ia.capacity){//normal stuitation
                        	ia.contents[ia.size] = x;
                        	ia.size++;
			}
		}
	}
}


void printIntArray(const IntArray& ia){
	for(int i=0; i<ia.size; i++){//print in one line
		cout << ia.contents[i] << " ";
	}
	cout << endl;//end line
}


// Do not change this function!

int main() {  // Test harness for IntArray functions.
  bool done = false;
  IntArray a[4];
  a[0].contents = a[1].contents = a[2].contents = a[3].contents = 0;

  while(!done) {
    char c;
    char which;

    // Note:  prompt prints to stderr, so it should not occur in .out files
    cerr << "Command?" << endl;  // Valid commands:  ra, rb, rc, rd,
                                 //                  +a, +b, +c, +d,
                                 //                  pa, pb, pc, pd, q
    cin >> c;  // Reads r, +, p, or q
    if (cin.eof()) break;
    switch(c) {
      case 'r':
        cin >> which;  // Reads a, b, c, or d
        delete [] a[which-'a'].contents;
        a[which-'a'].contents = 0;
        a[which-'a'] = readIntArray();
        break;
      case '+':
        cin >> which;  // Reads a, b, c, or d
        addToIntArray(a[which-'a']);
        break;
      case 'p':
        cin >> which;  // Reads a, b, c, or d
        printIntArray(a[which-'a']);
        cout << "Capacity: " << a[which-'a'].capacity << endl;
        break;
      case 'q':
        done = true;
    }
  }

  for (int i = 0; i < 4; ++i) delete [] a[i].contents;
}
