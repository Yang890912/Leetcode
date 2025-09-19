class Spreadsheet {
public:
    vector<vector<int>> sheet;

    Spreadsheet(int rows) {
        for (int i = 0; i < rows + 1; i++) {
            sheet.push_back(vector<int>(26, 0));
        }
    }
    
    void setCell(string cell, int value) {
        int row = stoi(cell.substr(1, cell.size() - 1));
        int column = cell[0] - 'A';
        if (row > sheet.size()) return;
        sheet[row][column] = value;
    }
    
    void resetCell(string cell) {
        int row = stoi(cell.substr(1, cell.size() - 1));
        int column = cell[0] - 'A';
        if (row > sheet.size()) return;
        if (cell[0] > 'Z' || cell[0] < 'A') return;
        sheet[row][column] = 0;
    }
    
    int getValue(string formula) {
        int res = 0;
        int i = 0;
        while (i < formula.size()) {
            if (formula[i] >= 'A' && formula[i] <= 'Z') {
                int column = formula[i++] - 'A';
                int row = 0;
                while (i < formula.size() && formula[i] >= '0' && formula[i] <= '9') {
                    row *= 10;
                    row += formula[i] - '0';
                    i++;
                }
                if (row > sheet.size()) res += 0;
                else res += sheet[row][column];
            }
            else if (formula[i] >= '0' && formula[i] <= '9') {
                int val = 0;
                while (i < formula.size() && formula[i] >= '0' && formula[i] <= '9') {
                    val *= 10;
                    val += formula[i] - '0';
                    i++;
                }
                res += val;
            }
            else {
                i++;
            }
        }

        return res;
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */