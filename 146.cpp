class LRUCache {
public:
    int Capacity;
    unordered_map<int, int> forV;
    unordered_map<int, int> forC;
    LRUCache(int capacity) {
        Capacity = capacity;
    }
    
    int get(int key) {
        if(forV.count(key)){
            for(auto it : forC){
                if(it.second < forC[key]) it.second++;
            }
            forC[key] = 0;
            return forV[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(forV.count(key)){
            forV[key] = value;
            for(auto it : forC){
                if(it.second < forC[key]) it.second++;
            }
            forC[key] = 0;
        }

        else{
            if(forV.size() < Capacity){
                for(auto it : forC){
                    it.second++;
                }
                forV[key] = value;
                forC[key] = 0;
            }

            else{
                for(auto it : forC){
                    it.second++;
                    if(it.second == Capacity-1){
                        forC.erase(it.first);
                        forV.erase(it.first);
                    }
                }
                forV[key] = value;
                forC[key] = 0;
            }
        }
        

    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */