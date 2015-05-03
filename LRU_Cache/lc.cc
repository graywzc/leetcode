class LRUCache{
public:
    LRUCache(int capacity)
    : capacity(capacity){
    }
    
    int get(int key) {
        if(ht.find(key) == ht.end())    
            return -1;
        else
        {
            int res = ht[key]->second;
            l.erase(ht[key]);
            l.insert(l.begin(), pair<int,int>(key,res));
            ht[key] = l.begin();
            return res;
        }
    }
    
    void set(int key, int value) {
        if(ht.find(key) == ht.end()) 
        {
            if(ht.size() == capacity)    
            {
                ht.erase(l.back().first);  
                l.pop_back();
                l.insert(l.begin(), pair<int,int>(key,value));
                ht[key] = l.begin();
                return;
            }
            else
            {
                l.insert(l.begin(), pair<int,int>(key,value));
                ht[key] = l.begin();
                return;
            }
        }
        else
        {
            l.erase(ht[key]); 
            l.insert(l.begin(), pair<int,int>(key,value));
            ht[key] = l.begin();
            return;
        }
    }
private:
    unordered_map<int, list<pair<int,int>>::iterator> ht;
    list<pair<int,int>> l;
    int capacity;
};
