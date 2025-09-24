class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res = "";
        if ((numerator < 0) ^ (denominator < 0)) res += "-";

        long long _numer = llabs((long long) numerator); 
        long long _denom = llabs((long long) denominator);
        res += to_string(_numer / _denom);
        
        if (_numer % _denom == 0) return res;

        res += ".";
        unordered_map<long long, int> um;
        while (_numer % _denom != 0) {
            if (um.count(_numer % _denom)) {
                res.insert(um[_numer % _denom], "(");
                res += ")";
                break;
            }

            um[_numer % _denom] = res.size();
            _numer %= _denom;
            _numer *= 10;
            res += to_string(_numer / _denom);
        }

        return res;
    }
};