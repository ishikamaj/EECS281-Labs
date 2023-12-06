/*
 * replace_words.cpp
 * Univeristy of Michigan, Ann Arbor
 * EECS 281 Lab 7 Written.
 * SUBMIT ONLY THIS FILE TO GRADESCOPE.
 */

// Common #includes for convience.
// No need to use them.
// Remove any of them if you want.
#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

#include "replace_words.h"

using namespace std;

  int hashfunc(vector<string>& hashtable, string key) {
    int sum = 0;
    if (key.empty()) {
      return 0;
    }
    else {
      for (int i = 0; i < key.size(); i++) {
        sum += key[i];
      }
      return sum % hashtable.size();
    }
  }
  
  void insert(vector<string>& hashtable, string key) {
    int index = hashfunc(hashtable, key);
    while (hashtable[index] != "") {
      index = (index + 1) % hashtable.size();
    }
    hashtable[index] = key;
  }
  
  int find(vector<string>& hashtable, string str) {
    int index = hashfunc(hashtable, str);
    while (hashtable[index] != str) {
      if (hashtable[index] == "") {
        return -1;
      }
      index = (index + 1) % hashtable.size();
    }
    return index;
  }

  vector<string> replace_words(const vector<string>& prefixes, const vector<string>& sentence) {
    vector<string> hashtable;
    vector<string> output = sentence;
    hashtable.resize(3571, "");
    for (string it : prefixes) {
      insert(hashtable, it);
    }
    for (int j = 0; j < output.size(); ++j) {
    for (int i = 0; i < sentence[j].length(); ++i) {
      string temp = sentence[j].substr(0, i + 1);
      int findIndex = find(hashtable, temp);
      if (findIndex >= 0) {
        output[j] = hashtable[findIndex];
        break;
      }
    }
  }
  return output;
}

