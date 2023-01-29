class LRUCache
{
    public:

        class node
        {
            public:
                int key;
            int val;
            node * prev;
            node * next;
            node(int _key, int _val)
            {
                key = _key;
                val = _val;
            }
        };

    int cap;
    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    unordered_map<int, node*> mp;

    LRUCache(int capacity)
    {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void add_node(node *newnode)
    {
        node *temp = head->next;
        head->next = newnode;
        newnode->prev = head;
        temp->prev = newnode;
        newnode->next = temp;
    }

    void delete_node(node *delnode)
    {
        node *delprev = delnode->prev;
        node *delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_)
    {

        if (mp.find(key_) != mp.end())
        {
            node *resnode = mp[key_];
            mp.erase(key_);
            int res = resnode->val;
            delete_node(resnode);
            add_node(resnode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int val_)
    {

        if (mp.find(key_) != mp.end())
        {
            node *existingnode = mp[key_];
            delete_node(existingnode);
            mp.erase(key_);
        }
        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            delete_node(tail->prev);
        }
        add_node(new node(key_, val_));
        mp[key_] = head->next;
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */