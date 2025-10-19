class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        string res = s;
        unordered_set<string> generated;
        queue<string> q;
        generated.insert(s);
        q.push(s);

        while (!q.empty()) {
            string _s = q.front();
            q.pop();

            if (_s < res) res = _s;

            string added = add(_s, a);
            if (!generated.count(added)) {
                generated.insert(added);
                q.push(added);
            }

            string rotated = rotate(_s, b);
            if (!generated.count(rotated)) {
                generated.insert(rotated);
                q.push(rotated);
            }
        }

        return res;
    }

    string add(string s, int a) {
        string output = s;
        for (int i = 1; i < s.size(); i += 2) {
            output[i] = ((output[i] - '0' + a) % 10) + '0';
        }
        return output;
    }

    string rotate(string s, int b) {
        string output;
        output = s.substr(s.size() - b, b) + s.substr(0, s.size() - b);
        return output;
    }
};