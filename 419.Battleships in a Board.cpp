class Solution2 {
public:
    int countBattleships(vector<vector<char>>& board) {
        if (board.size() == 0 || board[0].size() == 0) return 0;
		int count = 0;
		bool flag1, flag2;
		for (int i = 0; i < board.size(); ++i) {
			for (int j = 0; j < board[i].size(); ++j) {
				flag1 = false, flag2 = false;
				if (board[i][j] != 'X') continue;
				if (i == 0) flag1 = true;
				else flag1 = (board[i - 1][j] == '.');
				if (j == 0) flag2 = true;
				else flag2 = (board[i][j - 1] == '.');
				(flag1 && flag2) ? ++count : count = count;
			}
		}
		return count;
    }
};