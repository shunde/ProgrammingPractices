/**
 * corner case: [1.1 1] [1 1.0] [1.0.1 1.0]
 *
 */

class Solution {
public:
    int compareVersion(string version1, string version2) {        

        int major1 = 0, major2 = 0;
        size_t dotPos1 = string::npos, dotPos2 = string::npos;

        if (!version1.empty()) {
            dotPos1 = version1.find_first_of('.', 0);
            major1 = stoi(version1.substr(0, dotPos1));
        }

        if (!version2.empty()) {
            dotPos2 = version2.find_first_of('.', 0);        
            major2 = stoi(version2.substr(0, dotPos2));
        } 
        

        if (major1 < major2) return -1;
        else if (major1 > major2) return 1;
        else {            
            if (dotPos1 == string::npos && dotPos2 == string::npos) return 0;

            string str1, str2;
            if (dotPos1 != string::npos) str1 = version1.substr(dotPos1+1);
            if (dotPos2 != string::npos) str2 = version2.substr(dotPos2+1);
            return compareVersion(str1, str2);
        }
    }
};