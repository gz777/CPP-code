//data structure: map
//resource: https://thispointer.com/stdmap-tutorial-part-1-usage-detail-with-examples/
//http://www.cplusplus.com/reference/set/set/
//cpp.sh/77rnc

#include <iostream>
#include <map>
#include <string>
 
int main()
{
    std::map<std::string, int> mapOfWords;
    
    // Inserting data in std::map
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("moon", 2));
    mapOfWords["sun"] = 3; //If specified key already existed in map then operator [] will silently change its value where as insert will not replace already added key instead it returns the information i.e. if element is added or not.
    
    // Will replace the value of already added key i.e. earth
    mapOfWords["earth"] = 4;
    
    // Iterate through all elements in std::map
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        std::cout<<it->first<<" :: "<<it->second<<std::endl; //first: key; second: value
        it++;
    }
    
    // Check if insertion is successful or not
    if(mapOfWords.insert(std::make_pair("earth", 1)).second == false)
    {
        std::cout<<"Element with key 'earth' not inserted because already existed"<<std::endl;
    }
    
    // Searching element in std::map by key.
    if(mapOfWords.find("sun") != mapOfWords.end())
        std::cout<<"word 'sun' found"<<std::endl;
        
    if(mapOfWords.find("mars") == mapOfWords.end())
        std::cout<<"word 'mars' not found"<<std::endl;
    return 0;
}

/*
Some basic functions associated with Map:
begin() 每 Returns an iterator to the first element in the map
end() 每 Returns an iterator to the theoretical element that follows last element in the map
size() 每 Returns the number of elements in the map
max_size() 每 Returns the maximum number of elements that the map can hold
empty() 每 Returns whether the map is empty
pair insert(keyvalue, mapvalue) 每 Adds a new element to the map
erase(iterator position) 每 Removes the element at the position pointed by the iterator
erase(const g)每 Removes the key value ＆g＊ from the map
clear() 每 Removes all the elements from the map

*/