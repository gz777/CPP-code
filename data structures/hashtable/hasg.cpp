// hashtable hashing simple demo 4/26/20 gz
#include <iostream>
#include <string>

struct MapNode {
  std::string key, value;
  MapNode(std::string k="",std::string v=""):key(k),value(v) { }
};

//hash function
int myHashFunc(std::string s, int size) {
    int ascii = 0;
    for (unsigned int i=0;i<s.length();i++)
    {
        ascii += (int)s[i];
        //std::cout << ascii << std::endl;
    }
    return ascii % size; 
}

int main()
{
    const int N = 3;//size of map
    const int HS = N * 2;//size of hash table
    
    MapNode * mapList = new MapNode[N];
    std::string hashTable[HS]={};//initialize all elements to "na".
    
    for(MapNode * ptr=mapList;ptr<mapList+N;ptr++) {
        std::string k, v;
        std::cin>>k;
        std::cin.get();
        getline(std::cin,v);
        *ptr = MapNode(k,v);
    }
  
    for(int i=0;i<N;i++) {
        int index = myHashFunc(mapList[i].key,HS);//hashing
        
        if(hashTable[index] == "" ){//check collision
            std::cout << "Great: " <<  index << std::endl;
            hashTable[index] = mapList[i].value; //insert value in hash table in the index-th bucket
        } else {
            std::cout << "Bad news: " << index << std::endl;
        }  
        
    }
    

}


map/dictionary
key            value
("John Smith", {"John address", 222-2223, 4.0} )
("Lisa Smith", {"Lisa address", 222-2223, 4.0} )
("Sandra Dee", {"address", 222-2223, 4.0} )


maplist = {("John Smith", {"John address", 222-2223, 4.0} ), 
        ("Lisa Smith", {"Lisa address", 222-2223, 4.0} ),
        ("Sandra Dee", {"address", 222-2223, 4.0} );
O(n*m)//m: max length of key

=======================================================

//create a hash table
1) hashFunc("John Smith);
int index = hashFunc("John Smith);
index => 0

Lisa Smith
index => 1
Sandra Dee
index => 2

buckets size 

2) 
HashMapArray[0] = {"address", 222-2223, 4.0} 
HashMapArray[1] = {"Lisa address", 222-2223, 4.0}
HashMapArray[2] = {"address", 222-2223, 4.0}


//retrieve data
"John Smith"
1) int index = hashFunc("John Smith); // O(1)
2) HashMapArray[index]; // O(1)
O(1) + O(1) = O(1)


Wishing you all the best in your future endeavors