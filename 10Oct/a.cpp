// C++ function for illustration 
// map::lower_bound() function 
#include <bits/stdc++.h> 
using namespace std; 
  
// int main() 
// { 
  
//     // initialize container 
//     map<int, int> mp; 
  
//     // insert elements in random order 
//     mp.insert({ 2, 30 }); 
//     mp.insert({ 1, 10 }); 
//     mp.insert({ 5, 50 }); 
//     mp.insert({ 4, 40 }); 
//     for (auto it = mp.begin(); it != mp.end(); it++) { 
//         cout << (*it).first << " " << (*it).second << endl; 
//     } 
  
//     // when 2 is present 
//     auto it = mp.upper_bound(0); 
//     cout << "The lower bound of key 0 is "; 
//     cout << (*it).first << " " << (*it).second<<endl ;

//     it = mp.upper_bound(2); 
//     cout << "The lower bound of key 2 is "; 
//     cout << (*it).first << " " << (*it).second << endl; 
  
//     // when 3 is not present 
//     // points to next greater after 3 
//     it = mp.upper_bound(3); 
//     cout << "The lower bound of key 3 is "; 
//     cout << (*it).first << " " << (*it).second; 
  
//     // when 6 exceeds 
//     it = mp.upper_bound(6); 
//     cout << "\nThe lower bound of key 6 is "; 
//     cout << (*it).first << " " << (*it).second<<endl<<endl;; 


//     // when 2 is present 
//     it = mp.lower_bound(0); 
//     cout << "The lower bound of key 0 is "; 
//     cout << (*it).first << " " << (*it).second<<endl ;

//     it = mp.lower_bound(2); 
//     cout << "The lower bound of key 2 is "; 
//     cout << (*it).first << " " << (*it).second << endl; 
  
//     // when 3 is not present 
//     // points to next greater after 3 
//     it = mp.lower_bound(3); 
//     cout << "The lower bound of key 3 is "; 
//     cout << (*it).first << " " << (*it).second; 
  
//     // when 6 exceeds 
//     it = mp.lower_bound(6); 
//     cout << "\nThe lower bound of key 6 is "; 
//     cout << (*it).first << " " << (*it).second<<endl; 




//     return 0; 
// }

int main() 
{ 
  
    // initialize container 
    multiset<int> mp; 
  
    // insert elements in random order 
    mp.insert(2); 
    mp.insert(1); 
    mp.insert(5); 
    mp.insert(4); 
    for (auto it = mp.begin(); it != mp.end(); it++) { 
        cout << (*it) << " " << (*it) << endl; 
    } 
  
    // when 2 is present 
    auto it = mp.upper_bound(0); 
    cout << "The lower bound of key 0 is "; 
    cout << (*it) << " " << (*it) << endl; 

    it = mp.upper_bound(2); 
    cout << "The lower bound of key 2 is "; 
    cout << (*it) << " " << (*it) << endl; 
  
    // when 3 is not present 
    // points to next greater after 3 
    it = mp.upper_bound(3); 
    cout << "The lower bound of key 3 is "; 
    cout << (*it) << " " << (*it) << endl; 
  
    // when 6 exceeds 
    it = mp.upper_bound(6); 
    cout << "\nThe lower bound of key 6 is "; 
    cout << (*it) << " " << (*it) << endl<<endl<<endl;; 


    // when 2 is present 
    it = mp.lower_bound(0); 
    cout << "The lower bound of key 0 is "; 
    cout << (*it) << " " << (*it) << endl; 

    it = mp.lower_bound(2); 
    cout << "The lower bound of key 2 is "; 
    cout << (*it) << " " << (*it) << endl; 
  
    // when 3 is not present 
    // points to next greater after 3 
    it = mp.lower_bound(3); 
    cout << "The lower bound of key 3 is "; 
    cout << (*it) << " " << (*it) << endl; 
  
 // points to next greater after 3 
    it = mp.lower_bound(4); 
    cout << "The lower bound of key 4 is "; 
    cout << (*it) << " " << (*it) << endl; 

 // points to next greater after 3 
    it = mp.lower_bound(5); 
    cout << "The lower bound of key 5 is "; 
    cout << (*it) << " " << (*it) << endl; 

    // when 6 exceeds 
    it = mp.lower_bound(6); 
    if(it != mp.end())
    {
    cout << "\nThe lower bound of key 6 is "; 
    cout << (*it) << " " << (*it) << endl; 
    }





    return 0; 
}