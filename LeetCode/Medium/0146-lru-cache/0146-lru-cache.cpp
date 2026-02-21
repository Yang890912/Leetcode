class LRUCache {
public:
    // double linked list
    class Node {
        public:
            int key;
            int val;
            Node* next;
            Node* prev;

            Node(int key, int val) {
                this->key = key;
                this->val = val;
            }
    };

    void add(Node* node) {
        Node* temp = head->next;

        node->next = temp;
        node->prev = head;
        
        head->next = node;
        temp->prev = node;
    }

    void remove(Node* node) {
        Node* nextt = node->next;
        Node* prevv = node->prev;

        nextt->prev = prevv;
        prevv->next = nextt;
    }

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int capa;
    int size;
    vector<Node*> table{1001, nullptr};

    LRUCache(int capacity) {
        size = 0;
        capa = capacity;
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!table[key]) return -1;

        remove(table[key]);
        add(table[key]);
        
        return table[key]->val;
    }
    
    void put(int key, int value) {
        if (table[key]) {
           remove(table[key]);
           delete(table[key]);
           table[key] = nullptr;
           size--;
        }

        if (size >= capa) {
            int dk = tail->prev->key;
            remove(table[dk]);
            delete(table[dk]);
            table[dk] = nullptr;
            size--;
        }

        table[key] = new Node(key, value);
        add(table[key]);
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */