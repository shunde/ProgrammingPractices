// 踩坑了：& 的优先级低于 ==
// 在不知道有限级的情况下使用括号
class Solution {
private:
	
	const int OneByteMask = 0x80;
	const int TwoByteMask = 0xE0;
	const int ThreeByteMask = 0xF0;
	const int FourByteMask = 0xF8;
	const int FollowedByteMask = 0xC0;
 	
 	const int OneByteSym = 0x00;
 	const int TwoByteSym = 0xC0;
 	const int ThreeByteSym = 0xE0;
 	const int FourByteSym = 0xF0;
 	const int FollowedByteSym = 0x80; 	

 	bool isFollowedByte(int value) {
 		return (value & FollowedByteMask) == FollowedByteSym;
 	}

public:
    bool validUtf8(vector<int>& data) {
    	int i = 0;
    	while (i < data.size()) {
    		if ((data[i] & OneByteMask) == OneByteSym) {    			
    			i++;
    		} else if ((data[i] & TwoByteMask) == TwoByteSym) {
    			
    			if (i+1 < data.size() && isFollowedByte(data[i+1]))
    				i += 2;
    			else 
    				break;

    		} else if ((data[i] & ThreeByteMask) == ThreeByteSym) {
    			
    			if (i+2 < data.size() && isFollowedByte(data[i+1]) && isFollowedByte(data[i+2]))
    				i += 3;
    			else 
    				break;

    		} else if ((data[i] & FourByteMask) == FourByteSym) {
    			
    			if (i+3 < data.size() && isFollowedByte(data[i+1]) && isFollowedByte(data[i+2]) && isFollowedByte(data[i+3]))
    				i += 4;
    			else 
    				break;

    		} else {
    			break;
    		}
    	}

    

    	if (i < data.size()) return false;
    	return true; 
    }
};

