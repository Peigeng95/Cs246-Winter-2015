#include "calc.h"
#include <iostream>
using namespace std;
//**************  zero argument constructor   ************************
Calc::Calc():error(false),display(0),oper('E'),result(0),memory(0){}



//**************   constructor   *************************************
Calc::Calc(const Calc &other):
	error(other.error),display(other.display),oper(other.oper),result(other.result),
	memory(other.memory){}

void Calc::digit(int d){
	if(this->display >=0){//display >= 0
		this->display = this->display * 10 + d;
	}
	else{//display <  0
		this->display = this->display * 10 - d;
	}
}


//********************    method below     ************************************
void Calc::op(char oper){
	if(this->oper == '+'){
		this->result = this->result + this->display;
		this->display = 0;
	}
	else if(this->oper == '='){
		this->result = this->display;
		this->display = 0;
	}
	else if(this->oper == '-'){
		this->result = this->result - this->display;
		this->display = 0;
	}
	else if(this->oper == '*'){
		this->result = this->result * this->display;
		this->display = 0;
	}
	else if(this->oper == '/'){
		if(this->display != 0){
			this->result = this->result / this->display;
			this->display = 0;
		}
		else{
			this->result = 0;
			this->display = 0;
			this->error = true;
		}
	}
	else{
		this->result = this->display;
		this->display = 0;
		this->oper = oper;
	}
	//update oper
	this->oper = oper;
}

void Calc::equals(){
	char op = this->oper;
	int a;
	if(this->error){
		this->display = 0;
		this->result = 0;
	}
	else{
		if(op == '+'){
			this->result = this->result + this->display;
			this->display = this->result;
			this->oper = 'E';
		}
		else if(op == '-'){
			this->result = this->result - this->display;
			this->display = this->result;
			this->oper = 'E';
		}
		else if(op == '*'){
			this->result = this->result * this->display;
			this->display = this->result;
			this->oper = 'E';
		}
		else if(op == '/'){
			if(this->display != 0){
				this->result = (int)this->result / (int)this->display;
				this->display = this->result;
				this->oper = 'E';
			}
			else{
				this->display = 0;
				this->result = 0;
				this->oper = 'E';
				this->error = true;
			}
		}
		else{
			this->result = this->display;
			this->oper = 'E';		
		}
	}		
}

void Calc::memPlus(){
	this->memory = this->display+ this->memory;
}

void Calc::memClear(){
	this->memory = 0;
}

void Calc::memRecall(){
	this->display = this->memory;
}

bool Calc::isError() const{
	return this->error;
}

void Calc::allClear(){
	this->error = false;
	this->display = 0;
	this->oper = 'E';//E represent empty
	this->result = 0;
	this->memory = 0;
}

//**********************   operator overload   *********************
ostream &operator<<(ostream &out,const Calc &c){
	out<<c.result;
	if(c.memory != 0){//memory check
		out<<" M: "<<c.memory;
	}
	if(c.error){//error check
		out<<" E";
	}
	return out;
}
