#include "Cs246-A3Q2-istring.h"
#include <iostream>
#include <cstring>

using namespace std;

iString::iString():chars(NULL),length(0),capacity(0){}

iString::iString(const char * arr){
	int len=strlen(arr);	
	for(int i=0; i<len; i++){
		if(capacity == 0){
			capacity = 5;
			chars = new char [capacity];
		}
		else if(i == capacity-1){
			capacity = capacity * 2;
			char * temp = new char [capacity];
			for(int j=0; j < len; j++){
				temp[j] = chars[j];
			}
			delete [] chars;
			chars = temp;
		}		
		chars[i]=arr[i];
		length = length + 1;
	}
	chars[len+1] = '\0';
}

iString::iString(const iString& str){
	length = str.length;
	capacity = str.capacity;
	if(capacity == 0){
		chars = NULL;
	}
	else{
		chars = new char [capacity];
		for(int i=0; i<length; i++){
			chars[i] = str.chars[i];
		}
	}
}

iString& iString::operator=(const iString& str){
	length = str.length;
	capacity = str.capacity;
	delete [] chars;
	if(capacity == 0){
		chars = NULL;
	}
	else{
		chars = new char [capacity];
		for(int i=0; i<length; i++){
			chars[i] = str.chars[i];
		}
	}
}

iString:: ~iString(){
	delete [] chars;
	chars = NULL;
}

istream &operator>>(istream &in, iString& str){
	int capacity = 5;
	int length = 0;
	char * chars = new char [capacity];	
	char a;
	int i=0;
	while(true){
		in >> a;
		if((in.peek() == ' ')||(in.peek() == '\n')){
			chars[i] = a;
			chars[i+1] = '\0';
			length++;
			break;
		}
		else{
			if(i == capacity-2){
				capacity = capacity * 2;
				char * temp = new char [capacity];
				for(int j=0; j < length; j++){
					temp[j] = chars[j];
				}
				delete [] chars;
				chars = temp;
			}
			else{
				chars[i] = a;
				i++;
				length++;
			}
		}
	}
	chars[length + 1] ='\0';
	str.chars = chars;
	str.length = length;
	str.capacity = capacity;
	return in;
}

ostream &operator<<(ostream &out,const iString &str){
	if(str.length != 0){
		out<<str.chars;
		return out;
	}
	else{
		return out;
	}
}

iString operator+(const iString &str1, const iString &str2){
	iString str;
	str.length = str1.length + str2.length;
	str.capacity = str1.capacity + str2.capacity;
	str.chars = new char [str.capacity];
   if((str1.chars != NULL) && (str2.chars != NULL)) {
      strcpy(str.chars, str1.chars);
      strcat(str.chars, str2.chars);
   }
   else if((str1.chars == NULL) && (str2.chars != NULL)) {
      strcpy(str.chars, str2.chars);
   }
   else if((str1.chars != NULL) && (str2.chars == NULL)) {
      strcpy(str.chars, str1.chars);
   }
   else {
      str.chars = NULL;
   }
   return str;
}
	
iString operator+(const char *str1, const iString &str2){
	iString istr;
	istr.length = strlen(str1) + str2.length;
	istr.capacity = strlen(str1) + str2.capacity + 1;
	istr.chars = new char [istr.capacity];
   strcpy(istr.chars, str1);
	if(str2.chars != NULL){
   	strcat(istr.chars, str2.chars);
	}
   return istr;
}

iString operator+(const iString &str1, const char *str2){
	iString istr;
	istr.length = strlen(str2) + str1.length;
	istr.capacity = strlen(str2) + str1.capacity + 1;
	istr.chars = new char [istr.capacity];
	if(str1.chars != NULL){
   	strcpy(istr.chars, str1.chars);
   	strcat(istr.chars, str2);
	}
	else{
		strcpy(istr.chars, str2);
	}
   return istr;
}

bool sub(char * str1, char * str2){
	int len = strlen(str2);
   for(int i = 0; i < len; i++) {
      if(str1[i] != str2[i]) return false;
   }
   return true;
}
	

int operator / (const iString &str1, const iString &str2) {
	int place = 0;
	int len1 = str1.length;
	int len2 = str2.length;
	if (len1 <= len2){
		return -1;
	}
	while(true){
		if(place > len1 - len2) return -1;
		char * help = new char [str2.capacity];
		for(int i=0;i<str2.length; i++){
			help[i] = str1.chars[i+place];
		}
      if(sub(help, str2.chars)) {
			delete [] help;
         return place;
      }
		else{
			delete [] help;
			place++;
		}
	}
}

iString operator % (const iString &str, int a){
	iString str1;
	str1.length = str.length - a;
	str1.capacity = str.capacity - a + 1;
	char * help = new char [str.capacity];
	for(int i=0; i< str.length-a; i++){
		help[i] = str.chars[i+a];
	}
	str1.chars = help;
	return str1;
}
