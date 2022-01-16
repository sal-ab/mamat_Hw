#include "string.h"
#include "field.h"




class Ip : public Field{
public:
	String ip;
	String rule;
private:
	int mask=0;
	unsigned int int_ip=0;
	bool flag = true;
public:
/**
	* @brief Initiates an Ip from a string.
*/  
	Ip(const String str);
	~Ip();
/**
	* @brief checks if Ip value is valid.
	* returns 0 if not valid.
*/  	
	bool set_value(String val);
/**
	* @brief checks if Ip value matches rule set by set_value.
	*  returns true if matches.
*/  	
	bool match_value(String packet) const;
};
