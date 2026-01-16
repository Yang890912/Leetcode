class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        double halfArea = areaAboveY(squares, -1) / 2.0;

        double lower = squares[0][1];
        double upper = squares[0][1] + squares[0][2];
        for(int i = 1; i < squares.size(); i++) {
            if (squares[i][1] < lower) lower = squares[i][1];
            if (squares[i][1] + squares[i][2] > upper) upper = squares[i][1] + squares[i][2];
        }

        while (upper - lower > 1e-5) {
            double mid = (upper + lower) / 2;
            double area = areaAboveY(squares, mid);

            if (area > halfArea) lower = mid;
            else upper = mid;
        }

        return lower;
    }

    double areaAboveY(vector<vector<int>>& squares, const double y) {
        double area = 0.0;
        for (int i = 0; i < squares.size(); i++) {
            double bottom = squares[i][1];
            double length = squares[i][2];

            if (bottom + length < y) continue;
            
            if (bottom >= y) area += length * length;
            else area += length * (bottom + length - y);
        }

        return area;
    }

};