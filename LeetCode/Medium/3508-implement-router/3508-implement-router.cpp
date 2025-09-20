class Router {
public:
    int maxLimit;
    queue<long long> keys;
    unordered_map<long long, vector<int>> packets;
    unordered_map<int, vector<int>> desToTimestamps;

    long long genKey(int source, int destination, int timestamp) {
        return ((long long)source << 40) | ((long long)destination << 20) | (long long)timestamp;
    }

    Router(int memoryLimit) {
        maxLimit = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        long long key = genKey(source, destination, timestamp);

        if (packets.count(key)) return false;

        vector<int> packet = {source, destination, timestamp};
        keys.push(key);
        packets[key] = packet;
        desToTimestamps[destination].push_back(timestamp);

        if (keys.size() > maxLimit) forwardPacket();

        return true;
    }
    
    vector<int> forwardPacket() {
        if (packets.empty()) return {};

        long long key = keys.front();
        keys.pop();

        vector<int> packet = packets[key];
        packets.erase(key);

        int dst = packet[1];
        desToTimestamps[dst].erase(desToTimestamps[dst].begin());

        return packet;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        const vector<int>& timestamps = desToTimestamps[destination];

        if (timestamps.empty()) return 0;

        int left = (int)(lower_bound(timestamps.begin(), timestamps.end(), startTime) - timestamps.begin());
        int right = (int)(upper_bound(timestamps.begin(), timestamps.end(), endTime) - timestamps.begin());
        
        return right - left;
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */