//how c++ pass an obj of the same class behaves
//BCS370 additional material
//10-26-19 gz

#include <iostream>
#include <string>

class TrivialClass {
public: 
  TrivialClass(const std::string & data) :
    mData(data) {};

  void concat(const TrivialClass &data) {
	this->mData += data.mData;
  }
  
  std::string getData() const {return mData;} //regular getter
  
  const std::string& getData(const TrivialClass & rhs) const { //get another obj's data
    return rhs.mData;
  };

private:
  std::string mData;
};

int main() {
  TrivialClass a("fish");
  TrivialClass b("heads");

  std::cout << "b via a = " << a.getData(b) << std::endl;
  a.concat(b);
  std::cout <<"a+b=" << a.getData() << std::endl;
  return 0;
}