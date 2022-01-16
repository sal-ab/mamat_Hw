#include "string.h"
#include <string.h>
#include <vector>
#include <iostream>

#define SPACE " "


int count_substring (const char *delimiters, char *str);





String::String(){
	this->data = NULL;
}
	

String::String(const String &str){
	this->length = str.length;
	this->data = new char[(this->length) + 1];
	strcpy(this->data,str.data);
}

String::String(const char *str){
	this->length = strlen(str)+1;
	this->data = new char[(this->length) + 1];
	strcpy(this->data,str);
}


String::~String(){
}

String& String::operator=(const String &rhs){ //Look!
	if(this == &rhs){
		return *this;
	}
	
	this->length = rhs.length;
	delete[] this->data;
	this->data = new char[(this->length)+1];
	strcpy(this->data,rhs.data);
	return *this;
}



String& String::operator=(const char *str){ //check with M
	if (this->data == str){
		return *this;
	}
	this->length = strlen(str);
	delete[] this->data;
	this->data = new char[(this->length)+1];	
	strcpy(this->data,str);
	return *this;
}


bool String::equals(const char *rhs) const{
	return (!strcmp(this->data,rhs));
}


bool String::equals(const String &rhs) const{
		return (!strcmp(this->data,rhs.data));
}


void String::split(const char *delimiters, String **output, size_t *size) const{ //Look closely please!
	String copy = String(this->data);
	int k = count_substring(delimiters,copy.data);
	if (output == NULL){
		*size = (size_t)k;
		return;
	}
	int count=0;
	 *output = new String[k];
	char *s = this->data;
	char *token = strsep( &s,delimiters);
	while (s != NULL){
		(*output)[count] = token;
		token = strsep( &s,delimiters);
		count++;
	}
	(*output)[count] = token;
	*size = (size_t)k;
}



/**
	* @brief seprates string into sub-strings by delimiters.
	*  returns the number of sub-strings.
*/  
int count_substring (const char *delimiters, char *str){ //check forums
	if (str == NULL){
		return 0;
	}
	char *token;
	token = strtok(str,delimiters);
	int count = 0;
	while (token != NULL){
		token = strtok(NULL,delimiters);
		count++;
	}
return count;
}



int String::to_integer() const{
	return (atoi(this->data));
}


String String::trim() const{//Look again
	char* space_free = new char[(this->length)+1];
	int i = 0, j = this->length-1;
	strcpy(space_free,this->data);
	while(space_free[i] == *SPACE){
		i++;
	}
	while(space_free[j] == *SPACE){
		j--;
	}
	char* trimmed = new char[j-i+1];
	int k=0;
	while (!(i>j)){
		trimmed[k] = space_free[i];
		k++;
		i++;	
	}
	trimmed[k] = '\0';
	String str_trimmed = String(trimmed);
	delete[] trimmed;
	delete[] space_free;
	return str_trimmed;
}








































