#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/***

 n shops in a row selling an n[i] type vegetable.
 2 Baskets. > Each basket can have only 1 type of vegetable.

Return the max types of vegetable you can collect

Stop : 
1. Shops have ended
2. Baskets cant accomodate another type

Input: [0,1,2,2]
Output: 3

Input: [1,2,3,2,2,5,2]
Output: 4

Input: [3,3,3,1,2,1,1,2,3,3,4]
Output: 5

*/

// To execute C++, please define "int main()"

int getMaxVegetables(vector<int> shops) {
  int t1 = -1, t2 = -1;
  int count_t1 = 0, count_t2 = 0;
  int curr_type = 0;
  int max_veggi = -1, curr_veggi = 0, n = shops.size();
  
  int i = 0, j = 0;
  while (i < n) {
   /* if (t1 == -1 || t1 == shops[i]) {
      curr_type = t1==-1 ? curr_type+1 : curr_type;
      t1 = shops[i];
      count_t1++;
      curr_veggi++;
    } else if (t2 == -1 || t2 == shops[i]) {
      curr_type = t2==-1 ? curr_type+1 : curr_type;
      t2 = shops[i];
      count_t2++;
      curr_veggi++;
    }*/
    // 3,3,3,1,2,1,1,2,3,3,4
    /* 
      3 -> t1: (3, 1). 1, 1
      3 -> t1: (3, 1)
      
      
      t1 : 3, 0
      
      t2 : 1, 1
      
      curr : 1
      type: 2
    
    */
    
    //cout << t1 << " " << count_t1 << " " << t2 << " " << count_t2 << " " << curr_veggi << " " << curr_type << " " << i << " " << j << endl;
    if (shops[i] == t1 || shops[i] == t2) {
      if (shops[i] == t1) {
        count_t1++; 
      } else {
        count_t2++;
      }
      curr_veggi++;
      i++;
    } else {
      if (curr_type < 2) {
        if (t1 == -1) {
          t1 = shops[i];
          count_t1 = 1;
        } else {
          t2 = shops[i];
          count_t2 = 1;
        }
        curr_type++;
        curr_veggi++;
        i++;
      } else {
        if (shops[j] == t1) {
          count_t1--;
        } else {
          count_t2--;
        }
        curr_veggi--;
        
        if (count_t1 == 0) {
          t1 = -1;
          count_t1 = 0;
          curr_type--;
        } else if (count_t2 == 0) {
          t2 = -1;
          count_t2 = 0;
          curr_type--;         
        }
        
        j++;
      }   
    }
    
    if (curr_type <= 2) {
      max_veggi = max(max_veggi, curr_veggi);
    }  
  }
  
  return max_veggi;
}  
int main() {

  
  vector<int> arr = {3,3,3,1,2,1,1,2,3,3,4};
  cout << getMaxVegetables(arr) << endl;
  
  vector<int> arr1 = {1,2,3,2,2,5,2};
  cout << getMaxVegetables(arr1) << endl;
  
  return 0;
}





//----------------------------------------------------------------------------------

#include <iostream>
#include <bits/stdc++.h>

/*

Write a function that takes a string and a dictionary as input and looks up any bracketed string ("{}",
"[]", "()") and replaces it with its value in the dictionary.

For example, func("Two mathematicians walk into a {foo}.", {"foo": "bar"}) = "Two mathematicians walk into a bar."

*/

using namespace std;



bool isOpen(char ch) {
  return ch == '(' || ch == '{' || ch == '[';  
}
bool isClose(char ch) {
  return ch == ')' || ch == '}' || ch == ']';  
}
bool isEqual(char open, char close) {
  return (open == '(' && close == ')') || (open == '{' && close == '}') || (open == '[' && close == ']');  
}  
string completeString(string text, map<string, string> dict) {
  int len = text.length();
  char openBraces;
  bool isOpenExist = false;
  string str, key;
  
  int i = 0;
  while (i < len) {
    if (isOpen(text[i])) {
      if (isOpenExist) {
        return "-1";  
      }
      
      openBraces = text[i];
      isOpenExist = true;
    } else if (isClose(text[i])) {
      if (!isOpenExist || !isEqual(openBraces, text[i]) || dict.find(key) == dict.end()) {
        return "-1";  
      }
      
      str += dict[key];
      key = "";
      isOpenExist = false;
    } else {
      if (isOpenExist) {
         key += text[i]; 
      } else {
        str += text[i];  
      }  
    }
    
    i++;
  }
  
  if (isOpenExist) {
    return "-1";  
  }  
  
  return str;
}  
int main() {
  
  map<string, string> dict;
  dict["foo"] = "bar";
  dict["bar"] = "space bar";

  // foo -> bar -> space bar -> null 
    
  
  return 0;
}
