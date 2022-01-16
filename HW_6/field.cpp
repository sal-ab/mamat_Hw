#include "field.h"
#include <string.h>

#define OUR_DELIM ","
#define EQUAL_DELIM "="

  
Field::Field(String pattern){
this->pattern = pattern;
}

bool Field::match(String packet){
	bool flag = false;
	String *sub_packets;
	size_t size = 0;
	packet.split(OUR_DELIM , &sub_packets,&size);
	for (int i=0 ; i<(int)size ; i++){
		String *values;
		size_t num = 0;
		(sub_packets[i]).split(EQUAL_DELIM , &values,&num);
		(values[0])=(values[0]).trim();
		if ((this->pattern).equals(values[0])){
			flag = match_value((values[1]).trim());
		}
		delete[] values;	
	}
	delete[] sub_packets;
	return flag;	
}


Field::~Field() {
}
