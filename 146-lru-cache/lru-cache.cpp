class LRUCache {
private:
    class Node{
    public:
        int key, value;
        Node* prev;
        Node* next;

        Node(int k, int v){
            key = k;
            value = v;
            prev = next = NULL;
        }

    };
    int capacity;
        unordered_map<int, Node*> mp;
        Node* head;
        Node* tail;

        void addNode(Node* node){
            Node* temp = head->next;
            node->next = temp;
            node->prev = head;
            head->next = node;
            temp->prev = node;
        }

        void deleteNode(Node* node){
            Node* nextNode = node->next;
            Node* prevNode = node->prev;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;
        }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1, -1);

        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        int val = node -> value;

        deleteNode(node);
        addNode(node);
        return val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            Node* existing = mp[key];
            deleteNode(existing);
            mp.erase(key);
        }

        if(mp.size() == capacity){
            Node* lru = tail -> prev;
            deleteNode(lru);
            mp.erase(lru->key);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        mp[key] = newNode;
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */