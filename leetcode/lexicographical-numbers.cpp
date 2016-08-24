class Solution {
private:
	void lexicalOrderAux(vector<int>& list, int n, int max) {
		n *= 10;
		if (n > max) return;
		if (n != 0) {
		    list.push_back(n);
			lexicalOrderAux(list, n, max);
		}
		for (int i = 1; i < 10 && n + i <= max; i++) {
			list.push_back(n+i);
			lexicalOrderAux(list, n+i, max);
		}
	}
public:
    vector<int> lexicalOrder(int n) {
    	vector<int> list;
    	lexicalOrderAux(list, 0, n); 
    	return list;   	      
    }
};