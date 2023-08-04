/*
 * Leetcode 139: Word Break https://leetcode.com/problems/word-break/

 * Given a string s and a dictionary of strings wordDict, return true if s can be
   segmented into a space-separated sequence of one or more dictionary words.

 * Note that the same word in the dictionary may be reused multiple times in the
   segmentation.
 
 * Constraints:
 *  1 <= s.length <= 300
 *  1 <= wordDict.length <= 1000
 *  1 <= wordDict[i].length <= 20
 *  s and wordDict[i] consist of only lowercase English letters.
 *  All the strings of wordDict are unique.
 */

#include <iostream>
#include <vector>
#include <iomanip> // This is used by test(), not the main algorithm

using std::cout;
using std::endl;
using std::vector;
using std::string;

bool wordBreakHelper(string s, string* wordDictArr, int *cache, int pos,
                     int numWords){
  if (s.length() == 0) // Base case: reached end of s
    return true;

  for (int i = 0; i < numWords; i++){ // Check all words for a match
    // Performance optimation: Avoid repeated calculation of cache location.
    int *cacheLocation = cache + pos * numWords + i;
    if (*cacheLocation != -1) // See if calculation is cached.
      return *(cacheLocation); // Return cached calculation.

    // Calculation is not cached, so we need to run it and cache the result.
    if (wordDictArr[i] == s.substr(0, wordDictArr[i].length())){ // Match found
      // Depth-first search branching off of this match. 
      // Memory optimization: omit the part just processed; passes less data.
      if (wordBreakHelper(s.substr(wordDictArr[i].length(), string::npos),
                          wordDictArr, cache, pos + wordDictArr[i].length(),
                          numWords)){
        *cacheLocation = 1; // Cache this result
        return true; // If recursive call returned true, return true
      }
      else
        *cacheLocation = 0; // Cache this result
    }
  }
  return false; // We can only get here if no branch returned true
}

bool wordBreak(string s, vector<string>& wordDict){
  int pos = 0; // Position in the string; needed for cache access
  int numWords = wordDict.size();

  // Performance optimizations: Convert wordDict to array for faster accesses
  string wordDictArr[wordDict.size()];
  for (int i = 0; i < numWords; i++){
    wordDictArr[i] = wordDict[i];
  }

  // Row = position of calculation, col = which word is being tested
  int *cache = new int[s.length() * numWords];
  std::fill(cache, cache + s.length() * numWords, -1); // Initialize cache
  
  bool output = wordBreakHelper(s, wordDictArr, cache, pos, numWords);
  delete [] cache; // Free the dynamically allocated cache
  return output;
}

void test(string s, vector<string> &wordDict, bool exp){
  cout << std::boolalpha << std::setw(151) << s << std::setw(10);
  
  bool result = wordBreak(s, wordDict);
  if (result == exp)
    cout << "OK";
  else
    cout << "Error";

  string status = "Expected ";
  if (exp)
    status += "true";
  else
    status += "false";
  status += ", got ";
  if (wordBreak(s, wordDict))
    status += "true";
  else
    status += "false";

  cout << std::setw(30) << status << endl;
}

int main(){
  // Test cases
  vector<string> tester;
  cout << endl << std::setw(151) << "Test case" << std::setw(10) << "Status";
  cout << std::setw(30) << "Details" << endl;
  cout << std::string(191, '-') << endl;

  tester = {"leet", "code"};
  test("leetcode", tester, true);

  tester = {"apple", "pen"};
  test("applepenapple", tester, true);

  tester = {"cats", "dog", "sand", "and", "cat"};
  test("catsandog", tester, false);

  tester = {"b"};
  test("a", tester, false);

  tester = {"car", "ca", "rs"};
  test("cars", tester, true);

  tester = {"a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa",
            "aaaaaaaaa", "aaaaaaaaaa"};
  test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
       "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
       "aaaaaaaaaab", tester, false);

  tester = {"aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa",
            "aaaaaaaaa", "aaaaaaaaaa","ba"};
  test("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
       "aaaaabaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
       "aaaaaaaaaaa", tester, false);

  tester = {"cbc","bcda","adb","ddca","bad","bbb","dad","dac","ba","aa","bd",
            "abab","bb","dbda","cb","caccc","d","dd","aadb","cc","b","bcc",
            "bcd","cd","cbca","bbd","ddd","dabb","ab","acd","a","bbcc","cdcbd",
            "cada","dbca","ac","abacd","cba","cdb","dbac","aada","cdcda","cdc",
            "dbc","dbcb","bdb","ddbdd","cadaa","ddbc","babb"};
  test ("bccdbacdbdacddabbaaaadababadad", tester, true);

  cout << endl;
  return 0;
}
