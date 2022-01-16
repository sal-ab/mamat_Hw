#include "ip.h"
#include "string.h"
#include "field.h"

#define MIN 0
#define MAX 255
#define VALID_SIZE 2
#define IP_SIZE 4
#define BYTE 8
#define WORD 32
#define SLASH "/"
#define DOT "."
#define ERROR -1

 
unsigned int dots_no_more(String val, bool *flag);



Ip::Ip(String str) : Field(str){
	this->ip = str;
	String rule;
}

Ip::~Ip(){
}



bool Ip::set_value(String val) {
	String *out;
	size_t size=0;
	val.split(SLASH , &out, &size);
	if(size != VALID_SIZE){
		if(size!=0){
			delete[] out;
		}
		return false;
	}
	this->mask =WORD-(out[1].trim().to_integer());
	bool flag;
	if(this->mask <0 || this->mask>32){
		return ERROR;
	}
	this->int_ip = dots_no_more(out[0],&flag);
	this->flag = flag;
	delete[] out;
	return(this->flag);
}




bool Ip::match_value(String packet) const {
	bool *flag;
	unsigned int num = dots_no_more(packet, flag);
	if (this->mask == WORD){
		return true;
	}
	return(((this->int_ip >> this->mask) == (num >> this->mask)) && *flag);	
}



/**
	* @brief removes dots from Ip address.
	*  returns unsingned int value of address.
*/ 

unsigned int dots_no_more(String val, bool *flag){
	String *out;
	size_t size = 0;
	*flag = true;
	unsigned int address[IP_SIZE]={0};
	val.split(DOT, &out , &size);
	if(size != IP_SIZE){
		if(size!=0){
			delete[] out;
		}
		*flag = false;
		return ERROR;
	}
	for(int i=0;i<IP_SIZE;i++){
		address[i] = (out[i]).trim().to_integer();
		if (address[i]<MIN || address[i]>MAX){
			delete[] out;
			*flag = false;
			return ERROR;
		}
		address [i] = address[i]<<BYTE*(IP_SIZE-i-1);
	}
	delete[] out; // check syntax
	return ((unsigned int)(address[3] | address[2] | address[1] | address[0]));
}




