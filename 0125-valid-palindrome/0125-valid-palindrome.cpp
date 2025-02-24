class Solution {
public:
    bool isPalindrome(string s) {
       int start=0;
       int end=s.size()-1;
       while(start<=end){

            //skip the start index if its not alphanumeric
           if(!isalnum(s[start])){start++; continue;}
           //skip the end if its not alphanumeric
           if(!isalnum(s[end])){end--;continue;}

           //both start and end are not alphanumeric
           if(tolower(s[start])!=tolower(s[end]))return false;
           else{
               start++;
               end--;
           }
       }
       return true;
    }
};