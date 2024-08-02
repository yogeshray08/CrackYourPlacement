class LRUCache
{
public:
    class node
    {
    public:
        int key;
        int data;
        node *next;
        node *prev;

        node(int _key, int _data)
        {
            key = _key;
            data = _data;
            next = nullptr;
            prev = nullptr;
        }
    };

    node *head;
    node *tail;
    int cap;
    unordered_map<int, node *> m;

    LRUCache(int capacity)
    {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node *newNode)
    {
        node *temp = head->next;

        head->next = newNode;
        newNode->prev = head;

        newNode->next = temp;
        temp->prev = newNode;
    }

    void deletenode(node *delNode)
    {
        node *delPrev = delNode->prev;
        node *delNext = delNode->next;

        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    int get(int key)
    {
        if (m.find(key) != m.end())
        {
            node *resNode = m[key];
            int res = resNode->data;
            m.erase(key);
            deletenode(resNode);
            addnode(resNode);
            m[key] = head->next;
            return res;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
        if (m.find(key) != m.end())
        {
            node *existNode = m[key];
            m.erase(key);
            deletenode(existNode);
        }
        if (m.size() == cap)
        {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }
        addnode(new node(key, value));
        m[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
