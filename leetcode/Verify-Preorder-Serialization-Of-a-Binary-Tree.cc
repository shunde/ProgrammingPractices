class Solution {
public:
    bool isValidSerialization(string preorder) {
        int iNotNullCount = 0;
        int iNullCount = 0;
        string remainStr = preorder;

        while (!remainStr.empty() && iNullCount <= iNotNullCount) {
            size_t commaPos = remainStr.find_first_of(',', 0);
            string token = remainStr.substr(0, commaPos);

            if (token.compare("#") == 0) iNullCount+=1;
            else iNotNullCount+=1;

            if (commaPos == string::npos) remainStr.clear();
            else remainStr = remainStr.substr(commaPos+1);
        }
        if (iNullCount == iNotNullCount+1 && remainStr.empty()) return true;
        return false;        
    }
};