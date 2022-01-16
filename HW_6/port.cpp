#include "port.h"


#define MAX 65535
#define MIN 0
#define STR_SIZE 2
#define DASH "-"

Port::Port(String str) : Field(str){
	this->min = 0;
	this->max = 0;
	this->port = str;
}

Port::~Port(){
}

bool Port::set_value(String value){
	String *sub_val;
	size_t size = 0;
	value.split(DASH,&sub_val,&size);
	if (size != STR_SIZE){
		delete[] sub_val;
		return false;
	}
	this->min = sub_val[0].trim().to_integer();
	this->max = sub_val[1].trim().to_integer();
	if (this->min < MIN || this->max > MAX || this->min > this->max){
		delete[] sub_val;
		return false;
	}
	delete[] sub_val;
	return true;
}


bool Port::match_value(String packet) const{
	int val = packet.trim().to_integer();
	if (val < this->min || val > this->max){
		return false;
	}
	return true;
}
