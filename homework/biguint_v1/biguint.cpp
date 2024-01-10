#include "biguint.h"

biguint::biguint(){
	for(int i = 0; i < CAPACITY; i++)
		data_[i] = 0;
}

biguint::biguint(const std::string & s){
 	for(int i = 0; i < s.length(); i++)
 		assert(0 <= s[i] - '0' && s[i] - '0' <= 9);

 	for(int i = 0; i < s.length(); i++)
 		data_[i] = s[(s.length() - 1) - i] - '0';

 	for(int i = s.length(); i < CAPACITY; i++)
 		data_[i] = 0;
 }

unsigned short biguint::operator [](std::size_t pos) const{
	assert(pos < CAPACITY);

	return data_[pos];
}

void biguint::operator += (const biguint & b){

	std::size_t sum, carry(1);

	for(int i = 0; i < CAPACITY; i++){
		sum = data_[i] + b.data_[i];
		if(sum >= 10){
			data_[i] = sum - 10;
			//ignore last carry bit if any
			if((i < CAPACITY - 1) && (data_[i+1] != 0 || b.data_[i+1] != 0))
				data_[i+1] += carry;
		}
		else
			data_[i] = sum;
	}
}

void biguint::operator -= (const biguint & b){

	std::size_t rest, carry(1);

	if(compare(b) == -1 || compare(b) == 0){
		for(int i = 0; i < CAPACITY; i++)
			data_[i] = 0;
	}
	else{
		for(int i = 0; i < CAPACITY; i++){
			if(data_[i] < b.data_[i]){
				rest = (data_[i] + 10) - b.data_[i];
				data_[i] = rest; 
				data_[i+1] -= carry;
			}
			else{
				rest = data_[i] - b.data_[i];
				data_[i] = rest;
			}
		}
	}
}

int biguint::compare(const biguint & b) const{
	unsigned short aDigit, bDigit;

	for(int i = CAPACITY - 1; i >= 0; i--){
		if(data_[i] != 0 || b.data_[i] != 0){
			aDigit = data_[i] * (i+1);
			bDigit = b.data_[i] * (i+1);
			if(aDigit > bDigit)
				return 1;
			else if(bDigit > aDigit)
				return -1;
		}
	}
	return 0;
}

std::string biguint::toString() const{
	std::string number(""), numberNoZeros(""), add;
	int counter(0);

	for(int i = CAPACITY - 1; i >= 0; i--){
		add = '0' + data_[i];
		number += add;
	}

	//trim leading zeros
	for(int i = 0; i < number.length(); i++){
		if(number[i] != '0')
			counter++;

		if(counter == 0)
			continue;
		else
			numberNoZeros += number[i];
	}

	return numberNoZeros;
}

biguint operator + (const biguint & a, const biguint & b){
	biguint ans;

	ans += a;
	ans += b;

	return ans;
}

biguint operator - (const biguint & a, const biguint & b){
	biguint ans;

	ans = a;
	ans -= b;

	return ans;
}



bool operator < (const biguint & a, const biguint & b){
	if(a.compare(b) == -1)
		return true;
	else
		return false;
}

bool operator <= (const biguint & a, const biguint & b){
	if(a.compare(b) == -1 || a.compare(b) == 0)
		return true;
	else
		return false;
}

bool operator != (const biguint & a, const biguint & b){
	if(a.compare(b) != 0)
		return true;
	else
		return false;
}

bool operator == (const biguint & a, const biguint & b){
	if(a.compare(b) == 0)
		return true;
	else
		return false;
}

bool operator >= (const biguint & a, const biguint & b){
	if(a.compare(b) == 1 || a.compare(b) == 0)
		return true;
	else
		return false;
}

bool operator > (const biguint & a, const biguint & b){
	if(a.compare(b) == 1)
		return true;
	else
		return false;
}
std::ostream& operator <<(std::ostream& out, const biguint& b){
	for(int i = biguint::CAPACITY - 1; i >= 0; i--)
		out<<b[i];

	return out;
}





