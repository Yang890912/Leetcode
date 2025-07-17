class TimeMap {
public:
    unordered_map<string, map<int, string>> key2Time2Str;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key2Time2Str[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (key2Time2Str.find(key) == key2Time2Str.end()) return "";
        
        auto it = key2Time2Str[key].upper_bound(timestamp);
        
        if (it == key2Time2Str[key].begin()) return "";

        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */