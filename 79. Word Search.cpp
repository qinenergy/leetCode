class Solution2 {
public:
    bool exist(vector<vector<char>>& board, string word) {
    	int len = word.size();
    	int rows = board.size(); 
    	if(rows == 0 || len == 0)	return false;
    	int cols = board[0].size();
    	if(cols == 0)	return false;
    	vector<vector<bool>> visited(rows, vector<bool>(cols, false));
    	for(int i = 0; i < rows; ++i){
    		for(int j = 0; j < cols; ++j){
    			if(word[0] == board[i][j] &&
    				exist(board, visited, word, i, j, rows, cols, 0, len))
    				return true;
    		}
    	}
    	return false;
    }
    bool exist(vector<vector<char>>& board, vector<vector<bool>>& visited, string& word, int r, int c, int rows, int cols, int s, int len){
    	if(r < 0 || r >= rows || c < 0 || c >= cols)	return false;
    	auto& ch = word[s];
    	if(board[r][c] != ch || visited[r][c])	return false;
    	if(s == len - 1)	return true;
    	visited[r][c] = true;
    	if(r >= 1 && 
    		exist(board, visited, word, r - 1, c, rows, cols, s + 1, len))
    		return true;
    	if(r < rows - 1 &&
    		exist(board, visited, word, r + 1, c, rows, cols, s + 1, len))
    		return true;
    	if(c >= 1 &&
    		exist(board, visited, word, r, c - 1, rows, cols, s + 1, len))
    		return true;
    	if(c < cols - 1	&&
    		exist(board, visited, word, r, c + 1, rows, cols, s + 1, len))
    		return true;
    	visited[r][c] = false;
    	return false;
    }
};